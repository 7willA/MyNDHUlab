# MyNDHUlab

Coursework and lab assignments from my Computer Science studies at "National Dong Hwa University (NDHU)".
This repository collects the C and C++ programs I wrote across my freshman and sophomore years, plus my second‑year Algorithms labs.


## Repository structure

```
MyNDHUlab/
├── Year1/
│   ├── C_Sem1/      # Freshman – Semester 1: C programming
│   └── Cpp_Sem2/    # Freshman – Semester 2: C++ / Object-Oriented Programming
└── Year2/
    └── Sem2/        # Sophomore – Semester 2: Algorithms labs
```

---

## Year 1 — Semester 1: C programming (`Year1/C_Sem1`)

Fundamentals of C: input/output, control flow, arrays, strings, pointers, structs and recursion.
Files are named after what each program does. A few highlights:

- `ArabicToRoman.c` — convert Arabic numbers to Roman numerals
- `CollatzCycleLength.c` — Collatz conjecture cycle lengths
- `MazePathfinding.c` — recursive maze solving
- `MergeSort.c`, `CountInversions.c` — sorting and inversion counting
- `SpiralMatrix.c`, `SparseMatrix.c` — matrix problems
- `GomokuWinner.c`, `GoBoardCount.c` — board-game logic
- `PrimeFactorization.c`, `GoldbachPartitions.c` — number theory

## Year 1 — Semester 2: C++ / OOP (`Year1/Cpp_Sem2`)

Object-oriented programming in C++: classes, constructors, operator overloading,
inheritance, the STL (list, set, vector, map) and dynamic memory. Highlights:

- `FractionClass.cpp`, `FractionOperatorOverload.cpp` — a Fraction type with overloaded operators
- `TimeClass.cpp`, `DateClass.cpp`, `DateTimeInheritance.cpp` — date/time classes and inheritance
- `LibrarySystem.cpp`, `LibraryMember.cpp`, `BookClass.cpp` — a small library management system
- `HtmlElementParser.cpp`, `HtmlElementAttributes.cpp` — parsing HTML elements
- `MipsAssembler.cpp` — translating instructions to MIPS binary
- `DynamicContainer.cpp`, `ContainerClass.cpp` — dynamic array container

## Year 2 — Semester 2: Algorithms (`Year2/Sem2`)

Algorithm-analysis labs, each with source code, test data, results and a report:

- Searching & benchmarking
- Knapsack problems (0/1, fractional, unbounded)
- Graph algorithms: **BFS**, **Dijkstra**, **Bellman-Ford**, **Floyd-Warshall**, **A\***

---

## Languages & tools

- **C** and **C++**
- Compiled with **g++ / gcc**
- Python used in some Year 2 labs for charts and data generation

---

## How to compile

```bash
# C
gcc file.c -o program
./program

# C++
g++ file.cpp -o program
./program
```

---

*Author: Wilkend Auguste — National Dong Hwa University*
