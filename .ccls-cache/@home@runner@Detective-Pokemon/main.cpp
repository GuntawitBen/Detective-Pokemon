#include "corefunc.h"
#include "print.h"
#include <iostream>
#include <cstring>
#include <chrono>
#include <random>
#include <thread>
using namespace std;


int attempt=0, health=2;
int menu(){

      attempt++;
      //take input
      int input=0;
      cout << "Health: " << health << "/5" << endl;
      cout << "Attempt: " << attempt << endl;
      cout << "Press 1 to close the case"<<endl;
      cout << "Press 2 to investigate more" << endl;
      cin >> input;
      if (input == 1) { //choose to guess
        return 1;
      }
      else if (input == 2){ //choose to investigate
        return 2;
      }
  return 0;
    } 

int CloseTheCase(Pokemon* imposter, Pokemon pokemon[], int size){
  int number;
  cout << "\033[2J\033[1;1H";
  cout << "==================================================" << endl;
  cout << "There is only one Truth!!"<<endl;
  cout << "==================================================" << endl;
  this_thread::sleep_for(chrono::seconds(1));
  printpokemon(pokemon, 8);
  cout << "The Imposter is: "; cin >> number;
   if (imposter == &pokemon[number - 1]) {
    cout << "Congratulations! You correctly identified the imposter." << endl;
     return 1;
  } else {
    cout << "Incorrect! The imposter is a different Pokémon." << endl;
     return 0;
  }
  }



int game(Pokemon* imposter, Pokemon pokemon[], int size){

  for (int i = 0; i < 5; i++) {
    //if copy number correctly
    if (randomquestion() == 1) {
     cout << "\033[2J\033[1;1H";
     cout << "==================================================" << endl;
     cout << "That is Correct!" << endl;
     cout << "==================================================" << endl;
      this_thread::sleep_for(chrono::seconds(1));
     randomizedhint(imposter);
      
      this_thread::sleep_for(chrono::seconds(2));
      printpokemon(pokemon, size);
      if (menu() == 2){
        continue;
      }
      else {
        //function guess
        CloseTheCase(imposter, pokemon, 7);
      }
    }
    //if copy number wrong
    else {
    health --;
     cout << "\033[2J\033[1;1H";
     cout << "==================================================" << endl;
     cout << "Incorrect! You lose health!" << endl;
     cout << "==================================================" << endl;
      this_thread::sleep_for(chrono::seconds(1));
      printpokemon(pokemon, size);
    if (health != 0){
    if (menu() == 2){
      continue;
      }
      else {
      //function guess
        CloseTheCase(imposter, pokemon, 7);
      }
    }
  }
  cout << "==================================================" << endl;
  cout << "Health: " << health << "/5" << endl;
  cout << "==================================================" << endl;
  cout << "You Die!" << endl;
  this_thread::sleep_for(chrono::seconds(2));
  cout << "\033[2J\033[1;1H";
  PrintGameOver();
  return 0;
}
}


int main(){ 

  Pokemon pokemon[8];
  pokemon[0] = Pokemon("Pikachu", "Electric", "Yellow", 123);
  pokemon[1] = Pokemon("Charmander", "Fire", "Red", 789);
  pokemon[2] = Pokemon("Meowth", "Normal", "Yellow", 123);
  pokemon[3] = Pokemon("Margikarp", "Water", "Red", 789);
  pokemon[4] = Pokemon("Squirtle", "Water", "Blue", 789);
  pokemon[5] = Pokemon("Pichu", "Electric", "Yellow", 123);
  pokemon[6] = Pokemon("Snorlax", "Normal", "Blue", 789);
  pokemon[7] = Pokemon("Flareon", "Fire", "Red", 123);

  Pokemon* imposter = nullptr;
  // Who is the Imposter?
  int i;
  imposter = randomimposter(pokemon, 7);  //FIXEDDD!!!
  cout << imposter->getName()<<endl; 
  
  Introduction();
  cout << "\033[2J\033[1;1H";
  printpokemon(pokemon, 8);   // Print Suspect list
  Rule();

  // Start Game
 game(imposter, pokemon, 8);

}
