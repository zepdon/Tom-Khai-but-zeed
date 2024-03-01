#include "dialogueMaker/dialogueMaker.h"
#include "Dialogue/ImportFile.h"

void importASCIIsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::string sceneId;
    std::string asciiArt;
    
    while (std::getline(file, line)) {
        if (line.empty()) continue;  // Skip empty lines

        if (line.find('|') == std::string::npos) {
            // This line contains the ASCII art
            asciiArt += line + "\n";  // Append to the ASCII art
        } else {
            // This line contains a scene ID
            if (!sceneId.empty() && !asciiArt.empty()) {
                // Store the previous scene's ASCII art
                Game::setSceneAscii(sceneId, asciiArt);
                std::cout << "Stored ASCII art for scene ID: " << sceneId << '\n';
                std::cout << "ASCII art:\n" << asciiArt << '\n';
            }
            // Extract the scene ID from the line
            std::istringstream iss(line);
            std::getline(iss, sceneId, '|');
            asciiArt = "";  // Reset ASCII art for the next scene
        }
    }
    
    // Store the last scene's ASCII art
    if (!sceneId.empty() && !asciiArt.empty()) {
        Game::setSceneAscii(sceneId, asciiArt);
        std::cout << "Stored ASCII art for scene ID: " << sceneId << '\n';
        std::cout << "ASCII art:\n" << asciiArt << '\n';
    }

    file.close();
}





int main() {
    importScenesFromFile("example/exampleDialogue.txt");
    importEventsFromFile("example/exampleEvent.txt");
    importOptionsFromFile("example/exampleOption.txt");
    importASCIIsFromFile("example/exampleASCII.txt");

    Game::runGame("begin");
    return 0;
}
