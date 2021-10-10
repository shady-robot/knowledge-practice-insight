#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n);

int main(){
  for(int i=1; i<=100; i++){
    if(isPrime(i)){
       cout << i << endl;
    }
  }
  return 0;
}

bool isPrime(int n){

  // handling corner case when n is equal to 1 or 2
  if(n == 1) {
      return false;
  }
  if( n == 2) {
    return true;
  }
  
  // all even number are not prime
  if(n % 2 == 0){
    return false;
  }

  // start from 3 and increased by 2
  for(int i=3; i<=sqrt(n); i+=2){
    if(n%i == 0){
      return false;
    }
  }
  return true;
}
