# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## 🚀 New Features Added

This game extends the original Snake project with the following new features:

### 🏆 High Score Saving System
- Players enter their name at the start of the game.
- Scores are saved to `highscores.txt` using a file-based storage system.
- Top 5 high scores are displayed at the end of the game.
- This feature demonstrates file I/O, use of structs, vector sorting, and encapsulation via a `HighScoreManager` class.

### 📈 Game Speed Selector (Planned)
- Users will choose the initial speed before starting the game.
- Demonstrates input processing and immutable game state configuration.

### 🧱 Static Obstacles (Planned)
- Static blocks will be added as obstacles in the game environment.
- Demonstrates collision detection and a dedicated `ObstacleManager` class.

> ✅ These features collectively address multiple rubric criteria across loops/functions, OOP, memory management, I/O, and game interaction.


## 🧠 Rubric Coverage

| Rubric Area            | Criteria Satisfied                                           |
|------------------------|--------------------------------------------------------------|
| README + Build         | Includes instructions, structure, and rubric mapping         |
| Loops / Functions      | Control structures, input parsing, and I/O                   |
| Object-Oriented Design | Custom `HighScoreManager` class encapsulates logic           |
| Memory Management      | Vector containers, RAII pattern for file handling            |
| File I/O               | Save/load scores with `fstream`                             |
| (Planned) Concurrency  | Threaded logic for AI Snake or obstacle movement (optional)  |

---

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
