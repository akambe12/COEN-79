//
//  counting_characters.cpp
//  Counting Characters
//
//  Created by ethan paek on 9/21/18.
//  Copyright © 2018 SCU. All rights reserved.
//
//  This program counts the number of alphanumeric characters and non-alphanumeric characters from the input

#include <string>
#include <iostream>
#include <stdio.h>
#include "counting_characters.hpp"

using namespace std;

int main(){
  cout << "Please input your phrase:" << endl;
  char input[100];
  cin.get(input, 100);
  count(input);
  return 0;
}

void count(char str[]){ //https://codereview.stackexchange.com/questions/97513/counting-words-letters-average-word-length-and-letter-frequency, source used to assist implementation
    int i = 0;
    int letters_numbers = 0;
    int punctuation = 0;
    while(str[i] != '\0'){
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9')){//count all numbers and letters
            letters_numbers++;//add one quantity to the alphanumberic total
        }
	else if(ispunct(str[i])){
            punctuation++;//add one quantity to the non-alhpanumeric total
        }
        i++;//move onto the next character in the char array
    }
    cout << str << " has " << letters_numbers << " alphanumeric characters and " << punctuation << " non-alphanumeric characters." << endl; //print out the information
}
