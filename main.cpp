#include "dialogueMaker/dialogueMaker.h"

int main() {
  // Create scenes
  Game game;
  game.addScene("begin", "You are in a forest. What do you do?");
  game.addScene("2", "You see a bear. What do you do?");
  game.addScene("3", "You see a river. What do you do?");
  game.addScene("end", "You died.");

  // Add options to scenes
  game.addOption("begin", {{"Go left", "2"}, {"Go right", "3"}, {"Go straight", "end"}});

  game.addOption("2", {
    {"Run", "begin"},
    {"Fight", "end"}
  });

  game.addOption("3", {
    {"Swim", "end"},
    {"Walk around", "begin"}
  });

  // Game loop
  game.start("begin");
  while (!game.gameEnded("end")) {
    game.printCurrentScene();
    game.askForChoice();
  }
}
