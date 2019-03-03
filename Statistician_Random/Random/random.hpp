//
//  random.hpp
//  Statistician_Random
//
//  Created by Ethan Paek on 9/28/18.
//  Copyright © 2018 Ethan Paek. All rights reserved.
//

#ifndef random_hpp
#define random_hpp

#include <stdio.h>

namespace coen79_lab2{
    class rand_gen{
    public:
        rand_gen(int tmp_seed, int tmp_multiplier, int tmp_increment, int tmp_modulus);//formula used to generate the next seed; requires all four parameters to be filled before execution and will set the seed, multiplier, increment, and modulus
        int next();//set the new seed according to the linear congruence method
        void set_seed(int tmp_seed);//changes the value of the current seed; requires an integer input before execution
        int get_seed() const;//need getters in order to access info to private variables for print function
        int get_multiplier() const;
        int get_increment() const;
        int get_modulus() const;
      void print_info() const;//print out the names of all private variables
    private:
        int seed;
        int multiplier;
        int increment;
        int modulus;
    };
}
#endif /* random_hpp */
