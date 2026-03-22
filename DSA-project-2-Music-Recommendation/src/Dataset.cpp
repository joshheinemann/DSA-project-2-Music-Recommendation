#pragma once
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include "Dataset.h"


std::vector<string> Dataset::parseRow(const std::string& line) {
    std::vector<std::string> fields;
    std::string field;
    bool inBrackets = false;

    for (char c : line) {
        if (c == '[') {
            inBrackets = true;
            field += c;
        } else if (c == ']') {
            inBrackets = false;
            field += c;
        } else if (c == ',' && !inBrackets) {
            fields.push_back(field);
            field.clear();
        } else {
            field += c;
        }
    }
    fields.push_back(field);  // last field
    return fields;
}

std::vector<std::string> Dataset::parseList(const std::string& field) {
    std::vector<std::string> result;

    size_t start = field.find('[');
    size_t end   = field.find(']');
    if (start == std::string::npos || end == std::string::npos)
        return result;

    std::string inner = field.substr(start + 1, end - start - 1);

    size_t pos = 0;
    while (pos < inner.size()) {
        size_t open = inner.find('\'', pos);
        if (open == std::string::npos) break;
        size_t close = inner.find('\'', open + 1);
        if (close == std::string::npos) break;

        result.push_back(inner.substr(open + 1, close - open - 1));
        pos = close + 1;
    }

    return result;
}

Dataset::Dataset(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open())
        throw std::runtime_error("Could not open dataset file: " + filepath);

    std::string line;
    if (!std::getline(file, line))
        throw std::runtime_error("Dataset file is empty: " + filepath);

    int lineNumber = 1;
    while (std::getline(file, line)) {
        ++lineNumber;
        if (line.empty()) continue;

        try {
            auto f = parseRow(line);
            if (f.size() != 24) {
                throw std::runtime_error("Row does not have exactly 24 columns");
            }

            songs.emplace_back(
                f.at(0),                                 // id
                f.at(1),                                 // name
                parseList(f.at(4)),                      // artists
                f.at(2),                                 // album
                std::stod(f.at(9)),                      // danceability
                std::stod(f.at(10)),                     // energy
                std::stod(f.at(18)),                     // valence
                std::stod(f.at(19)),                     // tempo
                std::stod(f.at(15)),                     // acousticness
                std::stod(f.at(16)),                     // instrumentalness
                std::stod(f.at(12)),                     // loudness
                std::stod(f.at(14)),                     // speechiness
                std::stod(f.at(17)),                     // liveness
                std::stoi(f.at(11)),                     // key
                std::stoi(f.at(13)),                     // mode
                static_cast<int>(std::stod(f.at(20)))    // duration_ms
            );

        } catch (const std::exception& e) {
            std::cerr << "Warning: Skipping malformed row " << lineNumber
                      << " (" << e.what() << ")\n";
        }
    }
}

const std::vector<Song>& Dataset::getSongs() const { return songs; }
int Dataset::size() const { return static_cast<int>(songs.size()); }