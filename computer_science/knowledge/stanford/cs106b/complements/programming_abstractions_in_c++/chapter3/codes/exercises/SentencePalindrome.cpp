#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isSentencePalidrome(string sentence);

int main(){
  string line;
  cout << "This program tests for sentence palindromes." << endl;
  cout << "Indicate the end of the input with a blank line." << endl;

  while(true){
    cout << "Enter a sentence: ";
    getline(cin, line);
    if(line.length() == 0){
      break;
    }
    if(isSentencePalidrome(line)){
      cout << "That sentence is a palindrome." << endl;
    }else{
       cout << "That sentence is not a palindrome." << endl;
    }
  }
  return 0;
}

bool isSentencePalidrome(string sentence){
  string result;
  for(int i=0; i<sentence.length(); i++){
    if(isalpha(sentence[i])){
      result += toupper(sentence[i]);
    }
  }
  cout << result << endl;
  int length = result.length();
  for(int i=0; i<length/2; i++){
    if(result[i] != result[length-i-1]){
      return false;
    }
  }
  return true;
}