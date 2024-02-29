#include "player.h"
#include <iostream>

void movecursor(int x_position=0,int y_postion=0){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);        // Get handle to console output
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);              // Get CurrentCursor
    COORD screen = csbi.dwCursorPosition;

    screen.X += x_position;
    screen.Y += y_postion;
    SetConsoleCursorPosition(hConsole, screen);               // move Cursor
}

int currentcursor(char position){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);        // Get handle to console output
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hConsole, &csbi);              // Get CurrentCursor
    COORD screen = csbi.dwCursorPosition;

    if(position == 'x') return screen.X;
    else if(position == 'y') return screen.Y;
    else return 0;
}



void player::printstats(){
    double percent_hp = hp/hpmax;
    double percent_sa = sanity/sanity_max;
    int bar1 = 176; int bar2 = 219;
    
    SetConsoleCP(437);         // for bar text
    SetConsoleOutputCP(43);

    int tempX = currentcursor('x');      // Get Current position for pirnt Sanity bar

    //printHP
    movecursor(20);
    std::cout << "HP: ";
    for(int i=0; i<20; i++){
        std::cout << char(bar1);
    }
    movecursor(-20);
    for(int i=0; i<percent_hp*20; i++){
        std::cout << char(bar2);
    }

    std::cout<<"\r";                   // move cursor back to start
    //printSanity

    movecursor(tempX+50);
    std::cout << "SA: ";
    for(int i=0; i<20; i++){
        std::cout << char(bar1);
    }
    movecursor(-20);
    for(int i=0; i<percent_sa*20; i++){
        std::cout << char(bar2);
    }

    std::cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------\n";
}

void player::changestat(const std::string& change) {
    char text[50];
    double amount;
    char operation;

    sscanf(change.c_str(), "%[^-+ ] %c %lf", text, &operation, &amount);
    std::string stat = text;
    // Check the operation
    if (operation == '-') {               // Decrease the stat
        if (stat == "hp") {
            hp -= amount;
            if(hp<0) hp = 0;
            
        } else if (stat == "sa") {
            sanity -= amount;
            if(sanity<0) sanity = 0;
        }

        
    } else if (operation == '+') {        // Increase the stat
        if (stat == "hp") {
            hp += amount;
            if(hp>hpmax) hp = hpmax;

        } else if (stat == "sa") {
            sanity += amount;
            if(sanity>sanity_max) sanity = sanity_max;
        }
    }
}


bool player::CheckIfdied(){
    if(hp == 0 || sanity == 0){
        return true;
    }else return false;
}


void player::SaveToFile(const std::string& filename) {
    std::ofstream outFile(filename);                     // Open the file for writing
    if (outFile.is_open()) {
        // Write player stats to the file
        outFile << "HP: " << hp << "/" << hpmax << std::endl;
        outFile << "Sanity: " << sanity << "/" << sanity_max << std::endl;
        std::cout << "Player data saved to " << filename << std::endl;
        outFile.close(); // Close the file
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}


void player::LoadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);                   // Open the file for reading
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string key;
            if (iss >> key) {
                if (key == "HP:") {
                    iss >> hp;                        // set hp from file to current hp
                } else if (key == "Sanity:") {
                    iss >> sanity;                    // set sanity from file to current sanity
                }
            }
        }
        std::cout << "Player data loaded from " << filename << std::endl;
        inFile.close(); // Close the file
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
