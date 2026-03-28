#include <vector>
#include <iostream>
#include <sstream>
#include "Dataset.h"
#include "KNN.h"

void printArtists(const std::vector<std::string>& artists) { //prints all the artists of the song
    for (size_t i = 0; i < artists.size(); i++) {
        std::cout << artists[i];
        if (i < artists.size() - 1) {
            std::cout << ", ";
        }
    }
}

int chooseSongFromMatches(const std::vector<Song>& songs, const std::vector<int>& matches) {
    if (matches.empty()) {
        return -1;
    }

    if (matches.size() == 1) {
        return matches[0];
    }

    while (true) {
        std::cout << "Multiple songs found with that name. Please choose one:" << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;

        for (size_t i = 0; i < matches.size(); i++) {
            const Song& song = songs[matches[i]];

            std::cout << i + 1 << ". " << song.getName() << " - ";

            const std::vector<std::string>& artists = song.getArtists();
            for (size_t j = 0; j < artists.size(); j++) {
                std::cout << artists[j];
                if (j < artists.size() - 1) {
                    std::cout << ", ";
                }
            }

            std::cout << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Enter the number of the correct song: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice >= 1 && choice <= static_cast<int>(matches.size())) {
            return matches[choice - 1];
        }

        std::cout << "Invalid selection. Try again." << std::endl;
        std::cout << std::endl;
    }
}

int promptUserForSong(const Dataset& dataset, const std::vector<Song>& songs) {
    while (true) {
        std::string songName;

        std::cout << "Please enter a song: " << std::endl;
        std::cout << "--------------------" << std::endl;
        std::getline(std::cin, songName);

        std::vector<int> matches = dataset.searchForSong(songName);

        if (matches.empty()) {
            std::cout << "Sorry, we couldn't find that song in our dataset." << std::endl;
            std::cout << "Please try again." << std::endl;
            std::cout << std::endl;
            continue;
        }

        return chooseSongFromMatches(songs, matches);
    }
}

void printRecommendations(const Song& userPicked, const std::vector<std::pair<double, Song>>& results) {
    std::cout << std::endl;
    std::cout << "User picked: " << userPicked.getName() << std::endl;
    std::cout << std::endl;

    for (size_t i = 0; i < results.size(); i++) {
        std::cout << "Song #" << i + 1 << std::endl;
        std::cout << "Name: " << results[i].second.getName() << std::endl;

        std::cout << "Artists: ";
        printArtists(results[i].second.getArtists());
        std::cout << std::endl;

        std::cout << "Distance: " << results[i].first << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

bool askToContinue() {
    while (true) {
        std::string answer;

        std::cout << std::endl;
        std::cout << "Would you like to search again? (y/n): " << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::getline(std::cin, answer);

        if (answer == "y" || answer == "Y") {
            return true;
        }

        if (answer == "n" || answer == "N") {
            return false;
        }

        std::cout << "Invalid input. Please enter y or n." << std::endl;
    }
}

int main() {
    Dataset dataset("data/tracks_features.csv");

    std::cout << "Welcome to SpotiFind, the music recommendation program!" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    const std::vector<Song>& songs = dataset.getSongs();

    bool keepRunning = true;

    while (keepRunning) {
        int chosenIndex = promptUserForSong(dataset, songs);
        const Song& userPicked = songs[chosenIndex];

        std::vector<std::pair<double, Song>> results = getFiveClosestKNN(userPicked, songs);
        printRecommendations(userPicked, results);

        keepRunning = askToContinue();
    }

    std::cout << std::endl;
    std::cout << "Thank you for using SpotiFind!" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    return 0;
}