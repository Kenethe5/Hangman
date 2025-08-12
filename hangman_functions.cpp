#include <iostream>
#include <vector>
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