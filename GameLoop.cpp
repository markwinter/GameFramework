#include "stdafx.h"
#include "GameLoop.h"
#include "ExampleState.h"

GameLoop::GameLoop() {
  // Create a window
  //int w = sf::VideoMode().getDesktopMode().width;
  //int h = sf::VideoMode().getDesktopMode().height;
  int w = 800;
  int h = 600;
  main_window_.create(sf::VideoMode(w, h), "My Game");
  main_window_.setVerticalSyncEnabled(true);

  // Set current state to Example one
  state_ = new ExampleState();
}

GameLoop::~GameLoop() {

}

void GameLoop::Loop() {  
  while (main_window_.isOpen()) { 
    int32_t frame_time = game_clock_.restart().asMilliseconds();

    // Poll the window events
    sf::Event event;
    while (main_window_.pollEvent(event));

    // Clear the window
    main_window_.clear(sf::Color(0, 0, 0));

    state_->HandleInput();
    state_->Update(frame_time);
    state_->Draw(main_window_, frame_time);

    main_window_.display();
  }
}