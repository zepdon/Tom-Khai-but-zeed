#include <iostream>
#include "dialogueMaker.h"

Scene::Scene(string id, string dialogue, bool isEndScene=false) {
  this->id = id;
  this->dialogue = dialogue;
  this->isEndScene = isEndScene;
}

void Scene::printScene() {
  int sceneLength = dialogue.length();
  for (int i = 0; i < sceneLength; i++) {
    cout << "-";
  }
  cout << '\n' << dialogue << '\n';
  for (int i = 0; i < sceneLength; i++) {
    cout << "-";
  }
  if (options.size() > 0) {
    cout << "\n\n";
  }
  for (int i = 0; i < options.size(); i++) {
    cout << i+1 << ". " << options[i].text << '\n';
  }
  cout << "\n";
}

void Scene::addOption(string text, string nextSceneId) {
  Option option;
  option.text = text;
  option.sceneId = nextSceneId;
  options.push_back(option);
}

string Scene::chooseOption(int choice) {
  return options[choice-1].sceneId;
}

string Scene::getId() {
  return id;
}

string Scene::getDialogue() {
  return dialogue;
}

int Scene::getNumOptions() {
  return options.size();
}

bool Scene::getIsEndScene() {
  return isEndScene;
}

void Game::addScene(string id, string dialogue, bool isEndScene) {
  Scene* scene = new Scene(id, dialogue, isEndScene);
  Game::scenes[id] = scene;
}

void Game::addOption(string sceneId, vector<Option> options) {
  checkIfSceneExists(sceneId);
  for (int i = 0; i < options.size(); i++) {
    checkIfSceneExists(options[i].sceneId);
    Game::scenes[sceneId]->addOption(options[i].text, options[i].sceneId);
  }
}

void Game::start(string startSceneId) {
  Game::currentScene = Game::scenes[startSceneId];
}

void Game::setCurrentScene(string id) {
  Game::currentScene = Game::scenes[id];
}

void Game::printCurrentScene() {
  Game::currentScene->printScene();
}

void Game::askForChoice() {
  while (1) {
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;

    int choiceInt;
    try {
      choiceInt = stoi(choice);
    } catch (invalid_argument e) {
      cout << "Invalid choice." << '\n';
      continue;
    }

    if (choiceInt > 0 && choiceInt <= Game::currentScene->getNumOptions()) {
      string nextSceneId = Game::currentScene->chooseOption(choiceInt);
      setCurrentScene(nextSceneId);
      break;
    } else {
      cout << "Invalid choice." << '\n';
    }
  }
}

void Game::cleanUp() {
  for (auto it = Game::scenes.begin(); it != Game::scenes.end(); it++) {
    delete it->second;
  }
  Game::scenes.clear();
  Game::currentScene = NULL;
}

bool Game::gameEnded() {
  if (Game::currentScene->getIsEndScene()) {
    Game::currentScene->printScene();
    cleanUp();
    return true;
  }
  return false;
}

void Game::printAllScenes() {
  for (auto it = Game::scenes.begin(); it != Game::scenes.end(); it++) {
    cout << it->first << ": " << it->second->getDialogue() << '\n';
  }
}

void Game::runGame(string startSceneId) {
  checkIfSceneExists(startSceneId);
  start(startSceneId);
  while (!gameEnded()) { 
    printCurrentScene();
    askForChoice();
  }
}

void Game::checkIfSceneExists(string sceneId) {
  if (Game::scenes.find(sceneId) == Game::scenes.end()) {
    cout << "Scene with id \"" << sceneId << "\" does not exist." << '\n';
    cleanUp();
    exit(0);
  }
}
