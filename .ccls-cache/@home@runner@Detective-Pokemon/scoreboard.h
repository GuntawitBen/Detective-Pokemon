#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Score {
  string username;
  string attempt;
};

void bubbleSort(Score scores[], int size) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i - 1; j++) {
      if (scores[j].attempt > scores[j + 1].attempt) {
        Score temp = scores[j];
        scores[j] = scores[j + 1];
        scores[j + 1] = temp;
      }
    }
  }
}

void storeScoreboard(Score scores[], int size, const string& filename) {
  ofstream outfile(filename);
  if (outfile.is_open()) {
    for (int i = 0; i < size; i++) {
      outfile << scores[i].username << " " << scores[i].attempt << endl;
    }
    outfile.close();
    cout << "Scoreboard data has been stored in " << filename << endl;
  } else {
    cout << "Unable to open the file " << filename << endl;
  }
}
void loadScoreboard(Score scores[], int size, const string& filename) {
  ifstream infile(filename);
  if (infile.is_open()) {
    for (int i = 0; i < size; ++i) {
      if (infile >> scores[i].username >> scores[i].attempt) {
      } else {

      }
    }
    infile.close();
  } else {
  }
}

void updateScoreboard(const string& username, string attempt) {
  const string scoreboardFilename = "scoreboard.txt";
  const int scoreboardSize = 5; // Maximum number of scores in the scoreboard

  Score scores[scoreboardSize];

  // Load existing scoreboard data into the scores array
    loadScoreboard(scores, scoreboardSize, scoreboardFilename);

  // Add the new score at the end of the array
  scores[scoreboardSize - 1].username = username;
  scores[scoreboardSize - 1].attempt = attempt;

  // Sort the scores array using bubble sort
  bubbleSort(scores, scoreboardSize);

  // Store the sorted scoreboard data in a file
  storeScoreboard(scores, scoreboardSize, scoreboardFilename);
}

void printScoreboard(const string& filename) {
  ifstream infile(filename);
  if (infile.is_open()) {
    cout << "Scoreboard:" << endl;
    string username;
    string attempt; 
    while (infile >> username >> attempt) {
      cout << "Username: " << username << ", Attempts: " << attempt << endl;
    }
    infile.close();
  } else {
    cout << "Unable to open the file " << filename << endl;
  }
}
