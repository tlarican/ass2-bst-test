/**
 * Testing BST - Binary Search Tree functions
 *
 * This file has series of tests for BST
 * Each test is independent and uses assert statements
 * Test functions are of the form
 *
 *      test_netidXX()
 *
 * where netid is UW netid and XX is the test number starting from 01
 *
 * Test functions can only use the public functions from BST
 * testBSTAll() is called from main in main.cpp
 * testBSTAll calls all other functions
 * @author Multiple
 * @date ongoing
 */

#include <iostream>
#include <sstream>
#include <cassert>
#include <string>

#include "bst.hpp"

using namespace std;

/**
 * Trying to avoid global variables,
 * by creating a singleton class with our visitor functions
 * stringstream SS contains the output from visitor
 */
class TreeVisitor {
 public:
  TreeVisitor() = delete;

  // insert output to SS rather than cout, so we can test it
  static stringstream SS;

  static string GetSS() {
    return SS.str();
  }

  static void ResetSS() {
    SS.str(string());
  }
  // instead of cout, insert item into a string stream
  static void visitor(const string &item) {
    SS << item;
  }

  // instead of cout, insert item into a string stream
  static void visitor(const int &item) {
    SS << item;
  }
};

// initialize the static variable
stringstream TreeVisitor::SS;

/**
 * Test functions by Yusuf Pisan
 */

// Testing ==
void test_pisan01() {
  cout << "Starting test_pisan01" << endl;
  cout << "* Testing == and !=" << endl;
  BST<string> b1;
  BST<string> b2;
  BST<string> b3;
  // == and != for empty trees
  assert(b1 == b2 && (!(b1 != b2)));
  b1.Add("c");
  b2.Add("c");
  b3.Add("b");
  // == and !- for 1-node trees b1, b2, b3
  assert(b1 == b2 && (!(b1 != b2)));
  assert(b1 != b3 && (!(b1 == b3)));
  cout << "Ending test_pisan01" << endl;
}

// Testing == in detail
void test_pisan02() {
  cout << "Starting test_pisan02" << endl;
  cout << "* Testing == and != with more detail" << endl;
  BST<string> b1;
  BST<string> b2;
  BST<string> b3;
  b1.Add("c");
  b2.Add("c");
  b3.Add("b");
  b1.Add("a");
  b1.Add("f");
  b1.Add("g");
  b1.Add("x");
  b2.Add("a");
  b2.Add("f");
  b2.Add("g");
  b2.Add("x");
  // == for 5-node trees b1, b2
  assert(b1 == b2 && (!(b1 != b2)));

  BST<string> b4(b3);
  // copy constructor for 1-node trees b3, b4
  assert(b3 == b4 && (!(b3 != b4)));

  BST<string> b5(b1);
  // copy constructor for 5-node trees b1, b5
  assert(b1 == b5 && (!(b5 != b1)));

  BST<string> b7("b");
  // 1-param constructor for 1-node trees b3, b7
  assert(b3 == b7 && (!(b3 != b7)));

  cout << "Ending test_pisan02" << endl;
}

// Testing traversal
void test_pisan03() {
  cout << "Starting test_pisan03" << endl;
  cout << "* Testing traversal" << endl;
  BST<string> b1;
  BST<string> b2;
  BST<string> b3;
  b1.Add("c");
  b2.Add("c");
  b3.Add("b");
  b1.Add("a");
  b1.Add("f");
  b1.Add("g");
  b1.Add("x");
  b2.Add("a");
  b2.Add("f");
  b2.Add("g");
  b2.Add("x");

  TreeVisitor::ResetSS();
  b1.InorderTraverse(TreeVisitor::visitor);
  string result = "acfgx";
  assert(TreeVisitor::GetSS() == result);

  TreeVisitor::ResetSS();
  b1.PreorderTraverse(TreeVisitor::visitor);
  result = "cafgx";
  assert(TreeVisitor::GetSS() == result);

  TreeVisitor::ResetSS();
  b1.PostorderTraverse(TreeVisitor::visitor);
  result = "axgfc";
  assert(TreeVisitor::GetSS() == result);

  cout << "Ending test_pisan03" << endl;
}

/**
 * Test functions by Sample Sample
 */

// Testing samplefunctionality
void test_sample01() {
  cout << "Starting test_sample01" << endl;
  assert(true);
  cout << "Ending test_sample01" << endl;
}

// Calling all test functions
void testBSTAll() {
  test_pisan01();
  test_pisan02();
  test_pisan03();
  test_sample01();
}