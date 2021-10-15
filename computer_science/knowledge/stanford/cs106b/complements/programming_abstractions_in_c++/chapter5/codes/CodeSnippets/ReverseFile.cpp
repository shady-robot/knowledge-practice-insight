#include <iostream>
#include <fstream>
#include <string>
#include "filelib.h"
#include "vector.h"
#include "codeSnippets.h"

using namespace std;


void reverseFile(){
    ifstream infile;
    Vector<string> lines;
    cout << "Reverser File "<< endl;
    promptUserForFile(infile, "Input file: ");
    readEntireFile(infile, lines);

    infile.close();
    for(int i=lines.size()-1; i>=0; i--){
        cout << lines[i] << endl;
    }
}

// function that define in "filelib.cpp"
// promptUserForFile(infile, "Input file: ");
// readEntireFile(infile, lines);

//void readEntireFile(istream & is, Vector<string> & lines){
//    string line;
//    while(getline(is, line)){
//        lines.add(line);
//    }
//}
