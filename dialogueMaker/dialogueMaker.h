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

  public:
    Scene(string id, string dialogue, bool isEndScene);

    void printScene(); 

    void addOption(string text, string nextSceneId);

    string chooseOption(int choice);

    string getId();

    string getDialogue();

    int getNumOptions();

    bool getIsEndScene();
};

class Game {
  map<string, Scene*> scenes;
  Scene* currentScene;

  void setCurrentScene(string id);
  void cleanUp();
  void checkIfSceneExists(string id);

  public:
    void addScene(string id, string dialogue, bool isEndScene=false);

    void addOption(string sceneId, vector<Option> options);

    void start(string startSceneId);

    void printCurrentScene();

    void askForChoice();

    bool gameEnded();

    void printAllScenes();

    void runGame(string startSceneId);
};

