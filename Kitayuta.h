
#ifndef Kitayuta_h
#define Kitayuta_h

// --------
// includes
// --------

#include <iostream>
#include <string>

using namespace std;

// ------------
// kitayuta_read
// ------------

/**
 * read a string
 * @param s a string
 * @return the input string
 */
std::string kitayuta_read (const string& s);

// ------------
// kitayuta_eval
// ------------

/**
 * @param s the input string
 * @return the answer
 */
std::string kitayuta_eval (const std::string& s);

// -------------
// kitayuta_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param out the answer
 */
void kitayuta_print (ostream& w, const std::string& out);

// -------------
// kitayuta_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void kitayuta_solve (istream& r, ostream& w);

#endif
