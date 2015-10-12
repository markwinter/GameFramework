# GameFramework

An SFML C++11/14 game framework that can be used as a starting point for roughly any game. I have tried to keep the SFML dependent parts to a minimum so that you can easily re-use the code with your favourite library of choice without much refactoring.

The idea is that you can just git clone this repo and get started straight away on making a game with all of the bare essentials done already.

I have attempted to stick to [Google's C++ Style Guide](https://google-styleguide.googlecode.com/svn/trunk/cppguide.html)

### TODO

- Add an animation example
- Collision detection using the quadtree and simple brute-force
- AudioManager should take SFML max instances into account
- Add function to AudioManager to transition nicely between background music
- State stack should have a max amount
- Change to entity-component based system for game objects (Prefer composition over inheritance). More flexible and will reduce code duplication later on.
- Add World/Map/Tiling (Add support for Tiled Map Editor formats?)

### What Is What (alphabetical)

###### AnimationFrame

Essentially just a container to store information about timing and duration of an animation frame

###### AnimationHandler

Handles transitioning between frames as time passes. It takes a bunch of AnimationFrames and stores them in a vector. Once enough time has passed
it will just change the animation frame to the next in the vector, looping to the start once all frames are done. Has a public sf::IntRect var
which can be used to set the TextureRect on your object's sprite (which should be a spritesheet) to get the appropriate sprite from it.

###### AudioManager

Allows the playing of audio easily and in the future, helpful functions such as transitioning between background music. Uses a cache of sf::SoundBuffer internally.

###### Cache

Template for creating caches e.g. audio cache, texture cache.

###### Engine

Top layer wrapper that sets up the window, calls the game loop, etc.

###### Example classes

Included in this repo is a couple of example classes, ExampleState and ExampleObject, so that you can see how the code should be used. Feel free to delete these.

###### GameLoop

The 'heart' of the framework. Polls the window, counts the frame time, calls HandleInput() Update() and Draw() on the current state of the game, calls UpdateAll() and DrawAll() on the object manager, and finally draws to the window.

###### GameObject

A plain game object class that you should inherit from to create your player, ai, items, etc. classes.

###### GameState

A plain state class that you should inherit from to create new states in your game e.g. PlayingState, PausedState

###### MyGame

This is the starting point and simply calls Run() on the Engine class

###### ObjectManager

Stores objects in a vector so that the Draw() and Update() functions can easily be called on them all.

###### QuadTree

Implements a quadtree for spatial partitioning. Simply stores pointers to GameObjects that get added and removed by the ObjectManager.
