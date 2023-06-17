#include <chrono>
#include <iostream>
#include <random>
#include <thread>
using namespace std;

void randomizedhint(){
  
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(1, 3);
  
}

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