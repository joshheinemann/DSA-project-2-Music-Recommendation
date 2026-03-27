#include <iostream>
#include "Dataset.h"
#include "Song.h"

int main() {
    Dataset dataset("data/tracks_features.csv");

    const std::vector<Song>& songs = dataset.getSongs();

    
    return 0;
}