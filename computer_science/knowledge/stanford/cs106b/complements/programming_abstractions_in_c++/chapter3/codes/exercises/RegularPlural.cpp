/*
 *  Write a function createRegularPlural(word) that returns the plural of word 
 *  formed by following these standard English rules:
 *   
 *  a. If the word ends in s,x,z,ch, or sh, add es to the word.
 *  b. If the word ends in a y preceded by a consonant, change the y to ies.
 *  c. In all other cases, add just an s.
 *     
 * Write a test program and design a set of test cases to verify that your 
 * program works.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string createRegularPlural(string word);
bool isVowel(char ch);

int main(){
  string objects[6] = {"cat", "cup", "donkey", "lady", "fish", "stagecoach"};
  for(int i=0; i<6; i++){
    cout << objects[i] << ": " << createRegularPlural(objects[i]) << endl;
  }
  return 0;
}

string createRegularPlural(string word){

  char lastChar = word[word.length()-1];
  string substring = word.substr(word.length()-2);

  if(lastChar == 'y'){
    if(!isVowel(word[word.length()-2])){
      return word.substr(0, word.length()-1) + "ies";
    }
  }

  if(substring == "ch" || substring == "sh"){
      return word + "es";
  } 
  if(lastChar == 's' || lastChar == 'x' || lastChar == 'z'){
    return word + "es";
  }
  
  return word + "s";
}

bool isVowel(char ch){
  switch(ch){
    case 'A': case 'E': case 'I': case 'O': case 'U':
    case 'a': case 'e': case 'i': case 'o': case 'u':
      return true;
    default:
      return false;
  }
}