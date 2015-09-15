// ----------------------------
// projects/kitayuta/Kitayuta.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <vector>

#include "Kitayuta.h"

using namespace std;

// ------------
// kitayuta_read
// ------------

pair<int, int> kitayuta_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// kitayuta_eval
// ------------

int kitayuta_eval (int i, int j)
{
  // Initialize variables
  int max_cycles = 0;
  
  // Setup cycles cache
  std::vector<int> cycles_cache (1000000, 0);
   
   // Tricky.  Make sure the inputs are ordered.
  if (i > j) std::swap(i, j);
  
  // Loop through the input range
  for (int k = i; k <= j; ++k) {
    int cycles = 1;
    int val = k;
      
    while (val != 1) 
    {
      // If val is in the cache then use the cached value and break out of the loop
      if (val < static_cast<int>(cycles_cache.size()) && cycles_cache[val]) {
        cycles += cycles_cache[val] - 1;
        break;
      }
      
      // Compute one iteration of Kitayuta
      if (val & 1) {
	    val = 3 * val + 1;
      } else {
	    val = val / 2;
      }
      ++cycles;
    }
    
    // Save the number of cycles in the cache
    cycles_cache[k] = cycles;
    
    // Save the cycles if it is the max we have seen so far
    max_cycles = std::max (max_cycles, cycles);
  }
  
  return max_cycles;
}

// -------------
// kitayuta_print
// -------------

void kitayuta_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// kitayuta_solve
// -------------

void kitayuta_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = kitayuta_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = kitayuta_eval(i, j);
        kitayuta_print(w, i, j, v);}}
