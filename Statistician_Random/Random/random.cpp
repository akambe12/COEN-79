//
//  random.cpp
//  Statistician_Random
//
//  Created by Ethan Paek on 9/28/18.
//  Copyright © 2018 Ethan Paek. All rights reserved.
//
//  Documentation can be found in "random.hpp"

#include "random.hpp"
#include <iostream>

using namespace std;
using namespace coen79_lab2;

namespace coen79_lab2{
    rand_gen::rand_gen(int tmp_seed, int tmp_multiplier, int tmp_increment, int tmp_modulus){
        this->seed = tmp_seed;
        this->multiplier = tmp_multiplier;
        this->increment = tmp_increment;
        this->modulus = tmp_modulus;
    }
    
    void rand_gen::set_seed(int tmp_seed){
        seed = tmp_seed;
        return;
    }
    
    int rand_gen::next(){
        int new_seed;
        new_seed = (((multiplier * seed) + increment) % modulus);
	seed = new_seed;
        return new_seed;
    }
    
    int rand_gen::get_seed() const{
        return seed;
    }
    
    int rand_gen::get_multiplier() const{
        return multiplier;
    }
    
    int rand_gen::get_increment() const{
        return increment;
    }
    
    int rand_gen::get_modulus() const{
        return modulus;
    }
    
  void rand_gen::print_info() const{
        cout << "Seed: " << get_seed() << endl;
        cout << "Multiplier: " << get_multiplier() << endl;
        cout << "Increment: " << get_increment() << endl;
        cout << "Modulus: " << get_modulus() << endl;
    }
}
