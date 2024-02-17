#include <map>
#include <vector>
#include <string>
using namespace std;

class Scene;

struct Option {
  string text;
  string sceneId;
};

class Scene {
  string id;
  string dialogue;
  bool isEndScene;
  vector<Option> options;

  Scene(string id, string dialogue, bool isEndScene);

  void printScene(); 

  void addOption(string text, string nextSceneId);

  string chooseOption(int choice);

  string getId();

  string getDialogue();

  int getNumOptions();

  bool getIsEndScene();

  friend class Game;
};

class Game {
  static inline map<string, Scene*> scenes;
  static inline Scene* currentScene;

  static void setCurrentScene(string id);
  static void cleanUp();
  static void checkIfSceneExists(string id);
  static void askForChoice();
  static void start(string startSceneId);
  static bool gameEnded();
  static void printCurrentScene();

  public:
    static void addScene(string id, string dialogue, bool isEndScene=false);

    static void addOption(string sceneId, vector<Option> options);

    static void printAllScenes();

    static void runGame(string startSceneId);
};

