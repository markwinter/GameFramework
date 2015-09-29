#include "stdafx.h"
#include "GameLoop.h"
#include "ExampleState.h"

GameLoop::GameLoop() {
  // Set current state to an example state
  std::unique_ptr<GameState> example_state = std::make_unique<ExampleState>();
  state_stack_.push(std::move(example_state));
}

GameLoop::~GameLoop() {

}

void GameLoop::Loop(sf::RenderWindow& main_window) {  
  // Font and Text for displaying FPS
  sf::Font font_arial;
  sf::Text text_fps;
  font_arial.loadFromFile("arial.ttf");
  text_fps.setFont(font_arial);
  text_fps.setCharacterSize(24);

  sf::Clock game_clock_;
  int32_t frame_time = 0;
  int fps = 0;

  while (main_window.isOpen()) { 
    frame_time = game_clock_.restart().asMilliseconds();

    // Calculate fps
    fps = 1 / ((double) frame_time / 1000);
    text_fps.setString(std::to_string(fps));

    // Poll the window events
    sf::Event event;
    while (main_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        main_window.close();
    }

    main_window.clear(sf::Color(0, 0, 0));

    state_stack_.top()->HandleInput();
    state_stack_.top()->Update(frame_time);
    state_stack_.top()->Draw(main_window, frame_time);

    main_window.draw(text_fps);

    main_window.display();
  }

  // Empty the state stack which will also delete the unique ptrs
  while (!state_stack_.empty())
    state_stack_.pop();
}