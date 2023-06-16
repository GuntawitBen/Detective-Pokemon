#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

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
 void printall(Pokemon pokemon[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Pokemon " << i + 1 << ":" << std::endl;
        std::cout << "Name: " << pokemon[i].getName() << std::endl;
        std::cout << "Type: " << pokemon[i].getType() << std::endl;
        std::cout << "Color: " << pokemon[i].getColor() << std::endl;
        std::cout << "Code: " << pokemon[i].getCode() << std::endl;
        std::cout << std::endl;
    }
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

