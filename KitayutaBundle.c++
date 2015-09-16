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

#endif // Kitayuta_h
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



using namespace std;

// ------------
// kitayuta_read
// ------------

std::string kitayuta_read (const std::string& s) {
  std::istringstream sin(s);
  std::string in;
  sin >> in;
  return in;
}

// ------------
// kitayuta_eval
// ------------

bool is_palindrome (int b, int r, const std::string& str)
{
  while (b < r) {
    if (str[b] != str[r]) return false;
    ++b;
    --r;
  }
  return true;
}

std::string kitayuta_eval (const std::string& in)
{
  std::string str (in);
  int b = 0;
  int r = str.size() - 1;

  while (b < r)  {
    
    if (str[b] != str[r]) {
      // Can I insert a char from the back to the front
      if (is_palindrome(b, r-1, str)) {
	str.insert(str.begin()+b, str[r]);

      } 
      // Can I insert a char from the front to the back
      else if (is_palindrome(b+1, r, str)) {
	str.insert(str.begin()+r+1, str[b]);
      }
      else {
	str = "NA";
      }
      return str;
    }
   
    ++b;
    --r;
  }

  // The input was a palindrome.  If the string was odd, then b and r point to same char.
  // Insert *b in front of b to maintain the palindrome.  If the string was even, then b
  // is one past r.  Insert and char in front of b to maintain the palindrome.  
  str.insert(str.begin()+b, str[b]);
  return str;
}

// -------------
// kitayuta_print
// -------------

void kitayuta_print (ostream& w, const std::string& in, const std::string& out) {
  w << in << " " << out << std::endl;
}

// -------------
// kitayuta_solve
// -------------

void kitayuta_solve (istream& r, ostream& w) {
  std::string s;
  while (getline(r, s)) {
    const std::string in = kitayuta_read(s);
    const std::string out = kitayuta_eval(in);
    kitayuta_print(w, in, out);
  }
}
// -------------------------------
// projects/kitayuta/RunKitayuta.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout



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
