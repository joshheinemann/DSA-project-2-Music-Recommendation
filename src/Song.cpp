#include "Song.h"

Song::Song(std::string id, std::string name, std::vector<std::string> artists, std::string album,
           double danceability, double energy, double valence, double tempo,
           double acousticness, double instrumentalness, double loudness,
           double speechiness, double liveness, int key, int mode, int duration_ms)
    : id(id), name(name), artists(artists), album(album),
      danceability(danceability), energy(energy), valence(valence), tempo(tempo),
      acousticness(acousticness), instrumentalness(instrumentalness),
      loudness(loudness), speechiness(speechiness), liveness(liveness),
      key(key), mode(mode), duration_ms(duration_ms) {}

std::string Song::getName() const {
    return name;
}

std::vector<std::string> Song::getArtists() const {
    return artists;
}