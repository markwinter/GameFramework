// MyGame.cpp
//
// The entry point of the game

#include "stdafx.h"
#include "GameLoop.h"

int main() {
  // Create a window
  //int w = sf::VideoMode().getDesktopMode().width;
  //int h = sf::VideoMode().getDesktopMode().height;
  int w = 800;
  int h = 600;
  sf::RenderWindow main_window;
  main_window.create(sf::VideoMode(w, h), "My Game");
  main_window.setVerticalSyncEnabled(true);

  GameLoop game_loop;
  game_loop.Loop(main_window);

  return 0;
}

