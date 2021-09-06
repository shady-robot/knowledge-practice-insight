/*
 * File: ReverseDigits.cpp
 * -----------------------
 * Chapter1 exercise 8
 * This program reverses the digits in an integer
 * Using the digitSum function as model.
 */

#include <iostream>
using namespace std;

int digitSum(int n) {
  int sum = 0;
  while (n > 0) {
      sum += n % 10;
      n /= 10;
  }
  return sum; 
}

int reverseDigits(int n)
{
  int reverse = 0;
   while (n > 0) {
      reverse *= 10;
      reverse += n % 10;
      n /= 10;
  }
  return reverse; 
}
int main(){
  int target;
  cout << "This program reverses the digits in an integer." <<endl;
  cout << "Enter a positive integer: ";
  cin >> target;

  cout << "The reversed integer is: " << reverseDigits(target) << endl; 
  return 0;
}



