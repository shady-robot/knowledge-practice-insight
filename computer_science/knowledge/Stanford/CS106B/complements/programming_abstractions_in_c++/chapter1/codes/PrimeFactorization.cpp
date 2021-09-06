/*
 * File: PrimeFactorization.cpp
 * -----------------------
 * Chapter1 exercise 9
 * This program display the prime factorization of 
 * a number n.
 */

#include <iostream>
#include <math.h>
using namespace std;


// A function to print all prime factors of a given number n
void primeFactors(int n)
{
	while (n % 2 == 0)
	{
		cout << 2 << " * ";
		n = n/2;
	}

	// n must be odd at this point. So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n
		while (n % i == 0)
		{
			cout << i << " * ";
			n = n/i;
		}
	}

	//  When n is a prime number greater than 2
	if (n > 2){
    cout << n << endl;
  }
}


int main(){
  int target;
  cout << "This program factor a number." << endl;
  cout << "Enter number to be factored: ";
  cin >> target;
  primeFactors(target);
  return 0;
}