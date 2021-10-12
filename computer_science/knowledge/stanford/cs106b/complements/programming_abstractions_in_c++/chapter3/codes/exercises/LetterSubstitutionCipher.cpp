#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string letterCipherSubstitution(string cipher, string message);
string invertKey(string cipher, string encrypted);


int main(){
  string cipher, message;
  cout << "Letter substitution cipher." << endl;
  cout << "Enter a 26-letter key: ";
  getline(cin, cipher);

  cout << "Enter a message: ";
  getline(cin, message);
  
  string encrypted = letterCipherSubstitution(cipher, message);
  cout << "Encoded message: " << encrypted << endl;
  cout << "Origin message: " << invertKey(cipher, encrypted) << endl;
  
  return 0;
}

// Decimal Value for A is 65
// Refer to ASCII table 
// https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
string letterCipherSubstitution(string cipher, string message){
   string result;
   for(int i=0; i<=message.length(); i++){
    char letter = message[i];
    if(isalpha(letter)){
      int index = int(letter) - 65;
      result += cipher[index];
    }else{
      result += letter;
    }
  }
  return result;
}

// Using char() to convert ASCII 
string invertKey(string cipher, string encrypted){
   string result;
   for(int i=0; i<=encrypted.length(); i++){
    char letter = encrypted[i];
    if(isalpha(letter)){
      int index = cipher.find(letter);
      result += char(index+65);
    }else{
      result += letter;
    }
  }
  return result;
}