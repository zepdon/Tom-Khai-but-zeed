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
  vector<Option> options;

  public:
    Scene(string id, string dialogue);

    void printScene(); 

    void addOption(string text, string nextSceneId);

    string chooseOption(int choice);

    string getId();

    string getDialogue();
};

class Game {
  map<string, Scene*> scenes;
  Scene* currentScene;

  void printEndGame();

  public:
    void addScene(string id, string dialogue);

    void addOption(string sceneId, vector<Option> options);

    void start(string startSceneId);
  
    void setCurrentScene(string id);

    void printCurrentScene();

    void askForChoice();

    bool gameEnded(string endSceneId);

    void cleanUp();

    void printAllScenes();
};

