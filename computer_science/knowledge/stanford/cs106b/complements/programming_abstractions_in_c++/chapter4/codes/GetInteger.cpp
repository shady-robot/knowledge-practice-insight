/*
 * Function: getInteger
 * Usage: int n = getInteger(prompt);
 * ----------------------------------
 * Requests an integer value from the user. The function begins by printing
 * the prompt string on the console and then waits for the user to enter
 * a line of input data. 
 * 
 * If that line contains a single integer, the function returns the
 * corresponding integer value. If the input is not a legal integer or if
 * extraneous characters appear on the input line, the implementation gives
 * the user a chance to reenter the value.
 */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int getInteger(string prompt="Enter an integer: ");

int main(){
  int directNum;
  cout << "Enter an integer: ";
  cin >> directNum;
  cout << "Your input: " << directNum << endl;

  // Ensure that user input is valid 
  int number = getInteger();
  cout << "Your input: " << number << endl;

  return 0;
}


int getInteger(string prompt){
  int value;
  string line;

  while(true){
    cout << prompt;
    getline(cin, line);
    istringstream stream(line);
    stream >> value >> ws;
    if(!stream.fail() && stream.eof()) break;
    cout << "Illegal integer format. Try again." << endl;
  }
  return value;
}