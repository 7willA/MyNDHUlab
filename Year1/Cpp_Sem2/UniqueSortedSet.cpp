#include <iostream>
#include <list>
#include <set>

using namespace std;

int main () {

    set<int, greater<int>> uniqueNumbers;
    int value; 
    while(cin >> value){
        uniqueNumbers.insert(value);
    }
list<int> numbers(uniqueNumbers.begin(), uniqueNumbers.end());

for(const auto& num : numbers) {
    cout<< num <<" ";
}

cout << endl;
return 0;

}