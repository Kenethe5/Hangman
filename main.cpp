#include <iostream>
#include <vector>
#include <string>
#include "hangman_functions.h"
#include <limits>
using namespace std;
int main()
{
    greet();

    string codeword;
    int key;

    while (true)
    {
        // print out menu
        while (true)
        {
            cout << "Please select how to get codeword(enter 0 to quit):\n";
            cout << "1 - Randomly generated\n2 - Custom word\n-> ";

            if (!(cin >> key))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nERROR: Invalid input\n\n\n";
                continue;
            }

            if (key == 1)
            {
                codeword = getRandomWord("words.txt");
                break;
            }

            if (key == 2)
            {
                cin.ignore(100000000, '\n');
                cout << "Please enter your codeword: ";
                getline(cin, codeword);
                if (!codeword.empty())
                {
                    cout << endl;
                    break;
                }
                else
                {
                    cout << "\nERROR: Nothing entered!\n\n\n";
                    continue;
                }
            }
            if (key == 0)
            {
                cout << "You have quit the game.\n";
                return (0);
            }

            cout << "\nERROR: Invalid Input\nPlease try again.\n\n\n";
        }
        // reveal spaces and dashes
        string answer = codeword;
        for (int i = 0; i < codeword.length(); i++)
        {
            answer[i] = '_';
            if (codeword[i] == ' ' || codeword[i] == '-')
                answer[i] = codeword[i];
        }

        // initialize variables
        int misses = 0;
        bool guess = false;
        vector<char> incorrect;
        char letter;

        // loop checks for max misses and answer
        while (answer != codeword && misses < 6)
        {
            guess = false;
            display(misses);
            display_words(incorrect, answer);

            cout << "Enter a letter: ";
            cin >> letter;
            letter = tolower(letter);

            if (seen(letter, answer))
                cout << "Letter is already in answer!\n";
            else
            {
                for (int i = 0; i < codeword.length(); i++)
                {
                    if (letter == tolower(codeword[i]))
                    {
                        answer[i] = codeword[i];
                        guess = true;
                    }
                }

                if (guess)
                    cout << "You guessed correctly!\n";
                else if (seen(letter, incorrect))
                    cout << "Same incorrect guess!\n";
                else if (!guess)
                {
                    cout << "Incorrect guess!\n";
                    incorrect.push_back(letter);
                    misses++;
                }
            }
        }

        if (exit_screen(misses, codeword, incorrect, answer))
            continue;
        else
            break;
    }

    return 0;
}