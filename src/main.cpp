#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "high_score.h"
#include "obstacle.h"
#include "speed_selector.h"

int main() {
  // Ask for player name before the game starts
  std::string player_name;
  std::cout << "Enter your name: ";
  std::cin >> player_name;

  // Game configuration
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  // Allow player to select game speed
  SpeedSelector speedSelector;
  speedSelector.PromptForSelection();
  float speed_factor = speedSelector.GetSelectedSpeed();

  // Calculate the frame time based on selected speed
  std::size_t adjusted_ms_per_frame = static_cast<std::size_t>(kMsPerFrame / speed_factor);

  // Create obstacle manager (5 obstacles)
  ObstacleManager obstacleManager(kGridWidth, kGridHeight, 5);

  // Game loop
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);

  // Pass obstacles to game and renderer (assuming Game and Renderer classes have been modified to accept obstacles)
  game.SetObstacles(obstacleManager.GetObstacles());
  renderer.SetObstacles(obstacleManager.GetObstacles());

  game.Run(controller, renderer, adjusted_ms_per_frame);

  // End-of-game output
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  // Save and display high scores
  HighScoreManager manager("highscores.txt");
  manager.AddScore(player_name, game.GetScore());

  std::cout << "\n🏆 Top 5 High Scores:\n";
  auto top_scores = manager.GetTopScores();
  for (const auto &entry : top_scores) {
    std::cout << entry.name << ": " << entry.score << "\n";
  }

  return 0;
}