#include <iostream>
#include "combinatorics.h"

int main(){
  int k = 5;
  int n = 52;

  printf("C(%d, %d) = %d\n", n, k, combinations(n, k));
  printf("P(%d, %d) = %d\n", n, k, permutations(n, k));

  return 0;
}
