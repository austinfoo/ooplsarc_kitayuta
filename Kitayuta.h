
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
std::string kitayuta_read (const string& s);

// ------------
// kitayuta_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
std::string kitayuta_eval (const std::string& in);

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
void kitayuta_print (ostream& w, const std::string& in, const std::string& out);

// -------------
// kitayuta_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void kitayuta_solve (istream& r, ostream& w);

#endif
