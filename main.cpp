#include <iostream>
#include <vector>
#include <string>
#include "hangman_functions.h"
using namespace std;
/*VERSION 2 FEATURES
    -word guesses will be more forgiving, ignoring caps
    -randomly generate words derived from a file
    -fix bugs
*/
int main() {
    greet();
    
    string codeword;
    getline(cin, codeword);

    char answer[codeword.length() + 1];
    for(int i = 0; i < codeword.length(); i++)
        answer[i] = '_';
    answer[codeword.length()] = '\0';

    int misses = 0;
    bool guess = false; 
    vector<char> incorrect;
    char letter;
    while (answer != codeword && misses < 6) {
        display(misses);
        display_words(incorrect,answer);
        cout << "Enter a letter: ";
        cin >> letter;
        
        for(int i = 0; i < codeword.length(); i++) {
            if (letter == tolower(codeword[i]) ) {
                answer[i] = codeword[i];
                guess = true;
            }
        }
        if (guess) {
            cout << "You guessed correctly!\n";
        }
        else {
            cout << "Incorrect guess!\n";
            incorrect.push_back(letter);
            misses++;
    }
    guess = false;
    }
    exit_screen(misses, codeword, incorrect, answer);


    return 0;
}