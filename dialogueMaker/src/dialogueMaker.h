#include <vector>
#include <string>
using namespace std;

class Scene;

struct Option {
  string text;
  int sceneId;
};

class Scene {
  int id;
  string dialogue;
  vector<Option> options;

  public:
    Scene(int id, string dialogue);

    void printScene(); 

    void addOption(int choiceId, string text, int nextSceneId);

    int chooseOption(int choice);

    int getId();
};

class Game {
  vector<Scene*> scenes;
  Scene* currentScene;

  void printEndGame();

  public:
    void addScene(int id, string dialogue);

    void addOption(int sceneId, vector<Option> options);

    void start();
  
    void setCurrentScene(int id);

    void printCurrentScene();

    void askForChoice();

    bool gameEnded();

    void cleanUp();
};

