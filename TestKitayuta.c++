
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

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
    string s ("abcdefg\n");
    const string v = kitayuta_read(s);
    EXPECT_EQ("abcdefg", v);}

// ----
// eval
// ----

TEST(KitayutaFixture, eval_1) {
    const string v = kitayuta_eval("a");
    EXPECT_EQ("aa", v);}

TEST(KitayutaFixture, eval_2) {
    const string v = kitayuta_eval("aa");
    EXPECT_EQ("aaa", v);}

TEST(KitayutaFixture, eval_3) {
    const string v = kitayuta_eval("aaa");
    EXPECT_EQ("aaaa", v);}

TEST(KitayutaFixture, eval_4) {
    const string v = kitayuta_eval("aba");
    EXPECT_EQ("abba", v);}

TEST(KitayutaFixture, eval_5) {
    const string v = kitayuta_eval("abba");
    EXPECT_EQ("abbba", v);}

TEST(KitayutaFixture, eval_6) {
    const string v = kitayuta_eval("abc");
    EXPECT_EQ("NA", v);}

TEST(KitayutaFixture, eval_7) {
    const string v = kitayuta_eval("abab");
    EXPECT_EQ("babab", v);}

// -----
// print
// -----

TEST(KitayutaFixture, print) {
    ostringstream w;
    kitayuta_print(w, "abab", "babab");
    EXPECT_EQ("abab babab\n", w.str());}

// -----
// solve
// -----

TEST(KitayutaFixture, solve) {
    istringstream r("a\naa\naaa\naba\nabba\nabc\nabab\n");
    ostringstream w;
    kitayuta_solve(r, w);
    EXPECT_EQ("a aa\naa aaa\naaa aaaa\naba abba\nabba abbba\nabc NA\nabab babab\n", w.str());}

