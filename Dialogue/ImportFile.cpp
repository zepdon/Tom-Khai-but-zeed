#include "Importfile.h"
#include "../dialogueMaker/dialogueMaker.h"

void importScenesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line) && !line.empty()) {
        std::istringstream iss(line);
        std::string sceneId, dialogue, isEndSceneStr;
        std::getline(iss, sceneId, '|');
        std::getline(iss, dialogue, '|');
        std::getline(iss, isEndSceneStr);
        bool isEndScene = (isEndSceneStr == "true");

        // Debugging output
        std::cout << "Scene ID: " << sceneId << ", Dialogue: " << dialogue << ", Is End Scene: " << isEndScene << std::endl;

        Game::addScene(sceneId, dialogue, isEndSceneStr);
    }
    file.close();
}

void importEventsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line) && !line.empty()) {
        std::istringstream iss(line);
        std::string sceneId, event;
        std::getline(iss, sceneId, '|');
        std::getline(iss, event);

        // Debugging output
        std::cout << "Scene ID: " << sceneId << ", Event: " << event << std::endl;

        Game::addEvent(sceneId, event);
    }

    file.close();
}


void importOptionsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line) && !line.empty()) {
        std::istringstream iss(line);
        std::string sceneId, text, nextSceneId, event;
        std::getline(iss, sceneId, '|');
        std::getline(iss, text, '|');
        std::getline(iss, nextSceneId, '|');
        std::getline(iss, event);
        // Add option to the scene
        Game::addOption(sceneId, {{text, nextSceneId, event}});
    }

    file.close();
}
