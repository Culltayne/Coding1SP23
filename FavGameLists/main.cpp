#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
using namespace std;

const int MAX_SIZE = 100;
string favGames[MAX_SIZE];
int gameCount = 0;
int saveFileCount = 0;
int currentSaveFileNumber = -1;

string getSaveFileName() {
    stringstream ss;
    ss << "save" << saveFileCount << ".txt";
    return ss.str();
}

void add() {
    string game;
    cout << "Enter games you would like to add (type \"done\" when finished):" << endl;
    while (getline(cin, game) && gameCount < MAX_SIZE) {
        if (game == "done") {
            break;
        }
        favGames[gameCount++] = game;
    }
}

void show() {
    cout << "Favorite Games:" << endl;
    for (int i = 0; i < saveFileCount; ++i) {
        string fileName = "save" + to_string(i) + ".txt";
        ifstream file(fileName);
        string line;

        if (file.is_open()) {
            cout << "From file: " << fileName << endl;
            while (getline(file, line)) {
                cout << line << endl;
            }
            cout << endl; 
            file.close();
        }
    }
}

void remove() {
    string game;
    cout << "Enter games you want to remove (type \"done\" when finished):" << endl;
    while (getline(cin, game)) {
        if (game == "done") {
            break;
        }

        bool removed = false;
        for (int i = 0; i < gameCount; ++i) {
            if (favGames[i] == game) {
                for (int j = i; j < gameCount - 1; ++j) {
                    favGames[j] = favGames[j + 1];
                }
                --gameCount;
                removed = true;
                break;
            }
        }

        if (!removed) {
            cout << "Game not found: " << game << endl;
        }
    }
}

void edit() {
    string oldGame, newGame;
    cout << "Which game do you want to edit?" << endl;
    getline(cin, oldGame);
    cout << "Enter the new name for the game:" << endl;
    getline(cin, newGame);

    for (int i = 0; i < gameCount; ++i) {
        if (favGames[i] == oldGame) {
            favGames[i] = newGame;
            break;
        }
    }
}

void load() {
    cout << "Enter the save file number you want to load: ";
    int fileNumber;
    cin >> fileNumber;
    cin.ignore(); 

    if (fileNumber >= 0 && fileNumber < saveFileCount) {
        ifstream file("save" + to_string(fileNumber) + ".txt");
        string line;

        if (file.is_open()) {
            gameCount = 0;
            while (getline(file, line) && gameCount < MAX_SIZE) {
                favGames[gameCount++] = line;
            }
            file.close();
            currentSaveFileNumber = fileNumber;
            cout << "Save file " << fileNumber << " loaded successfully." << endl;
        } else {
            cout << "File could not be loaded." << endl;
        }
    } else {
        cout << "Invalid file number. Please try again." << endl;
    }
}

void save() {
    ofstream file;
    if (currentSaveFileNumber != -1) {
        file.open("save" + to_string(currentSaveFileNumber) + ".txt");
    } else {
        file.open(getSaveFileName());
    }

    if (file.is_open()) {
        for (int i = 0; i < gameCount; ++i) {
            file << favGames[i] << endl;
        }
        file.close();

        if (currentSaveFileNumber == -1) {
            saveFileCount++;
        }
        gameCount = 0; // Clear the current list of games after saving
    } else {
        cout << "File could not be saved." << endl;
    }
}

int main() {
    cout << "Welcome to the favorite games program!" << endl;
    string choice;

    while (true) {
        cout << "Choose an option (add/show/remove/edit/load/save/quit): ";
        getline(cin, choice);

        if (choice == "add") {
            add();
        } else if (choice == "show") {
            show();
        } else if (choice == "remove") {
            remove();
        } else if (choice == "edit") {
            edit();
        } else if (choice == "load") {
            load();
        } else if (choice == "save") {
            save();
        } else if (choice == "quit") {
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}