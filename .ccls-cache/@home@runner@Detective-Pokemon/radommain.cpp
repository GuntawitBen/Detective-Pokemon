#include <chrono>
#include <iostream>
#include <random>
#include <thread>

using namespace std;

class Pokemon {
  private:
    string Name;
    string Type;
    string Color;
    int Code;

void randomizedhint(){
  int i;
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(1, 3);
  switch ( uniform_int_distribution<int> distribution(1, 3))  {
    case 1:
        cout << endl<< "HINT IS " << "Color: " << imposter.getCode() << endl << endl;
        break;

    case 2:
        cout << endl<< "HINT IS " << "Type: " << imposter.getCode() << endl << endl;
        break;
    
    case 3:
        cout << endl<< "HINT IS " << "CODE: " << imposter.getCode() << endl << endl;
        break;
    default:
       

  }
 
  
}

