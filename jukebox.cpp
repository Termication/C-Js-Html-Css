#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Song structure to hold song details
struct Song {
    string title;
    string artist;
};

// Jukebox class
class Jukebox {
private:
    vector<Song> songs;

public:
    // Add a song to the jukebox
    void addSong(const string& title, const string& artist) {
        Song newSong = {title, artist};
        songs.push_back(newSong);
        cout << "Added \"" << title << "\" by " << artist << " to the jukebox." << endl;
    }

    // List all songs in the jukebox
    void listSongs() {
        if (songs.empty()) {
            cout << "No songs in the jukebox." << endl;
        } else {
            cout << "Songs in the jukebox:" << endl;
            for (const auto& song : songs) {
                cout << song.title << " by " << song.artist << endl;
            }
        }
    }

    // Play a song from the jukebox
    void playSong(const string& title) {
        bool found = false;
        for (const auto& song : songs) {
            if (song.title == title) {
                found = true;
                cout << "Playing \"" << title << "\" by " << song.artist << "..." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Song \"" << title << "\" not found in the jukebox." << endl;
        }
    }
};

int main() {
    Jukebox jukebox;

    // Add some initial songs
    jukebox.addSong("Shape of You", "Ed Sheeran");
    jukebox.addSong("Rolling in the Deep", "Adele");
    jukebox.addSong("Bohemian Rhapsody", "Queen");

    // Menu loop
    int choice;
    do {
        cout << "\nJukebox Menu:" << endl;
        cout << "1. Add a song" << endl;
        cout << "2. List all songs" << endl;
        cout << "3. Play a song" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, artist;
                cout << "Enter song title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist name: ";
                getline(cin, artist);
                jukebox.addSong(title, artist);
                break;
            }
            case 2:
                jukebox.listSongs();
                break;
            case 3: {
                string title;
                cout << "Enter song title to play: ";
                cin.ignore();
                getline(cin, title);
                jukebox.playSong(title);
                break;
            }
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
