#include <vector>
#include <iostream>
#include <sstream>
#include "Dataset.h"

using namespace std;

int main(){
    Dataset dataset;
    cout<<"Welcome to SpotiFind, the music recommendation program!" << endl;
    cout<<"----------------------------------------------------------" <<endl;
    cout<<endl;
    string song;
    string answer;
    vector <int> songData;
    //parsing input
    bool continue = false;
    while (continue = false){
        cout << "Please enter a song: "<<endl;
        cout << "----------------------" << endl;
        getline(cin, song);
        songData = dataset.searchForSong(song);
        if(songData != {}){
          cout<<"Song found!"<<endl;
        }
        else{
            cout << "Sorry, we couldn't find that song in our dataset..." << endl;
            cout << "----------------------------------------------------" << endl;
        }
        cout << "Would you like to continue? (y/n):"<<endl;
        cout << "-----------------------------------" << endl;
        getline(cin; answer);
        if(answer == "n"){
            continue = true;
        }
    }
    cout << "Thank you for using SpotiFind! " << endl;
    cout << "-------------------------------"<<endl;

    return 0;
}