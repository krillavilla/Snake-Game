#ifndef SPEED_SELECTOR_H
#define SPEED_SELECTOR_H

#include <string>
#include <vector>
#include <iostream>

class SpeedSelector {
public:
    // Constructor with default speed options
    SpeedSelector();

    // Constructor with custom speed options
    explicit SpeedSelector(std::vector<std::pair<std::string, float>> speed_options);

    // Get user-selected speed factor
    float GetSelectedSpeed();

    // Display speed options and prompt user for selection
    void PromptForSelection();

private:
    std::vector<std::pair<std::string, float>> speed_options_;
    float selected_speed_ = 1.0f;  // Default speed factor
};

#endif // SPEED_SELECTOR_H