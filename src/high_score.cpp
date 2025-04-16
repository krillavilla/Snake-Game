#include "high_score.h"
#include <iostream>

HighScoreManager::HighScoreManager(std::string filename)
    : filename_(std::move(filename)) {
    LoadScores();
}

void HighScoreManager::AddScore(const std::string& name, int score) {
    scores_.emplace_back(name, score);
    // Sort scores in descending order
    std::sort(scores_.begin(), scores_.end());
    // Save to file
    SaveScores();
}

std::vector<ScoreEntry> HighScoreManager::GetTopScores(int count) const {
    // Make sure we don't try to return more scores than we have
    int available = std::min(static_cast<int>(scores_.size()), count);

    // Return a copy of the top 'available' scores
    return std::vector<ScoreEntry>(scores_.begin(), scores_.begin() + available);
}

void HighScoreManager::LoadScores() {
    std::ifstream file(filename_);

    // If file doesn't exist, just return (we'll create it when saving)
    if (!file.is_open()) {
        return;
    }

    // Clear existing scores
    scores_.clear();

    // Read scores from file
    std::string name;
    int score;

    while (file >> name >> score) {
        scores_.emplace_back(name, score);
    }

    // Sort scores in descending order
    std::sort(scores_.begin(), scores_.end());

    file.close();
}

void HighScoreManager::SaveScores() {
    std::ofstream file(filename_);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename_ << " for writing." << std::endl;
        return;
    }

    for (const auto& entry : scores_) {
        file << entry.name << " " << entry.score << std::endl;
    }

    file.close();
}