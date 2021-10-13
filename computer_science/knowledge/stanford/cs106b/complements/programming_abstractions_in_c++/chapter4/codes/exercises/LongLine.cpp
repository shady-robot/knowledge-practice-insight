/*  File: LongLine.cpp
 * -------------------
 * Write a program that prints the longest line in a file chosen by the user. 
 * If several lines are all equally long, your program should print the first
 * such line.
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string promptUserForFile(ifstream & infile, string prompt="Choose file: ");

int main(){
  ifstream infile;

  promptUserForFile(infile);

  string line, longestLine;
  int maxLength = 0;
  while(getline(infile, line)){
      if(line.length() > maxLength){
        maxLength = line.length();
        longestLine = line;
      }
  }
  cout << "The longest line: " << longestLine << endl;
  infile.close();
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