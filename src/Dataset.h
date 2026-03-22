//this class will read and parse the song data from our data taken from kaggle
//takes the CSV file and creates song objects
//initially we will store all of the songs inside of a vector, then transfer to KD tree

#pragma once
#include <string>
#include <vector>
#include "Song.h"

class Dataset {
private:
    std::vector<Song> songs;

    std::string cleanField(const std::string& field);
    std::vector<std::string> parseRow(const std::string& line);
    std::vector<std::string> parsePythonList(const std::string& field);

public:
    explicit Dataset(const std::string& filepath);

    const std::vector<Song>& getSongs() const;
    int size() const;
};