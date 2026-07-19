# Lab 6 - Weighted Activity Selection
411321344 Wilkend AUGUSTE

The source code is in the `src` folder, so go in there first.

## Compile

cd src
g++ -O2 -std=c++17 -o lab6 lab6.cpp

## Run
Input format:
n
name start finish value   (n lines)

MSYS2:
./lab6 ../data/example.txt example

Windows CMD:
lab6.exe ..\data\example.txt example


It prints the selected activities, total value, and running time for greedy,
brute force, and DP. (Brute force is skipped when n > 22.)
Expected output for example.txt: greedy = 220, brute force = 250, DP = 250.

## Reproduce all the results (MSYS2)

cd src
g++ -O2 -std=c++17 -o lab6 lab6.cpp
for f in example counterexample small_10 small_15 small_20 medium_50 medium_100 medium_200 large_500 large_1000 large_2000 ; do
    ./lab6 ../data/$f.txt $f
done
python make_charts.py

Results are saved to results.csv and the charts go into the results/ folder.
