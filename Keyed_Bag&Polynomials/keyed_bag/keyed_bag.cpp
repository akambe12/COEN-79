//
//  keyed_bag.cpp
//  Keyed Bag
//
//  Created by Ethan Paek on 10/12/18.
//  Copyright © 2018 Ethan Paek. All rights reserved.
//
//  Documentation can be found in "keyed_bag.h"

#include "keyed_bag.h"
#include <cassert>
#include <iostream>

using namespace std;
using namespace coen79_lab4;

namespace coen79_lab4{
  keyed_bag::keyed_bag(){
    used = 0;
  }

  void keyed_bag::erase(){
    for(int i = 0; i < size(); i++){
      keys[i] = '\0';
      data[i] = '\0';
    }
    used = 0;
    return;
  }

  bool keyed_bag::erase(const key_type& key){
    int index = -1;
    for(int i = 0; i < size(); i++){
      if(key == keys[i]){
	index = i;
	break;
      }
    }
    if(index != -1){
      for(int j = index; j < size(); j++){
	keys[j] = keys[j+1];
	data[j] = data[j+1];
      }
      used--;
      return true;
    }
    return false;
  }

  void keyed_bag::insert(const value_type& entry, const key_type& key){
    assert(size() < CAPACITY);
    bool same_key = false;
    for(int i = 0; i < size(); i++){
      if(key == keys[i]){
	  same_key = true;
	  break;
	}
    }
    if(same_key == false){
      keys[used] = key;
      data[used] = entry;
      used++;
    }
    return;
  }

  void keyed_bag::operator +=(const keyed_bag& addend){
    assert((size() + addend.size()) <= CAPACITY);
    bool same_key = hasDuplicateKey(addend);
    if(same_key == false){
      size_type k, size = addend.size();
      for(k = 0; k < size; k++){
	data[used] = addend.data[k];
	keys[used] = addend.keys[k];
	used++;
      }
    }
    return;
  }

  bool keyed_bag::has_key(const key_type& key) const{
    bool check = false;
    for(int i = 0; i < size(); i++){
      if(keys[i] == key){
	check = true;
	break;
      }
    }
    if(check == true){
      return true;
    }
    return false;
  }

  keyed_bag::value_type keyed_bag::get(const key_type& key) const{
    bool check_bag = has_key(key);
    assert(check_bag == true);
    int index;
    for(int i = 0; i < size(); i++){
      if(keys[i] == key){
        index = i;
	break;
      }
    }
    return data[index];
  }

  keyed_bag::size_type keyed_bag::size() const{
    return used;
  }

  keyed_bag::size_type keyed_bag::count(const value_type& target) const{
    size_type count = 0;
    for(int i = 0; i < size(); i++){
      if(target == data[i]){
	count++;
      }
    }
    return count;
  }

  bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const{
    bool same_key = false;
    for(int i = 0; i < size(); i++){
      for(int j = 0; j < otherBag.size(); j++){
        if(keys[i] == otherBag.keys[j]){
          same_key = true;
          break;
        }
      }
    }
    if(same_key == true){
      return true;
    }
    return false;
  }
  
  keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2){
    assert((b1.size() + b2.size()) <= keyed_bag::CAPACITY);
    keyed_bag temp;
    temp += b1;
    temp += b2;
    return temp;
  }
}
