#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <vector>
#include <random>
#include "SDL.h"

class ObstacleManager {
public:
    // Constructor takes grid dimensions
    ObstacleManager(int grid_width, int grid_height, int obstacle_count);

    // Generate random obstacles on the grid
    void GenerateObstacles();

    // Check if a position contains an obstacle
    bool IsObstacle(int x, int y) const;

    // Get all obstacle positions for rendering
    const std::vector<SDL_Point>& GetObstacles() const;

    // Reset all obstacles (for new game)
    void Reset();

private:
    int grid_width_;
    int grid_height_;
    int obstacle_count_;
    std::vector<SDL_Point> obstacles_;
    std::random_device rd_;
    std::mt19937 engine_;
    std::uniform_int_distribution<int> random_w_;
    std::uniform_int_distribution<int> random_h_;
};

#endif // OBSTACLE_H