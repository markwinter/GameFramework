# GameFramework

An SFML C++11/14 game framework that can be used as a starting point for roughly any game. I have tried to keep the SFML dependent parts to a minimum so that you can easily re-use the code with your favourite library of choice without much refactoring.

The idea is that you can just git clone this repo and get started straight away on making a game with all of the bare essentials done already.

### What Is What (alphabetical)

###### AudioManager

Allows the playing of audio easily and eventually helpful functions such as transitioning between background music. Uses the audio cache internally.

###### AudioCache

Contains two unordered_maps for caching audio using the sf::Music and sf::SoundBuffer classes from SFML.

###### Cache

Template for creating caches e.g. texture cache

###### Example classes

Included in this repo is a couple of example classes, ExampleState and ExampleObject, so that you can see how the code should be used. Feel free to delete these.

###### GameLoop

The 'heart' of the framework. Sets up the game window (should probably be refactored out of this class) and proceeds to poll the window, count the frame time, call HandleInput() Update() and Draw() on the current state of the game, calls UpdateAll() and DrawAll() on the object manager, and finally draws to the window.

###### GameState

A plain state class that you should inherit from to create new states in your game e.g. PlayingState, PausedState

###### GameObject

A plain game object class that you should inherit from to create your player, ai, items, etc. classes.

###### MyGame

This is the starting point and simply calls the game loop

###### ObjectManager

Stores objects in a vector so that the Draw() and Update() functions can easily be called on them all.
