#include <chrono>
#include <iostream>
#include <random>
#include <thread>
using namespace std;
char enter;

void Introduction(){
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
}
void Rule(){
  cout << "=============== Press Enter to View the Rules ====" << endl; cin.get(enter);
  cout << "\033[2J\033[1;1H";
  cout << "==== Rules (1/5) =================================" << endl;
  cout << "In order to win, you need to collect the passcodes" << endl << " before the imposter kills you" << endl;
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
}
void PrintGameOver(){
    cout << " ██████╗  █████╗  ██╗     ██╗███████╗  ██████╗  ██╗      ██╗███████╗███████╗ \n";
    cout << "██╔════╝ ██╔══██╗ ████╗  ███║██╔════╝██║     ██║██║      ██║██╔════╝██║   ██╗\n";
    cout << "██║  ███╗███████║ ██║ ██║ ██║███████╗██║     ██║ ██║    ██╔╝███████╗████████║\n"; 
    cout << "██║   ██║██╔══██║ ██║     ██║██╔════╝██║     ██║  ██║  ██╔╝ ██╔════╝██║  ██╔╝\n";
    cout << "╚██████╔╝██║  ██║ ██║     ██║███████║  ██████║     ████╔╝   ███████║██║   ██║\n"; 
    cout << " ╚═════╝ ╚═╝  ╚═╝ ╚═╝     ╚═╝╚══════╝  ╚═════╝     ╚═══╝    ╚══════╝╚═╝   ╚═╝\n";
}
void PrintCorrect(){
    cout << "\033[2J\033[1;1H";
    cout << "==================================================" << endl;
    cout << "That is Correct!" << endl;
    cout << "==================================================" << endl;
}
void PrintIncorrect(){
      cout << "\033[2J\033[1;1H";
      cout << "==================================================" << endl;
      cout << "Incorrect! You lose health!" << endl;
      cout << "==================================================" << endl;
}
void PrintOneTruth(){
  cout << "\033[2J\033[1;1H";
  cout << "==================================================" << endl;
  cout << "There is only one Truth!!"<<endl;
  cout << "==================================================" << endl;
}