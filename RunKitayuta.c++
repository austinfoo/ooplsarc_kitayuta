// -------------------------------
// projects/kitayuta/RunKitayuta.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout

#include "Kitayuta.h"

// ----
// main
// ----

int main () {
    using namespace std;
    kitayuta_solve(cin, cout);
    return 0;}

/*
% g++ -pedantic -std=c++11 -Wall Kitayuta.c++ RunKitayuta.c++ -o RunKitayuta



% cat RunKitayuta.in
1 10
100 200
201 210
900 1000



% RunKitayuta < RunKitayuta.in > RunKitayuta.out



% cat RunKitayuta.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/