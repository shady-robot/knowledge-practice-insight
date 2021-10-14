/*
 * LetterCount.cpp
 * Copyright (C) 2021 shady <shady@MrRobot.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include "filelib.h"
#include "vector.h"

using namespace std;

/* Constant */
static const int COLUMNS = 7;

void letterCount(){
    Vector<int> letterCounts(26);
    ifstream infile;
    promptUserForFile(infile, "Input file: ");
    char ch;

    while(infile.get(ch)){
        if(isalpha(ch)){
            letterCounts[toupper(ch)-'A']++;
        }
    }
    infile.close();

    for(char ch='A'; ch <= 'Z'; ch++){
    cout << setw(COLUMNS) << letterCounts[ch-'A'] << " " << ch << endl;
    }
}


