#include "corefunc.h"
#include "print.h"
#include "scoreboard.h"
#include <iostream>
#include <cstring>
#include <chrono>
#include <random>
#include <thread>

void game(Pokemon* imposter, Pokemon pokemon[], int size);
int attempt=0, health=2, result=0;
using namespace std;

int menu()
    {
      attempt++;
      //take input
      int input=0;
      cout << "Health: " << health << "/2" << endl;
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

void CloseTheCase(Pokemon* imposter, Pokemon pokemon[], int size){
  int number;
  string username = "Guest";
  PrintOneTruth();
  this_thread::sleep_for(chrono::seconds(1));
  printpokemon(pokemon, size);
  cout << "The Imposter is (Input number): "; cin >> number; //Win game
     if (imposter == &pokemon[number - 1]) {
     cout << "\033[2J\033[1;1H";  
       result = 1;
       string attemptStr = to_string(attempt);
     cout << "Congratulations! You correctly identified the imposter." << endl;
       
     cout << "Please input your username: "; cin >> username;
     const string scoreboardFilename = "scoreboard.txt";
     updateScoreboard(username, attemptStr);
     printScoreboard(scoreboardFilename);
     } 
     else {
       result=0;
     cout << "Incorrect! The imposter is a different Pokémon." << endl;
     cout << "You lose 1 health!" << endl;
          //menu
       health--;
       if (health == 0){
         cout << "========================================" << endl;
           cout << "Health: " << health << "/2" << endl;
           cout << "========================================" << endl;
           this_thread::sleep_for(chrono::seconds(1));
           cout << "You Die!" << endl;
           this_thread::sleep_for(chrono::seconds(1));
           cout << "\033[2J\033[1;1H";
           PrintGameOver(); //Game Over
           this_thread::sleep_for(chrono::seconds(3));
       }
       else{
          if (menu() == 2) game(imposter, pokemon, size); //2 to game
          else CloseTheCase(imposter, pokemon, size); //1 to guess again
       }
     }
}

void game(Pokemon* imposter, Pokemon pokemon[], int size){

  for (int i = 0; i < 5; i++) {
    //if copy number correctly======================================
    if (randomquestion() == 1) {
      PrintCorrect();
      this_thread::sleep_for(chrono::seconds(1));
      randomizedhint(imposter); //print hint
      this_thread::sleep_for(chrono::seconds(2));
      printpokemon(pokemon, size);
          //menu
          if (menu() == 2){ continue; } //press 2 continue
          else { CloseTheCase(imposter, pokemon, size); } //press 1 to guess
    }
      
    //if copy number wrong==========================================
    else {
      health --;
      PrintIncorrect();
      this_thread::sleep_for(chrono::seconds(1));
      printpokemon(pokemon, size);
      if (health != 0){ //check if health is remaining
          //menu
          if (menu() == 2){continue; } //press 2 to play
          else {CloseTheCase(imposter, pokemon, size);} //press 1 to guess
      }  
      else{ //if health is zero
           cout << "========================================" << endl;
           cout << "Health: " << health << "/2" << endl;
           cout << "========================================" << endl;
           this_thread::sleep_for(chrono::seconds(1));
           cout << "You Die!" << endl;
           this_thread::sleep_for(chrono::seconds(1));
           cout << "\033[2J\033[1;1H";
           PrintGameOver(); //Game Over
           this_thread::sleep_for(chrono::seconds(3));
          }
      } break; //out of for loop
    } 

}

int main()
  {

  Pokemon pokemon[9];
  pokemon[0] = Pokemon("Pikachu", "Electric", "Yellow", 123);
  pokemon[1] = Pokemon("Charmander", "Fire", "Red", 789);
  pokemon[2] = Pokemon("Meowth", "Normal", "Yellow", 678);
  pokemon[3] = Pokemon("Margikarp", "Water", "Red", 789);
  pokemon[4] = Pokemon("Squirtle", "Water", "Blue", 123);
  pokemon[5] = Pokemon("Pichu", "Electric", "Yellow", 678);
  pokemon[6] = Pokemon("Snorlax", "Normal", "Blue", 789);
  pokemon[7] = Pokemon("Flareon", "Fire", "Red", 123);
  pokemon[8] = Pokemon("Lapras", "Water", "Blue",678);

  Pokemon* imposter = nullptr;
  // Who is the Imposter?
  int i;
  imposter = randomimposter(pokemon, 8); 
  
  Introduction();
  cout << "\033[2J\033[1;1H";
  printpokemon(pokemon, 9);   // Print Suspect list
  Rule();

  // Start Game
 game(imposter, pokemon, 9);
}

