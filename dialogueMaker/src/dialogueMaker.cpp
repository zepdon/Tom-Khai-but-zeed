#include <iostream>
#include "dialogueMaker.h"

Scene::Scene(int id, string dialogue) {
  this->id = id;
  this->dialogue = dialogue;
}

void Scene::printScene() {
  cout << dialogue << '\n';
  for (int i = 0; i < options.size(); i++) {
    cout << i+1 << ". " << options[i].text << '\n';
  }
}

void Scene::addOption(int choiceId, string text, int nextSceneId) {
  Option option;
  option.text = text;
  option.sceneId = nextSceneId-1;
  options.push_back(option);
}

int Scene::chooseOption(int choice) {
  return options[choice-1].sceneId;
}

int Scene::getId() {
  return id;
}

void Game::addScene(int id, string dialogue) {
  Scene* scene = new Scene(id, dialogue);
  scenes.push_back(scene);
}

void Game::addOption(int sceneId, vector<Option> options) {
  for (int i = 0; i < options.size(); i++) {
    scenes[sceneId-1]->addOption(i, options[i].text, options[i].sceneId);
  }
}

void Game::start() {
  currentScene = scenes[0];
}

void Game::setCurrentScene(int id) {
  currentScene = scenes[id];
}

void Game::printCurrentScene() {
  currentScene->printScene();
}

void Game::askForChoice() {
  int choice;
  cout << "Enter your choice: ";
  cin >> choice;
  setCurrentScene(currentScene->chooseOption(choice));
}

void Game::printEndGame() {
  cout << "Game over." << '\n';
}

bool Game::gameEnded() {
  if (currentScene->getId() == 4) {
    printEndGame();
    return true;
  }
  return false;
}
