/*
 * File: SumOddInteger.cpp
 * -----------------------
 * Write a program that reads in a positive integer N and then calculates and 
 * displays the sum of the first N odd integers. For example, if N is 4, your 
 * program should display the value 16, which is 1 + 3 + 5 + 7.
 * 
 * chapter1: exercise-4
 */

#include <iostream>
using namespace std;

int main(){
  int sentinel;
  cout << "How many odd number you want to add? ";
  cin >> sentinel;
  int sum = 0;
  for(int i=0; i<sentinel; i++){
    sum += (i*2+1);
  }
  cout << "The number you enter is: " << sentinel << endl;
  cout << "The sum of odd number: " << sum << endl;
  return 0;
}