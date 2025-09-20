#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <vector>
using namespace std;

 
void greet();
void display(int);\
void display_words(vector<char>, string);
bool exit_screen(int,string,vector<char>, string);
string getRandomWord(const string&);
bool seen(char, vector<char>);
bool seen(char,string);

#endif

