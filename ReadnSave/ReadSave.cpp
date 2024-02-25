#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
 //reading txt file
  ifstream source;
  source.open("dialogue.txt");
  string textline;
  char format[]="%s"
  while(getline(source,textline)){
    sscanf(textline.c_str(),format);
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