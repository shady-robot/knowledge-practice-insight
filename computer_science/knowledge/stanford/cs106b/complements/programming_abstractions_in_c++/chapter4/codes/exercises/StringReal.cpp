#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;

int stringToInteger(string str);
string integerToString(int n);

double stringToReal(string str);
string realToString(double n);

int main(){
  int variable = 1234;
  string sVariable = "1234";
  string rVariable = "12.34";
  double dVariable = 12.34; 
  cout << typeid(variable).name() << endl;
  cout << typeid(stringToInteger(sVariable)).name() << endl;

  cout << typeid(sVariable).name() << endl;
  cout << typeid(integerToString(variable)).name() << endl;

  cout << typeid(dVariable).name() << endl;
  cout << typeid(stringToReal(rVariable) ).name() << endl;

  cout << typeid(rVariable).name() << endl;
  cout << typeid(realToString(dVariable) ).name() << endl;

  cout << stringToInteger(sVariable) << endl;
  cout << realToString(dVariable) << endl;
  cout << stringToReal(rVariable) << endl;
  return 0;
}

int stringToInteger(string str) {
  istringstream stream(str);
  int value;
  stream >> value;
  if (stream.fail() || !stream.eof()) {
    cerr << "stringToInteger: Illegal integer format";
  }
  return value;
}

string integerToString(int n) {
  ostringstream stream;
  stream << n;
  return stream.str();
}


double stringToReal(string str){
  istringstream stream(str);
  double value;
  stream >> value;
  if (stream.fail() || !stream.eof()) {
    cerr << "stringToReal: Illegal real format";
  }
  return value;
}
string realToString(double n){
  ostringstream stream;
  stream << n;
  return stream.str();
}