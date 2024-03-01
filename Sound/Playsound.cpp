#include "Playsound.h"


void Playsound::playsoundss(const std::string& sceneId) {
    if (sceneId == "1-2") {
        PlaySound(TEXT("Sound/Sounds/ALARMM"), NULL, SND_FILENAME | SND_ASYNC);
    }
}

void Playsound::StopPlay() {
    PlaySound(NULL, NULL, 0);
}

// int main(){
//     int  x;
//     Playsound::playsoundss("1-2");
//     std::cin >> x;
// }