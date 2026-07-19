========================================================================
Lab of Algorithm - Assignment 9
Maximum Flow / Resource Matching - Edmonds-Karp
Student ID : 411321344
Name       : Wilkend AUGUSTE
========================================================================

------------------------------------------------------------------------
1. FILES
------------------------------------------------------------------------
main.cpp        C/C++ source code (Edmonds-Karp + matching modeling)
report.pdf      My report have (concepts, modeling, manual trace, analysis)
README.txt      This file
test_data/      Input test cases
output/         Program output for each test case

------------------------------------------------------------------------
2. HOW TO COMPILE
------------------------------------------------------------------------
A C++17 compiler is required (g++ recommended).

    g++ -O2 -std=c++17 -o maxflow main.cpp

------------------------------------------------------------------------
3. HOW TO RUN
------------------------------------------------------------------------
The program reads from a file given as an argument, or from stdin.

    ./maxflow test_data/basic_case.txt
    ./maxflow < test_data/basic_case.txt

To reproduce every output file:

    ./maxflow test_data/basic_case.txt              > output/basic_output.txt
    ./maxflow test_data/greedy_fail_case.txt        > output/greedy_fail_output.txt
    ./maxflow test_data/multi_capacity_case.txt     > output/multi_capacity_output.txt
    ./maxflow test_data/incomplete_matching_case.txt> output/incomplete_matching_output.txt

------------------------------------------------------------------------
4. INPUT FORMAT
------------------------------------------------------------------------
    Line 1                 : <numStudents> <numTasks>
    Next numStudents lines : <studentName> <studentCapacity> <k> <task_1> ... <task_k>
    Next numTasks  lines   : <taskName> <taskCapacity>

    studentCapacity = how many tasks the student may be assigned (basic = 1)
    k               = how many tasks the student can accept
    taskCapacity    = how many students the task may receive  (basic = 1)

Example (basic_case.txt):
    4 3
    A 1 2 T1 T2
    B 1 1 T1
    C 1 2 T2 T3
    D 1 1 T3
    T1 1
    T2 1
    T3 1

Node layout inside the program:
    node 0                       = source
    nodes 1..numStudents         = students
    nodes numStudents+1..        = tasks
    last node                    = sink
Edges:
    source  -> student : capacity = studentCapacity
    student -> task    : capacity = 1
    task    -> sink    : capacity = taskCapacity
The maximum flow value equals the maximum number of matches.

------------------------------------------------------------------------
5. OUTPUT FORMAT
------------------------------------------------------------------------
The program first prints every augmenting path it finds,
then the maximum matching number and one valid set of assignments, e.g.:

    Maximum Matching: 3
    Assignments:
      A -> T1
      C -> T2
      D -> T3

When several optimal matchings exist, any one with the maximum number
of matches is correct.

------------------------------------------------------------------------
6. TEST CASES
------------------------------------------------------------------------
basic_case.txt             Each student/task capacity 1. Expected max = 3.
greedy_fail_case.txt       A:{T1,T2}, B:{T1}. A naive in-order greedy that
                           gives T1 to A finds only 1 match; the optimum
                           (A->T2, B->T1) is 2. Expected max = 2.
multi_capacity_case.txt    Student B capacity 2, task T2 capacity 2.
                           Expected max = 4.
incomplete_matching_case.txt  3 students all want only T1 (capacity 1);
                           not everyone can be matched. Expected max = 1.
