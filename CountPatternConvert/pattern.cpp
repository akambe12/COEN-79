//
//  pattern.cpp
//  Pattern
//
//  Created by Ethan Paek on 9/23/18.
//  Copyright © 2018 Ethan Paek. All rights reserved.
//
//  This program creates a pattern of consecutive numbers as demonstrated in Camino

#include "pattern.hpp" 
#include <iostream>
#include <stdio.h>
#include <iomanip>//necessary for setw()                                                      
#include <string>//necessary to declare strings 

using namespace std;

int main(){
  create_pattern();
  return 0;
}

void create_pattern(){
    string zero2nine = "0123456789";
    string nine2zero = "9876543210";
    cout << zero2nine << endl;
    int counter = 11;//this is the initial field width setting for the strings
    for(int i = 0; i < 4; i++){//http://www.c4learn.com/cplusplus/cpp-setw-setting-field-width/ link used to learn about setw()
        cout << setw(counter);//set the first field width
        cout << nine2zero;//display the first sequence in descending order
        cout << setw(counter + 6);//doubles the field width for the next sequence
        cout << zero2nine << endl;//display the second sequence in increasing order
        counter += 2;//increment the counter by 2
    }
    cout << setw(counter);//set the field width one last time
    cout << nine2zero << endl;//print the last sequence
}
