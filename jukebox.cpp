#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <SDL2/SDL.h>

using namespace std;
namespace fs = std::filesystem;

// Jukebox class
class Jukebox {
private:
    vector<string> songTitles;

public:
    // Load songs from a specified folder
    void listSongs(const string& folderPath) {
        for (const auto& entry : fs::directory_iterator(folderPath)) {
            if (entry.is_regular_file()) {
                songTitles.push_back(entry.path().filename().string());
            }
        }
        cout << "Loaded " << songTitles.size() << " songs from " << folderPath << endl;
    }

    // List all loaded songs
    void printSongs() {
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
        string filePath = "/home/innocent/Music/empire cast" + songTitle;
        if (SDL_Init(SDL_INIT_AUDIO) < 0) {
            cout << "SDL initialization failed: " << SDL_GetError() << endl;
            return;
        }
        SDL_AudioSpec wavSpec;
        Uint32 wavLength;
        Uint8 *wavBuffer;
        if (SDL_LoadWAV(filePath.c_str(), &wavSpec, &wavBuffer, &wavLength) == NULL) {
            cout << "Error loading WAV file: " << SDL_GetError() << endl;
            return;
        }
        SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
        if (deviceId == 0) {
            cout << "Failed to open audio device: " << SDL_GetError() << endl;
            SDL_FreeWAV(wavBuffer);
            SDL_Quit();
            return;
        }
        SDL_PauseAudioDevice(deviceId, 0);
        SDL_QueueAudio(deviceId, wavBuffer, wavLength);
        SDL_Delay((wavLength / wavSpec.freq) * 1000);
        SDL_CloseAudioDevice(deviceId);
        SDL_FreeWAV(wavBuffer);
        SDL_Quit();
    }
};

int main() {
    Jukebox jukebox;

    // Load songs from the specified folder
    jukebox.listSongs("/home/innocent/Music/empire cast");

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
                jukebox.printSongs();
                break;
            case 2: {
                string title;
                cout << "Enter song title to play: ";
                cin >> title;
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
