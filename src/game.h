#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  // Add these new methods to match the game.cpp implementation
  void SetObstacles(const std::vector<SDL_Point>& obstacles);
  bool CheckObstacleCollision();
  bool IsObstacle(int x, int y) const;

 private:
  Snake snake;
  SDL_Point food;
  std::vector<SDL_Point> obstacles_; // Add the obstacles vector

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
};

#endif