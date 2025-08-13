#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "hangman_functions.h"
using namespace std;

void greet() {
    cout << "==================================================\n";
    cout << "Welcome to hangman!\n";
    cout << "Guess the code word before your friend is hung to death!\n";
    cout << "===================================================\n";
    cout << "Please enter a codeword to guess: ";
}

void display(int m) {
    if (m == 0) {
        cout << "_________________________\n";
        cout << "|         ______         |\n";
        cout << "|         |    |         |\n";
        cout << "|              |         |\n";
        cout << "|              |         |\n";
        cout << "|            __|___      |\n";
        cout << "|________________________|\n";
        cout << "|                        |\n";
        cout << "| misses: " << m << "              |\n";
        cout << "|________________________|\n";
    }
    else if (m == 1) {
        cout << "_________________________\n";
        cout << "|         ______         |\n";
        cout << "|         |    |         |\n";
        cout << "|         O    |         |\n";
        cout << "|              |         |\n";
        cout << "|            __|___      |\n";
        cout << "|________________________|\n";
        cout << "|                        |\n";
        cout << "| misses: " << m << "              |\n";
        cout << "|________________________|\n";
    }
    else if (m == 2) {
        cout << "_________________________\n";
        cout << "|         ______         |\n";
        cout << "|         |    |         |\n";
        cout << "|         O    |         |\n";
        cout << "|         |    |         |\n";
        cout << "|            __|___      |\n";
        cout << "|________________________|\n";
        cout << "|                        |\n";
        cout << "| misses: " << m << "              |\n";
        cout << "|________________________|\n";
    }
    else if (m == 3) {
        cout << "_________________________\n";
        cout << "|         ______         |\n";
        cout << "|         |    |         |\n";
        cout << "|         O    |         |\n";
        cout << "|         |/   |         |\n";
        cout << "|            __|___      |\n";
        cout << "|________________________|\n";
        cout << "|                        |\n";
        cout << "| misses: " << m << "              |\n";
        cout << "|________________________|\n";
    }
    else if (m == 4) {
        cout << "_________________________\n";
        cout << "|         ______         |\n";
        cout << "|         |    |         |\n";
        cout << "|         O    |         |\n";
        cout << "|        \\|/   |         |\n";
        cout << "|            __|___      |\n";
        cout << "|________________________|\n";
        cout << "|                        |\n";
        cout << "| misses: " << m << "              |\n";
        cout << "|________________________|\n";
    }
    else if (m == 5) {
        cout << "_________________________\n";
        cout << "|         ______         |\n";
        cout << "|         |    |         |\n";
        cout << "|         O    |         |\n";
        cout << "|        \\|/   |         |\n";
        cout << "|          \\ __|___      |\n";
        cout << "|________________________|\n";
        cout << "|                        |\n";
        cout << "| misses: " << m << "              |\n";
        cout << "|________________________|\n";
    }
    else if (m == 6) {
        cout << "_________________________\n";
        cout << "|         ______         |\n";
        cout << "|         |    |         |\n";
        cout << "|         O    |         |\n";
        cout << "|        \\|/   |         |\n";
        cout << "|        /\\  __|___      |\n";
        cout << "|________________________|\n";
        cout << "|                        |\n";
        cout << "| misses: " << m << "              |\n";
        cout << "|________________________|\n";
    }
}

void display_words(vector<char> incorrect, string ans) {
    for(int i = 0; i < incorrect.size(); i++)
        cout << incorrect[i] << " ";
    cout << endl;
    cout << "Answer: " << ans << endl;
    
}

void exit_screen(int misses, string codeword, vector<char> incorrect, string ans) {
    if (misses < 6) {
        display(misses);
        display_words(incorrect,ans);
        cout << "\nCongratulations! You have guessed the word!\n";
    }
    else {
        display(misses);
        display_words(incorrect,ans);
        cout << "\nYou lost! Your friend has been hung!\nThe codeword was " << codeword << endl;
    }
    cout << "\n=============================================\n";
}

string getRandomWord(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "ERROR: File not found!\n";
        exit(1);
    }
    vector<string> words;
    string word;

    while(getline(file,word)) {
        words.push_back(word);
    }
    if(words.empty()) {
        cout << "ERROR: File is empty!\n";
        exit(1);
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    int ran_index = rand() % words.size();
    file.close();

    return words[ran_index];
}

bool seen(char letter, vector<char> incorrect) {
    for (int i = 0; i < incorrect.size(); i++) {
        if (letter == incorrect[i])
            return true;
    }
    return false;
}

bool seen(char letter, string answer) {
    for (int i = 0; i < answer.size(); i++) {
        if (letter == answer[i])
            return true;
    }
    return false;
}