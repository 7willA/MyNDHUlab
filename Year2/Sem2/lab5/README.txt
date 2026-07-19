==============================================
  Lab Assignment 5 — Activity Selection Problem
  Student: Wilkend Auguste  |  ID: 411321344
==============================================

COMPILATION
-----------
  g++ -std=c++17 -o lab5 lab5.cpp

USAGE
-----
  ./lab5 <filename>        Read from file
  ./lab5 < <filename>      Pipe from file
  ./lab5                   Manual input 

INPUT FORMAT
------------
  n
  name start finish
  one activity per line

REPRODUCE ALL RESULTS
---------------------
  ./lab5 test_data/sample.txt
  ./lab5 test_data/custom.txt
  ./lab5 test_data/counterexample1.txt
  ./lab5 test_data/counterexample2.txt

FILES
-----
  lab5.cpp                     Source code
  Report_Lab5_Wilkend.docx     Written report 
  test_data/sample.txt         Sample from assignment 
  test_data/custom.txt         Self-designed test 
  test_data/counterexample1.txt  Defeats Earliest Start First
  test_data/counterexample2.txt  Defeats Shortest Duration First
  README.txt                   This file
