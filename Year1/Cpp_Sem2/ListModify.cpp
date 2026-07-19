#include <iostream>
#include <list>
#include <iostream>

using namespace std;

void foo (list<int>&l){

for (auto it = l.begin(); it != l.end(); it++){
    if(*it > 25){
        *it +=10;
        break;
    }

}
for (auto it = l.begin (); it != l.end(); it++){
    if(*it < 15){
        l.erase(it);
        break;
    }
}

}