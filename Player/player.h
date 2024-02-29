
#include <iostream>
#include <windows.h>    // for SetConsoleCursorPosition
#include <fstream>      // for file streams
#include <string>       // for string manipulation
#include <sstream>      // for string stream
#include <vector>       // for storing lines of file

class player{
        double hp = 100;
        double hpmax = 100;
        double sanity = 100;
        double sanity_max = 100;
        std::string currentScene;
    public:
        bool CheckIfdied();
        void printstats();
        void changestat(const std::string& change);                                //use keyword "hp" or "sa" example: "hp-1"
        void SaveToFile(const std::string& filename);
        void LoadFromFile(const std::string& filename);
};

void movecursor(int,int);
int currentcursor(char);


// int main() {
//     player player1;
//     player1.LoadFromFile("Save.txt");
//     player1.printstats();

//     return 0;
// }
