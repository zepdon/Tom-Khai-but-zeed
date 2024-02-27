#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
 //reading txt file
  ifstream source;
  source.open("dialogue.txt");
  string textline;
  char format[]="%s";
  char id[10];
  char dialogue[300];
  while(getline(source,textline)){
    sscanf(textline.c_str(),format,id,dialogue);
  }

  //savepoint?
  ofstream dialogue;//open dialog?
  dialogue.open("dialogue.txt");
  dialogue.close();
  cin.get();

  ifstream source;
  source.open("dialogue.txt");
  string textline;
  while(getline(source, textline)){
    cout<<textline;
  }
}