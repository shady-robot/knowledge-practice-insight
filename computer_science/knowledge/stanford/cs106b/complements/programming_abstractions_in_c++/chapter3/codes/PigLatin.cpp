/*
 * File: PigLatin.cpp
 * ------------------
 * This program converts lines from English to Pig Latin.
 * This dialect of Pig Latin applies the following rules:
 * 
 * 1. If the word contains no vowels, no translation is done, which means that
 * the translated word is the same as the original.
 * 
 * 2. If the word begins with a vowel, the function adds the string "way" to
 * the end of the original word.
 * 
 * 3. If the word begins with a consonant, the function extracts the string of 
 * consonants up to the first vowel, moves that collection of consonants to the 
 * end of the word, and adds the string "ay".
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/* Function prototype */
string lineToPigLatin(string line);
string wordToPigLatin(string word);
int findFirstVowel(string word);
bool isVowel(char ch);

int main(){
  cout << "This program translates English to Pig Latin. " << endl;
  string line;

  cout << "Enter English text: ";

  getline(cin, line);

  string translation = lineToPigLatin(line);
  cout << "Pig Latin output: " << translation << endl;

  return 0;
}


string lineToPigLatin(string line){
  string result;
  int start = -1;
  // Separate line into words 
  for(int i = 0; i < line.length(); i++){
    char ch = line[i];
    if(isalpha(ch)){
      if(start == -1) start = i;
    }else{
      if(start >= 0){
        result += wordToPigLatin(line.substr(start, i - start));
        start = -1;
      }
      result += ch;
    }
  }
  if(start >= 0) result += wordToPigLatin(line.substr(start));

  return result;
}

string wordToPigLatin(string word){
  int vp = findFirstVowel(word);
  if(vp == -1){
    return word;
  } else if (vp == 0) {
    return word + "way";
  }else {
    string head = word.substr(0, vp);
    string tail = word.substr(vp);
    return tail + head + "ay";
  }
}

int findFirstVowel(string word){
  for(int i = 0; i < word.length(); i++){
    if(isVowel(word[i])) return i;
  }
  return -1;
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