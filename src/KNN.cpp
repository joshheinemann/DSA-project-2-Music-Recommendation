#include "Dataset.h"
#include "Song.h"
#include <queue>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <iostream>
#include <algorithm>


double Distance(const Song& a, const Song& b) {                 //euclidian distance
    std::vector<double> a_features = a.getFeatures();
    std::vector<double> b_features = b.getFeatures();

    if (a_features.size() != b_features.size()) {
        throw std::invalid_argument("Songs must have same number of features");
    }

    double sum = 0.0;

    for (size_t i = 0; i < a_features.size(); i++) {
        double diff = a_features[i] - b_features[i];
        sum += diff * diff;
    }

    return std::sqrt(sum);
}

std::vector<std::pair<double, Song>> getFiveClosestKNN(){
    Dataset dataset("data/tracks_features.csv"); //parse data from kaggle and create our dataset class

    const std::vector<Song>& songs = dataset.getSongs(); //get the vector of all of the songs
      
    std::priority_queue<std::pair<double, Song>> maxheap; // will use a maxheap to store the 5 most similar songs

    Song userpicked = songs[0]; // temporary holder but we will need to implement logic for the user to pick a song that is in our dataset

    //loop through all of the songs in the dataset. if current song is closer than any of the current 5 in the dataset,
    //add it and remove the one that is farthest away (top of maxheap)
    for(Song s : songs){
        if(s.getId() == userpicked.getId()){continue;}

        double dist = Distance(userpicked, s);

        if(maxheap.size() < 5){
            maxheap.push({dist, s});
        }
        else if(dist < maxheap.top().first){
            maxheap.pop();
            maxheap.push({dist, s});
        }
    }

    std::vector<std::pair<double, Song>> results;

    while (!maxheap.empty()) {
        results.push_back(maxheap.top());
        maxheap.pop();
    }

    std::reverse(results.begin(), results.end());

    // for (size_t i = 0; i < results.size(); i++) {
    //     std::cout << "Song #" << i + 1 << std::endl;
    //     std::cout << "Name: " << results[i].second.getName() << std::endl;
        
    //     std::cout << "Artists: ";
    //     std::vector<std::string> artists = results[i].second.getArtists();

    //     for(int j = 0; j < artists.size(); j++){
    //         std::cout << artists[j];
    //         if (j < artists.size() - 1) std::cout << ", ";
    //     }

    //     std::cout << std::endl;
    //     std::cout << "Distance: " << results[i].first << std::endl;
    //     std::cout << "------------------------" << std::endl;
    // }

    return results;
    
}