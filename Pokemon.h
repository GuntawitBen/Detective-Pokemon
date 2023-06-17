#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#endif

class Pokemon {
  private:
    string Name;
    string Type;
    string Color;
    int Code;
  public:
    void setName(string name){
      Name = name;
    }
    string getName(){
      return Name;
    }
    void setType(string type){
      Type = type;
    }
    string getType(){
      return Type;
    }
    void setColor(string color){
      Color = color;
    }
    string getColor(){
      return Color;
    }
    void setCode(int code){
      Code = code;
    }
    int getCode(){
      return Code;
    }
    
    Pokemon() {
        Name = "";
        Type = "";
        Color = "";
        Code = 0;
    }
    
    Pokemon(string name, string type, string color, int code){
        Name = name;
        Type = type;
        Color = color;
        Code = code;
    }
};



