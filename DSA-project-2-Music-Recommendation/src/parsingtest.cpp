#include <iostream>
#include <string>
#include "Dataset.h"
#include "Song.h"

int main() {
    Dataset dataset("data/tracks_features.csv");

    const std::vector<Song>& songs = dataset.getSongs();

    std::cout << "Loaded songs: " << songs.size() << "\n\n";

    std::vector<int> indices = {0, 1, 2, 600000, 1200000, 1204024};


    for (int idx : indices) {
        const Song& s = songs[idx];

        std::cout << "Song #" << idx + 1 << "\n";
        std::cout << "ID: " << s.getId() << "\n";
        std::cout << "Name: " << s.getName() << "\n";

        std::cout << "Artists: ";
        for (const std::string& artist : s.getArtists()) {
            std::cout << artist << " ";
        }
        std::cout << "\n";

        std::cout << "Album: " << s.getAlbum() << "\n";

        std::cout << "Danceability: " << s.getDanceability() << "\n";
        std::cout << "Energy: " << s.getEnergy() << "\n";
        std::cout << "Valence: " << s.getValence() << "\n";
        std::cout << "Tempo: " << s.getTempo() << "\n";
        std::cout << "Acousticness: " << s.getAcousticness() << "\n";
        std::cout << "Instrumentalness: " << s.getInstrumentalness() << "\n";
        std::cout << "Loudness: " << s.getLoudness() << "\n";
        std::cout << "Speechiness: " << s.getSpeechiness() << "\n";
        std::cout << "Liveness: " << s.getLiveness() << "\n";

        std::cout << "Key: " << s.getKey() << "\n";
        std::cout << "Mode: " << s.getMode() << "\n";
        std::cout << "Duration (ms): " << s.getDurationMs() << "\n";

        std::cout << "Features: ";
        const std::vector<double>& features = s.getFeatures();

        for (double f : features) {
            std::cout << f << " ";
        }
        std::cout << std::endl;

        std::cout << "-----------------------------\n";
    }

    return 0;
}