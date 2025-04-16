#ifndef HIGH_SCORE_H
#define HIGH_SCORE_H

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

struct ScoreEntry {
    std::string name;
    int score;

    // Constructor for convenience
    ScoreEntry(std::string n, int s) : name(std::move(n)), score(s) {}

    // Comparison operator for sorting
    bool operator<(const ScoreEntry& other) const {
        return score > other.score; // Note: reverse order for descending sort
    }
};

class HighScoreManager {
public:
    // Constructor takes filename for the high scores file
    explicit HighScoreManager(std::string filename);

    // Add a new score to the list
    void AddScore(const std::string& name, int score);

    // Get the top N scores (default: 5)
    std::vector<ScoreEntry> GetTopScores(int count = 5) const;

private:
    std::string filename_;
    std::vector<ScoreEntry> scores_;

    // Load scores from file
    void LoadScores();

    // Save scores to file
    void SaveScores();
};

#endif // HIGH_SCORE_H