#include "Pokemon.h"
#include <chrono>
#include <iostream>
#include <random>
#include <thread>
using namespace std;

bool randomquestion() {
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(100, 999);
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
  cout << "=============== List of Suspects =================" << endl;
  for (int i = 0; i < size; i++) {
   cout << "Pokemon " << i + 1 << ":" << std::endl;
   cout << "Name: " << pokemon[i].getName() << endl;
   cout << "Type: " << pokemon[i].getType() << endl;
   cout << "Color: " << pokemon[i].getColor() << endl;
   cout << "Code: " << pokemon[i].getCode() << endl; 
   cout << endl;
    }
  cout << "==================================================" << endl;
}
int game(Pokemon imposter, Pokemon pokemon[], int size){

  for (int i = 0; i < 5; i++) {
    //if copy number correctly
    if (randomquestion() == 1) {
     cout << "\033[2J\033[1;1H";
     cout << "==================================================" << endl;
     cout << "That is Correct!" << endl;
     cout << "==================================================" << endl;
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
     cout << "==================================================" << endl;
     cout << "Incorrect! You lose health!" << endl;
     cout << "==================================================" << endl;
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
  cout << "==================================================" << endl;
  cout << "Health: " << health << "/5" << endl;
  cout << "==================================================" << endl;
  cout << "You Die!" << endl;
  this_thread::sleep_for(chrono::seconds(2));
  cout << "\033[2J\033[1;1H";
    cout << " ██████╗  █████╗  ██╗     ██╗███████╗  ██████╗  ██╗      ██╗███████╗███████╗ \n";
    cout << "██╔════╝ ██╔══██╗ ████╗  ███║██╔════╝██║     ██║██║      ██║██╔════╝██║   ██╗\n";
    cout << "██║  ███╗███████║ ██║ ██║ ██║███████╗██║     ██║ ██║    ██╔╝███████╗████████║\n"; 
    cout << "██║   ██║██╔══██║ ██║     ██║██╔════╝██║     ██║  ██║  ██╔╝ ██╔════╝██║  ██╔╝\n";
    cout << "╚██████╔╝██║  ██║ ██║     ██║███████║  ██████║      ████╔╝  ███████║██║   ██║\n"; 
    cout << " ╚═════╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝╚══════╝  ╚═════╝      ╚═══╝   ╚══════╝╚═╝   ╚═╝\n";

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
  cout << "==================================================" << endl;
  cout << " In The Middle Of The Night, At Pokemon Center... " << endl;
  cout << "================================= Press Enter ====" << endl; cin.get(enter);
  cout << "==== Charmander: =================================" << endl;
  cout << "\"Argghhhh!!! Helppp!! There is a dead body!!\"" << endl;
  cout << "================================= Press Enter ====" << endl; cin.get(enter);
  cout << "==== You: ========================================" << endl;
  cout << "\"Don't Worry! I'm the detective pokemon!\"" << endl;
  cout << "================================= Press Enter ====" << endl; cin.get(enter);
  cout << "==================================================" << endl;
  cout << "Press Enter to view the list of suspects" << endl;
  cout << "================================= Press Enter ====" << endl; cin.get(enter);
  
  // Print Suspect list
  cout << "\033[2J\033[1;1H";
  printpokemon(pokemon, 7);
  
  // Explain the Rule
  cout << "=============== Press Enter to View the Rules ====" << endl; cin.get(enter);
  cout << "\033[2J\033[1;1H";
  cout << "==== Rules (1/5) =================================" << endl;
  cout << "In order to win, you need to collect 5 passcodes" << endl << " before the imposter kills you" << endl;
  cout << "================================= Press Enter ====" << endl; cin.get(enter);
  cout << "==== Rules (2/5) =================================" << endl;
  cout << "Imposter will accidentally drop the passcode and " << endl << "you have to quickly plagiarize the codes" << endl;
  cout << "================================= Press Enter ====" << endl; cin.get(enter);
  cout << "==== Rules (3/5) =================================" << endl;
  cout << "If you copy the right code, you will gain one hint" << endl;
  cout << "================================= Press Enter ====" << endl; cin.get(enter);
  cout << "==== Rules (4/5) =================================" << endl;
  cout << "If you copy the wrong code, you will lose your " << endl << "health. You have 2 health."<< endl;
  cout << "================================= Press Enter ====" << endl; cin.get(enter);
  cout << "==== Rules (5/5) =================================" << endl;
  cout << "The more attempt you made, the lower score you" << endl << " will get" << endl;
  cout << "======================= Press Enter to Start! ====" << endl; cin.get(enter);
  cout << "Let's Start!!" << endl;
  this_thread::sleep_for(chrono::seconds(1));

  // Start Game
  game(imposter, pokemon, 7);
}
  