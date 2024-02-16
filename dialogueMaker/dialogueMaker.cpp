#include <iostream>
#include "dialogueMaker.h"

Scene::Scene(string id, string dialogue, bool isEndScene=false) {
  this->id = id;
  this->dialogue = dialogue;
  this->isEndScene = isEndScene;
}

void Scene::printScene() {
  cout << dialogue << '\n';
  for (int i = 0; i < options.size(); i++) {
    cout << i+1 << ". " << options[i].text << '\n';
  }
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
  scenes[id] = scene;
}

void Game::addOption(string sceneId, vector<Option> options) {
  for (int i = 0; i < options.size(); i++) {
    scenes[sceneId]->addOption(options[i].text, options[i].sceneId);
  }
}

void Game::start(string startSceneId) {
  currentScene = scenes[startSceneId];
}

void Game::setCurrentScene(string id) {
  currentScene = scenes[id];
}

void Game::printCurrentScene() {
  currentScene->printScene();
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

    if (choiceInt > 0 && choiceInt <= currentScene->getNumOptions()) {
      string nextSceneId = currentScene->chooseOption(choiceInt);
      setCurrentScene(nextSceneId);
      break;
    } else {
      cout << "Invalid choice." << '\n';
    }
  }
}

void Game::cleanUp() {
  for (auto it = scenes.begin(); it != scenes.end(); it++) {
    delete it->second;
  }
  scenes.clear();
  currentScene = NULL;
}

bool Game::gameEnded() {
  if (currentScene->getIsEndScene()) {
    cout << currentScene->getDialogue() << '\n';
    cleanUp();
    return true;
  }
  return false;
}

void Game::printAllScenes() {
  for (auto it = scenes.begin(); it != scenes.end(); it++) {
    cout << it->first << ": " << it->second->getDialogue() << '\n';
  }
}

void Game::runGame(string startSceneId) {
  start(startSceneId);
  while (!gameEnded()) { 
    printCurrentScene();
    askForChoice();
  }
}
