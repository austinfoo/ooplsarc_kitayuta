// --------------------------
// projects/kitayuta/Kitayuta.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Kitayuta_h
#define Kitayuta_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// kitayuta_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
pair<int, int> kitayuta_read (const string& s);

// ------------
// kitayuta_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int kitayuta_eval (int i, int j);

// -------------
// kitayuta_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void kitayuta_print (ostream& w, int i, int j, int v);

// -------------
// kitayuta_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void kitayuta_solve (istream& r, ostream& w);

#endif // Kitayuta_h
