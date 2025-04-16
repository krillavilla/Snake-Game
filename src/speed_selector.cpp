#include "speed_selector.h"
#include <iostream>
#include <limits>

SpeedSelector::SpeedSelector() {
    // Default speed options: name and speed factor
    speed_options_ = {
        {"Slow", 0.75f},
        {"Normal", 1.0f},
        {"Fast", 1.5f},
        {"Insane", 2.0f}
    };
}

SpeedSelector::SpeedSelector(std::vector<std::pair<std::string, float>> speed_options)
    : speed_options_(std::move(speed_options)) {
}

float SpeedSelector::GetSelectedSpeed() {
    return selected_speed_;
}

void SpeedSelector::PromptForSelection() {
    int choice = 0;
    bool valid_choice = false;

    std::cout << "\nSelect game speed:\n";
    for (size_t i = 0; i < speed_options_.size(); ++i) {
        std::cout << (i + 1) << ". " << speed_options_[i].first << "\n";
    }

    while (!valid_choice) {
        std::cout << "Enter your choice (1-" << speed_options_.size() << "): ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();  // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard input
            std::cout << "Invalid input. Please enter a number.\n";
        } else if (choice < 1 || choice > static_cast<int>(speed_options_.size())) {
            std::cout << "Invalid choice. Please try again.\n";
        } else {
            valid_choice = true;
        }
    }

    // Set the selected speed factor
    selected_speed_ = speed_options_[choice - 1].second;
    std::cout << "Selected speed: " << speed_options_[choice - 1].first << "\n\n";
}