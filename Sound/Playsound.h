#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <string>
//#include "../dialogueMaker/dialogueMaker.h"

#pragma comment(lib, "winmm.lib")

class Playsound {
public:
    void   static playsoundss(const std::string& sceneId);
    void   static StopPlay();
};
