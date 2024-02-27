#include <iostream>
#include "dialogueMaker.h"
#include <Windows.h>

Scene::Scene(std::string id, std::string dialogue, bool isEndScene) {
  this->id = id;
  this->dialogue = dialogue;
  this->isEndScene = isEndScene;
}

void Scene::printScene() {
  std::cout << "---------------------------------------------------------------------------------------------------------------------------";
  std::cout << '\n' << dialogue << '\n';
  std::cout << "---------------------------------------------------------------------------------------------------------------------------";
  if (options.size() > 0) {
    std::cout << "\n\n";
  }
  for (int i = 0; i < options.size(); i++) {
    std::cout << i+1 << ". " << options[i].text << '\n';
  }
  std::cout << "\n";
}

void Scene::addOption(std::string text, std::string nextSceneId, std::string event) {
  Option option;
  option.text = text;
  option.sceneId = nextSceneId;
  option.event = event;
  options.push_back(option);
}

void Scene::addEvent(std::string event) {
  events.insert(event);
}

std::pair<std::string, std::string> Scene::chooseOption(int choice) {
  return {options[choice-1].sceneId, options[choice-1].event};
}

std::string Scene::getId() {
  return id;
}

std::string Scene::getDialogue() {
  return dialogue;
}

int Scene::getNumOptions() {
  return options.size();
}

bool Scene::getIsEndScene() {
  return isEndScene;
}

bool Scene::hasEvent(std::string event) {
  return events.find(event) != events.end();
}

void Game::addScene(std::string id, std::string dialogue, bool isEndScene) {
  Scene* scene = new Scene(id, Game::parseText(dialogue), isEndScene);
  Game::scenes[id] = scene;
}

void Game::addEvent(std::string sceneId, std::string event) {
  checkIfSceneExists(sceneId);
  Game::scenes[sceneId]->addEvent(event);
}

void Game::addOption(std::string sceneId, std::string optionText, std::string nextSceneId, std::string event) {
  checkIfSceneExists(sceneId);
  Game::scenes[sceneId]->addOption(parseText(optionText), nextSceneId, event);
}

void Game::start(std::string startSceneId) {
  Game::currentScene = Game::scenes[startSceneId];
}

void Game::setCurrentScene(std::string id) {
  Game::currentScene = Game::scenes[id];
  for (auto it = Game::currentEvents.begin(); it != Game::currentEvents.end(); it++) {
    if (Game::currentScene->hasEvent(*it)) {
      Game::currentScene = Game::scenes[*it];
    }
  }
}

void Game::printCurrentScene() {
  std::cout << "\033[2J\033[1;1H";
  Game::currentScene->printScene();
}

void Game::addCurrentEvent(std::string event) {
  currentEvents.insert(event);
}

void Game::askForChoice() {
  while (1) {
    std::string choice;
    std::string x = "Enter Your Choice: ";
    for (int i = 0; i < x[i]; i++)
    {
      std::cout << x[i];
      Sleep(15);
    }
    std::cin >> choice;

    int choiceInt;
    try {
      choiceInt = std::stoi(choice);
    } catch (std::invalid_argument e) {
      std::cout << "Invalid choice." << '\n';
      continue;
    }

    if (choiceInt > 0 && choiceInt <= Game::currentScene->getNumOptions()) {
      std::pair<std::string, std::string> nextScene = Game::currentScene->chooseOption(choiceInt);
      std::string nextSceneId = nextScene.first;
      std::string event = nextScene.second;
      Game::setCurrentScene(nextSceneId);
      Game::addCurrentEvent(event);
      break;
    } else {
      std::cout << "Invalid choice." << '\n';
    }
  }
}

void Game::cleanUp() {
  for (auto it = Game::scenes.begin(); it != Game::scenes.end(); it++) {
    delete it->second;
  }
  Game::scenes.clear();
  Game::currentScene = nullptr;
}

bool Game::gameEnded() {
  if (Game::currentScene->getIsEndScene()) {
    Game::printCurrentScene();
    cleanUp();
    return true;
  }
  return false;
}

void Game::printAllScenes() {
  for (auto it = Game::scenes.begin(); it != Game::scenes.end(); it++) {
    std::cout << it->first << ": " << it->second->getDialogue() << '\n';
  }
}

void Game::runGame(std::string startSceneId) {
  checkIfSceneExists(startSceneId);
  start(startSceneId);
  while (!gameEnded()) { 
    printCurrentScene();
    askForChoice();
  }
}

void Game::checkIfSceneExists(std::string sceneId) {
  if (Game::scenes.find(sceneId) == Game::scenes.end()) {
    std::cout << "Scene with id \"" << sceneId << "\" does not exist." << '\n';
    cleanUp();
    exit(0);
  }
}

std::string Game::parseText(std::string text) {
  std::map<std::string, std::string> decorations = {
    {"b", "\033[1m"}, // Bold
    {"ul", "\033[4m"}, // Underline
    {"r", "\033[31m"}, // Red
    {"g", "\033[32m"}, // Green
    {"y", "\033[33m"}, // Yellow
    {"random", "\033[38;2;76;42;107m"}, // rgb(69, 211, 76)
  };
  std::vector<std::string> tags;
  std::string parsedText = "";
  std::string currentTag = "";

  for (int i = 0; i < text.size(); i++) {
    if (text[i] == '[') {
      i++;
      while (text[i] != ']') {
        currentTag += text[i];
        i++;
      }
      if (currentTag == "/") {
        tags.pop_back();
        parsedText += "\033[m";
        for (int i = 0; i < tags.size(); i++) {
          parsedText += decorations[tags[i]];
        }
      } else {
        tags.push_back(currentTag);
        parsedText += decorations[currentTag];
      }
      currentTag = "";
    } else {
      parsedText += text[i];
    }
  }

  for (int i = 0; i < tags.size(); i++) {
    parsedText += "\033[m";
  }
  return parsedText;
}
