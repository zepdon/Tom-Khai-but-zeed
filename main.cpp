#include "dialogueMaker/dialogueMaker.h"

int main() {
  // Create scenes
  Game game;
  game.addScene("begin", "You are in a forest. What do you do?");
  game.addScene("2", "You see a bear. What do you do?");
  game.addScene("3", "You see a river. What do you do?");
  game.addScene("4", "You see a bridge. What do you do?");
  game.addScene("bad_ending", "You died.", true);
  game.addScene("nice_ending", "You survived.", true);

  // Add options to scenes
  game.addOption("begin", {{"Go left", "2"}, {"Go right", "3"}, {"Go straight", "4"}});

  game.addOption("2", {
    {"Run", "begin"},
    {"Fight", "bad_ending"}
  });

  game.addOption("3", {
    {"Swim", "bad_ending"},
    {"Walk around", "begin"}
  });

  game.addOption("4", {
    {"Cross it", "nice_ending"},
    {"Jump off", "bad_ending"}
  });

  // Game loop
  game.runGame("begin");
}
