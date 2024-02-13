#include "dialogueMaker.h"

int main() {
  // Create scenes
  Game game;
  game.addScene(1, "You are in a forest. What do you do?");
  game.addScene(2, "You see a bear. What do you do?");
  game.addScene(3, "You see a river. What do you do?");
  game.addScene(4, "You died.");

  // Add options to scenes
  game.addOption(1, {{"Go left", 2}, {"Go right", 3}, {"Go straight", 4}});

  game.addOption(2, {
    {"Run", 1},
    {"Fight", 4}
  });

  game.addOption(3, {
    {"Swim", 4},
    {"Walk around", 1}
  });

  // Game loop
  game.start();
  while (!game.gameEnded()) {
    game.printCurrentScene();
    game.askForChoice();
  }
}
