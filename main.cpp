#include <iostream>
#include <fstream>
#include <sstream>
#include "dialogueMaker/dialogueMaker.h"

void readDialogueFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::string currentSceneId;
    std::string currentDialogue;
    bool isEndScene = false;

    while (std::getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        // Check if line starts with '##' to indicate a scene change
        if (line.substr(0, 2) == "##") {
            // If a scene is already in progress, add it to the Game
            if (!currentSceneId.empty()) {
                Game::addScene(currentSceneId, currentDialogue, isEndScene);
                currentDialogue.clear();
            }
            // Extract the scene ID from the line
            currentSceneId = line.substr(2);
            isEndScene = false; // Reset end scene flag
        }
        // Check if line starts with '#' to indicate an end scene
        else if (line.substr(0, 1) == "#") {
            // Extract the scene ID from the line
            currentSceneId = line.substr(1);
            isEndScene = true; // Set end scene flag
        }
        else {
            // Append the line to the current dialogue
            currentDialogue += line + '\n';
        }
    }

    // Add the last scene
    if (!currentSceneId.empty()) {
        Game::addScene(currentSceneId, currentDialogue, isEndScene);
    }
}

int main() {
    // Read dialogue from a text file
    readDialogueFromFile("dialogue.txt");

    // Game loop
    Game::runGame("begin");

    return 0;
}
