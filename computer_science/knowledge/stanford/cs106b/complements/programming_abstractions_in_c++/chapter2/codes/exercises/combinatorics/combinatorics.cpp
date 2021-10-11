#include <iostream>
#include <cstdlib>

#include "combinatorics.h"

// Private function prototype
int fact(int a, int b);


int permutations(int n, int k){
  return fact(n, k);
}

int combinations(int n, int k){
  int result = fact(n, k)/fact(k, k);
  return result;
}

int fact(int a, int b){
  int result = 1;
  for(int i = 0; i < b; i ++){
    result *= a;
    a --;
  }
  return result;
}
