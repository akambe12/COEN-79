//
//  Gettysburg.cpp
//  Gettysburg
//
//  Created by Ethan Paek on 9/23/18.
//  Copyright © 2018 Ethan Paek. All rights reserved.
//
//This program converts all letters from lowercase to uppercase and displays all the words from an input file with a length of at least 10 characters. All punctuation marks are removed and do not contribute to the words' length. The name of the file is read in as a command line argument.

#include "Gettysburg.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <fstream>

using namespace std;

int main(int argc, char * argv[]) {
  if(argc != 2){//if there is more than one file or none at all, exit the program                   
    cout << "Invalid number of file(s)! Lo siento." << endl;
  }
  else{//there is exactly one file read in from the command line                                    
    replace(argv[1]);//pass the file name to the replace function                                 
  }
  return 0;
}

void replace(char* filename){//deletes all punctuation and changes every letter from lowercase to uppercase
  ifstream myfile(filename);//open the file
    if(!myfile.is_open()){//if the file cannot open, exit the program
        cout << "File could not be opened. Lo siento mi amigo (or amiga)." << endl;
    }
    string textstring;
    while(myfile >> textstring){//read in the file, word by word
	if(textstring.length() >= 10){//check if a word has 10 or more characters
	  for(int i = 0, len = textstring.size(); i < len; i++){//delete punctuation and change lowercase letters to uppercase
	    if(ispunct(textstring[i])){//https://stackoverflow.com/questions/19138983/c-remove-punctuation-from-string
	      textstring.erase(i--, 1);
	    }
	    else{
	      textstring[i] = toupper(textstring[i]);
	    }
	  }
	  if(textstring.length() >= 10){//after you remove punctuation, re-check if has 10 characters or more since .length() counts punctuation
	    cout << textstring << endl;
	  }
	}
      } 
    myfile.close();
}
