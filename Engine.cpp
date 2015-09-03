#include "stdafx.h"
#include "Engine.h"

Engine::Engine() {
  // Create a window
  //int w = sf::VideoMode().getDesktopMode().width;
  //int h = sf::VideoMode().getDesktopMode().height;
  int w = 800;
  int h = 600;
  main_window_.create(sf::VideoMode(w, h), "My Game");
  main_window_.setVerticalSyncEnabled(true);
}

Engine::~Engine() {

}

void Engine::Run() {
  game_loop_.Loop(main_window_);
}