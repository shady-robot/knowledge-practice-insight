/* 
 * File: Countdown.cpp
 *--------------------
 * Write a program that prints out the calls for a spaceship that is about 
 * to launch. Countdown the numbers from 10 to 1 and then write "Liftoff"
 */

#include <iostream>
using namespace std;

int main() {
  /* TODO: Your code goes here! */
   cout << "Using a for loop syntax" << endl;
  for(int i=10; i>0; i--){
     cout << i << endl;
  }
  cout << "Liftoff" << endl;


  /* Using a while loop syntax */
  cout << "Using a while loop syntax" << endl;
  int timer = 10;
  while(timer > 0){
    cout << timer << endl;
    timer --;
  }
  cout << "Liftoff" << endl;
  return 0;
}