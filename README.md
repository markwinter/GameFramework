# GameFramework

An SFML C++11 game framework that can be used as a starting point for roughly any game. I have tried to keep the SFML dependent parts to a minimum so that you can easily re-use the code with your favourite library of choice without much refactoring.

The idea is that you can just git clone this repo and get started straight away on making a game with all of the bare essentials done already.

### What Is What

###### MyGame.cpp

This is the starting point and simply calls the game loop

###### ObjectManager.h

This is a templated class (although I might remove the templating) that stores objects in a vector so that the Draw() and Update() functions can easily be called on them all.

###### AudioCache.cpp / AudioCache.h

Contains two unordered maps for caching audio using the sf::Music and sf::SoundBuffer classes from SFML.

###### GameLoop.cpp / GameLoop.h

The 'heart' of the framework. Sets up the game window (should probably be refactored out of this class) and proceeds to poll the window, count the frame time, call HandleInput() Update() and Draw() on the current state of the game, calls UpdateAll() and DrawAll() on the object manager, and finally draws to the window.

###### GameState.cpp / GameState.h

A plain state class that you should inherit from to create new states in your game.

###### GameObject.cpp / GameObject.h

A plain game object class that you should inherit from to create your player, ai, items, etc. classes.


###### Example classes

Included in this repo is a couple of example classes, ExampleState and ExampleObject, so that you can see how the code should be used. Feel free to delete these.
