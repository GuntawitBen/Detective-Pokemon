#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include "Pokemon.h"
using namespace std;
int count;


bool randomquestion() {
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(10000000, 99999999);
  int randomInteger = distribution(generator);
    cout << "\033[2J\033[1;1H";
  cout<<"Here comes the number!"<<endl;
     this_thread::sleep_for(std::chrono::seconds(2));
  cout << "Random Integer: " << randomInteger << std::endl;
  this_thread::sleep_for(std::chrono::seconds(3));
  cout << "\033[2J\033[1;1H";
  int userInput;
  cout << "Enter the same number: ";
  cin >> userInput;
  if (userInput == randomInteger) {
        return 1;
    } else {
        return 0;
    }
}
Pokemon randomimposter(Pokemon pokemon[], int size){
  random_device rd;
  mt19937 generator(rd());
  uniform_int_distribution<int> distribution(0, 7);
  int randomNumber = distribution(generator);
  Pokemon imposter = pokemon[randomNumber];
  cout << "Imposter Pokemon:" << imposter.getName() << endl;
  return pokemon[randomNumber];
}

int main() {
  
  //Announce 10 Pokemon
   Pokemon pokemon[8];
    pokemon[0] = Pokemon("Pikachu","Electric","Yellow", 123);
    pokemon[1] = Pokemon("Charmander","Fire", "Red", 789);
    pokemon[2] = Pokemon("Meowth", "Normal", "Yellow", 911);
    pokemon[3] = Pokemon("Margikarp", "Water", "Red", 321);
    pokemon[4] = Pokemon("Squirtal", "Water", "Blue", 678);
    pokemon[5] = Pokemon("Pichu", "Electric", "Yellow", 875);
    pokemon[6] = Pokemon("Snorlax", "Normal", "Blue", 119);
    pokemon[7] = Pokemon("Flareon","Fire","Red",179);

  //Who is the Imposter?
  Pokemon imposter = randomimposter(pokemon, 8);
  
  //introduction
  char enter;
  cout << "[In The Middle Of The Night, At Pokemon Center...]" << endl;
  cout << "{Press Enter To Continue}"<< endl; cin.get(enter);
  cout << "Charmander: Argghhhh!!! helppp!! There is a dead body in the cafeteria!!"<< endl;
  cout << "{Press Enter To Continue}"<< endl; cin.get(enter);
  cout << "[You are the detective pokemon, now you have to investigate and find the killer]"<< endl;
  cout << "{Press Enter To Continue}"<< endl; cin.get(enter);
  cout << "Press [i] to view the list of all pokemons in the Pokemonn Center. "<< endl;
  

  //Print Suspect list
  Pokemon myPokemon;
  myPokemon.printall(pokemon, 8);
  

  //Explain the Rule
  cout << "In order to win, you need to collect all the hints before the murderer kills you"<<endl;
  cout << "{Press Enter To Continue}"<< endl; cin.get(enter);
  cout << "To gain hints, you will be given a randomized numbers for 5 seconds, then you have to correctly plagiarize the numbers"<<endl;
  cout << "{Press Enter To Continue}"<< endl; cin.get(enter);
    cout<< "Let's Start!!"<<endl;
        this_thread::sleep_for(std::chrono::seconds(1));

  //Firstquestion
for (int i=0; i<5; i++){
  if (randomquestion() == 1){
    cout<<"That is Correct!"<<endl;
    cout<<"Here is the hint, You only have 15 seconds to look through the list!"<<endl;
    cout<<imposter.getCode()<<endl;
    myPokemon.printall(pokemon, 8);
      this_thread::sleep_for(std::chrono::seconds(15));
    cout << "\033[2J\033[1;1H";
  }
  else{
    break;
  }
}
  cout<<"YOu Die!"<<endl;
}