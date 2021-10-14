/*
 * File: RandomTextSub.cpp
 * -----------------------
 * Write a program that reads characters from an input file and displays them
 * on the console after making the appropriate random substitutions. Your
 * program should replace every uppercase character in the input by a random
 * uppercase character and every lowercase character by a random lowercase one.
 * Nonalphabetic characters should remain unchanged.
 */
#include <iostream>
#include <string>
#include <fstream>
#include "random.h"

using namespace std;
string promptUserForFile(ifstream & infile, string prompt="Input file: ");
char randomSubstitution(char ch);

int main(){
  string line;
  ifstream infile;
  cout << "Debug" << endl;
  promptUserForFile(infile);
  cout << "Debug" << endl;
  while(getline(infile, line)){
    string result = "";
    for(int i=0; i<=line.length(); i++){
      char ch = line[i];
      if(isalpha(ch)){
        result += randomSubstitution(ch);
      }else{
        result += line[i];
      }
    }
    cout << result << endl;
  }
  return 0;
}

string promptUserForFile(ifstream & infile, string prompt){
  string filename;
  while (true)
  {
    cout << prompt;
    getline(cin, filename);

    infile.open(filename.c_str());
    if(!infile.fail()) return filename;
    infile.clear();
    cout << "Unable to open that file. Try again. " << endl;
  }
}

/*
 * Rplace every uppercase character in the input by a random uppercase
 * character and every lowercase character by a random lowercase one.
 */
char randomSubstitution(char ch){
  int index = randomInteger(0, 26);
  if(islower(ch)) return char(97+index);
  if(isupper(ch)) return char(65+index);
  return ch;
}
