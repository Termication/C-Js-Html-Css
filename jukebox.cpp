#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

using namespace std;
namespace fs = std::filesystem;

// Jukebox class
class Jukebox {
private:
    vector<string> songTitles;

public:
    // Load songs from a specified folder
    void loadSongs(const string& folderPath) {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (entry.is_regular_file()) {
                songTitles.push_back(entry.path().filename().string());
            }
        }
        cout << "Loaded " << songTitles.size() << " songs from " << folderPath << endl;
    }

    // List all loaded songs
    void listSongs() {
        if (songTitles.empty()) {
            cout << "No songs loaded." << endl;
        } else {
            cout << "Songs loaded:" << endl;
            for (const auto& title : songTitles) {
                cout << title << endl;
            }
        }
    }

    // Play a song
    void playSong(const string& songTitle) {
        string filePath = "./" + songTitle;
        ifstream file(filePath);
        if (file) {
            cout << "Playing " << songTitle << "..." << endl;
            // Here you can add code to play the song using a suitable library
        } else {
            cout << "Song \"" << songTitle << "\" not found." << endl;
        }
    }
};

int main() {
    Jukebox jukebox;

    // Load songs from a folder
    jukebox.loadSongs("/home/innocent/Music/empirecast");

    // Menu loop
    int choice;
    do {
        cout << "\nJukebox Menu:" << endl;
        cout << "1. List all songs" << endl;
        cout << "2. Play a song" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                jukebox.listSongs();
                break;
            case 2: {
                string title;
                cout << "Enter song title to play: ";
                cin.ignore();
                getline(cin, title);
                jukebox.playSong(title);
                break;
            }
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
