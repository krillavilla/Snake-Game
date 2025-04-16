#include "obstacle.h"
#include <algorithm>

ObstacleManager::ObstacleManager(int grid_width, int grid_height, int obstacle_count)
    : grid_width_(grid_width),
      grid_height_(grid_height),
      obstacle_count_(obstacle_count),
      engine_(rd_()),
      random_w_(0, grid_width - 1),
      random_h_(0, grid_height - 1) {
    GenerateObstacles();
}

void ObstacleManager::GenerateObstacles() {
    obstacles_.clear();

    // Generate random obstacle positions
    for (int i = 0; i < obstacle_count_; ++i) {
        SDL_Point obstacle;
        bool valid_position = false;

        // Ensure we don't place obstacles on top of each other
        // or in the center (where the snake starts)
        while (!valid_position) {
            obstacle.x = random_w_(engine_);
            obstacle.y = random_h_(engine_);

            // Avoid center of grid (snake starting position)
            if (abs(obstacle.x - grid_width_ / 2) < 3 &&
                abs(obstacle.y - grid_height_ / 2) < 3) {
                continue;
            }

            // Check if position is already occupied by another obstacle
            valid_position = true;
            for (const auto& existing : obstacles_) {
                if (existing.x == obstacle.x && existing.y == obstacle.y) {
                    valid_position = false;
                    break;
                }
            }
        }

        obstacles_.push_back(obstacle);
    }
}

bool ObstacleManager::IsObstacle(int x, int y) const {
    for (const auto& obstacle : obstacles_) {
        if (obstacle.x == x && obstacle.y == y) {
            return true;
        }
    }
    return false;
}

const std::vector<SDL_Point>& ObstacleManager::GetObstacles() const {
    return obstacles_;
}

void ObstacleManager::Reset() {
    GenerateObstacles();
}