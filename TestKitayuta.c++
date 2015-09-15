// --------------------------------
// projects/kitayuta/TestKitayuta.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Kitayuta.h"

using namespace std;

// -----------
// TestKitayuta
// -----------

// ----
// read
// ----

TEST(KitayutaFixture, read) {
    string s("1 10\n");
    const pair<int, int> p = kitayuta_read(s);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);}

// ----
// eval
// ----

TEST(KitayutaFixture, eval_1) {
    const int v = kitayuta_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(KitayutaFixture, eval_2) {
    const int v = kitayuta_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(KitayutaFixture, eval_3) {
    const int v = kitayuta_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(KitayutaFixture, eval_4) {
    const int v = kitayuta_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(KitayutaFixture, eval_5) {
    const int v = kitayuta_eval(1000, 900);
    ASSERT_EQ(174, v);}

TEST(KitayutaFixture, eval_6) {
    const int v = kitayuta_eval(1, 1);
    ASSERT_EQ(1, v);}

// -----
// print
// -----

TEST(KitayutaFixture, print) {
    ostringstream w;
    kitayuta_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(KitayutaFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n 1000 900\n 1 1\n");
    ostringstream w;
    kitayuta_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n1000 900 174\n1 1 1\n", w.str());}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Kitayuta.c++ TestKitayuta.c++ -o TestKitayuta -lgtest -lgtest_main -lpthread



% valgrind TestKitayuta                                         >  TestKitayuta.out 2>&1
% gcov -b Kitayuta.c++     | grep -A 5 "File 'Kitayuta.c++'"     >> TestKitayuta.out
% gcov -b TestKitayuta.c++ | grep -A 5 "File 'TestKitayuta.c++'" >> TestKitayuta.out



% cat TestKitayuta.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestKitayuta
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Kitayuta
[ RUN      ] Kitayuta.read
[       OK ] Kitayuta.read (31 ms)
[ RUN      ] Kitayuta.eval_1
[       OK ] Kitayuta.eval_1 (5 ms)
[ RUN      ] Kitayuta.eval_2
[       OK ] Kitayuta.eval_2 (3 ms)
[ RUN      ] Kitayuta.eval_3
[       OK ] Kitayuta.eval_3 (3 ms)
[ RUN      ] Kitayuta.eval_4
[       OK ] Kitayuta.eval_4 (3 ms)
[ RUN      ] Kitayuta.print
[       OK ] Kitayuta.print (17 ms)
[ RUN      ] Kitayuta.solve
[       OK ] Kitayuta.solve (10 ms)
[----------] 7 tests from Kitayuta (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Kitayuta.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Kitayuta.c++.gcov'
File 'TestKitayuta.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestKitayuta.c++.gcov'
*/
