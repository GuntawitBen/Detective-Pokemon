#include "Pokemon.h"
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
using namespace std;

void printpokemon(Pokemon pokemon[], int size){
  cout << "=============== List of Suspects =================" << endl;
  for (int j = 0; j < size; j++) {
   cout << "Pokemon " << j + 1 << ":" << endl;
   cout << "Name: " << pokemon[j].getName() << endl;
   cout << "Type: " << pokemon[j].getType() << endl;
   cout << "Color: " << pokemon[j].getColor() << endl;
   cout << "Code: " << pokemon[j].getCode() << endl; 
   cout << endl;
   cout << "==================================================" << endl;
    }
  }

// random imposter
Pokemon* randomimposter(Pokemon pokemon[], int size){
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(0, 7);
  int randomNumber = distribution(generator);
  cout << "Imposter Pokemon:" << pokemon[randomNumber].getName() << endl;
  return &pokemon[randomNumber];
}



//radom hint
void randomizedhint(Pokemon* imposter){
  int i;
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(1, 3);
  
  i = distribution(generator);
  switch (i)  {
    case 1:
        cout << endl<< "HINT IS " << "Color: " << imposter->getColor() << endl << endl;
        break;

    case 2:
        cout << endl<< "HINT IS " << "Type: " << imposter->getType() << endl << endl;
        break;
    
    case 3:
        cout << endl<< "HINT IS " << "CODE: " << imposter->getCode() << endl << endl;
        break;
    default:
      cout << "error pls restart."<<endl;
  
}
}

//randon question
bool randomquestion(){
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(100, 999); //range random number indicate how hard the game is
  int randomInteger = distribution(generator);
  cout << "\033[2J\033[1;1H";
  cout << "==================================================" << endl;
  cout << "The imposter dropped the password!" << endl;
  cout << "==================================================" << endl;
  this_thread::sleep_for(chrono::seconds(2));
  cout << "Password: " << randomInteger << endl;
  cout << "==================================================" << endl;
  this_thread::sleep_for(chrono::seconds(3));
  cout << "\033[2J\033[1;1H";
  int userInput;
  cout << "==================================================" << endl;
  cout << "Quickly! Copy the password!: ";
  cin >> userInput;
  if (userInput == randomInteger) {
    return 1;
  } else {
    return 0;
  }
}