#include "dialogueMaker/dialogueMaker.h"

int main() {
  // Create scenes
  Game::addScene("begin", "You are in a forest. What do you do?");
  Game::addScene("2", "You see a bear. What do you do?");
  Game::addScene("3", "You see a river. What do you do?");
  Game::addScene("4", "You see a bridge. What do you do?");
  Game::addScene("bad_ending", "You died.", true);
  Game::addScene("nice_ending", "You survived.", true);

  // Add options to scenes
  Game::addOption("begin", {{"Go left", "2"}, {"Go right", "3"}, {"Go straight", "4"}});

  Game::addOption("2", {
    {"Run", "begin"},
    {"Fight", "bad_ending"}
  });

  Game::addOption("3", {
    {"Swim", "bad_ending"},
    {"Walk around", "begin"}
  });

  Game::addOption("4", {
    {"Cross it", "nice_ending"},
    {"Jump off", "bad_ending"}
  });

  // Game loop
  Game::runGame("begin");
}
