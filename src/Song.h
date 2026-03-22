#pragma once
#include <string>

class Song {
private:
    //basic song information (identifying the song)
    std::string id;
    std::string name;
    std::string artist;
    std::string album;

    //song features
    double danceability;
    double energy;
    double valence;
    double acousticness;
    double instrumentalness;
    double loudness;
    double speechiness;
    double liveness;
    
    //more technical features
    int key;
    int mode;
    double tempo;

    int duration_ms;

public:
    // constructor
    Song(std::string id, std::string name, std::string artist, std::string album,
         double danceability, double energy, double valence, double tempo,
         double acousticness, double instrumentalness, double loudness,
         double speechiness, double liveness, int key, int mode, int duration_ms);

    // getters
    std::string getName() const;
    std::string getArtist() const;

};
