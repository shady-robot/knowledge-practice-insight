/*
 * VectorDemo.cpp
 * Copyright (C) 2021 shady <shady@MrRobot.local>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include "vector.h"
#include "codeSnippets.h"

using namespace std;

void vectorDemo(){
    Vector<int> vec;
    vec.add(10);
    vec.add(20);
    vec.add(30);
    vec.add(50);

    vec.insert(3, 40);
    vec.add(60);
    // 10 20 30 40 50 60

    vec.remove(4);
    // after remove: 10 20 30 40 60

    // change index 4 from 60 to 50
    vec.set(4, 50);

    for(int i=0; i<vec.size(); i++){
        cout << vec[i] << " ";
    }
}




