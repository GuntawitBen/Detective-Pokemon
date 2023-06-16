#include "Pokemon.h"
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
using namespace std;
int count;

bool randomquestion() {
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(100, 999);
  int randomInteger = distribution(generator);
  cout << "\033[2J\033[1;1H";
  cout << "The imposter dropped the password!" << endl;
  this_thread::sleep_for(chrono::seconds(2));
  cout << "Password: " << randomInteger << std::endl;
  this_thread::sleep_for(chrono::seconds(3));
  cout << "\033[2J\033[1;1H";
  int userInput;
  cout << "Quickly copy the password!: ";
  cin >> userInput;
  if (userInput == randomInteger) {
    return 1;
  } else {
    return 0;
  }
}
Pokemon randomimposter(Pokemon pokemon[], int size) {
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(0, 7);
  int randomNumber = distribution(generator);
  cout << "Imposter Pokemon:" << pokemon[randomNumber].getName() << endl;
  return pokemon[randomNumber];
}
int attempt=0, health=2;
int menu(){

      attempt++;
      //take input
      int input=0;
      cout << "Health: " << health << "/5" << endl;
      cout << "Attempt: " << attempt << endl;
      cout << "Press 1 to guess"<<endl;
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
void printpokemon(Pokemon pokemon[], int size){

  for (int i = 0; i < size; i++) {
   cout << "Pokemon " << i + 1 << ":" << std::endl;
   cout << "Name: " << pokemon[i].getName() << std::endl;
   cout << "Type: " << pokemon[i].getType() << std::endl;
   cout << "Color: " << pokemon[i].getColor() << std::endl;
   cout << "Code: " << pokemon[i].getCode() << std::endl;
   cout << std::endl;
    }
}
int game(Pokemon imposter, Pokemon pokemon[], int size){

  
  for (int i = 0; i < 5; i++) {
   
    //if copy number correctly
    if (randomquestion() == 1) {
      cout << "\033[2J\033[1;1H";
      cout << "That is Correct!" << endl;
      this_thread::sleep_for(chrono::seconds(1));
      //function randomized hint
      cout << endl<< "HINT IS " << "CODE: " << imposter.getCode() << endl << endl;
      this_thread::sleep_for(chrono::seconds(2));
      printpokemon(pokemon, size);
      if (menu() == 2){
        //continue the loop
      }
      else if (menu() == 1){
        //function guess
      }
    }
    //if copy number wrong
    else {
    health --;
      cout << "\033[2J\033[1;1H";
    cout << "Incorrect! You lose health!" << endl;
      this_thread::sleep_for(chrono::seconds(1));
      printpokemon(pokemon, size);
    if (health != 0){
    if (menu() == 2){
      //continue the loop
      }
      else if (menu() == 1){
      //function guess
      }
    }
      else break;
    }
  
  }
  cout << "Health: " << health << "/5" << endl;
  cout << "You Die!" << endl;
  return 0;
}




int main() {

  //Announce Pokemon
  Pokemon pokemon[8];
  pokemon[0] = Pokemon("Pikachu", "Electric", "Yellow", 123);
  pokemon[1] = Pokemon("Charmander", "Fire", "Red", 789);
  pokemon[2] = Pokemon("Meowth", "Normal", "Yellow", 123);
  pokemon[3] = Pokemon("Margikarp", "Water", "Red", 789);
  pokemon[4] = Pokemon("Squirtal", "Water", "Blue", 789);
  pokemon[5] = Pokemon("Pichu", "Electric", "Yellow", 123);
  pokemon[6] = Pokemon("Snorlax", "Normal", "Blue", 789);
  pokemon[7] = Pokemon("Flareon", "Fire", "Red", 123);
    
  // Who is the Imposter?
  Pokemon imposter = randomimposter(pokemon, 8);

  // introduction
  char enter;
  cout << "[In The Middle Of The Night, At Pokemon Center...]" << endl;
  cout << "{Press Enter To Continue}" << endl;
  cin.get(enter);
  cout << "Charmander: Argghhhh!!! Helppp!! There is a dead body in the "
          "cafeteria!!"
       << endl;
  cout << "{Press Enter To Continue}" << endl;
  cin.get(enter);
  cout << "[You are the detective pokemon, now you have to investigate and "
          "find the killer]"
       << endl;
  cout << "{Press Enter To Continue}" << endl;
  cin.get(enter);
  cout << "Press [i] to view the list of all pokemons in the Pokemonn Center. "
       << endl;

  // Print Suspect list
  printpokemon(pokemon, 7);
  
  // Explain the Rule
  cout << "In order to win, you need to collect all the hints before the "
          "murderer kills you"
       << endl;
  cout << "{Press Enter To Continue}" << endl;
  cin.get(enter);
  cout << "To gain hints, you will be given a randomized numbers for 5 "
          "seconds, then you have to correctly plagiarize the numbers"
       << endl;
  cout << "{Press Enter To Continue}" << endl;
  cin.get(enter);
  cout << "Let's Start!!" << endl;
  this_thread::sleep_for(chrono::seconds(1));

  // Start Game
  game(imposter, pokemon, 7);
}
  