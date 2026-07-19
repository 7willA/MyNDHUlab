#include <iostream>
#include <list>
using namespace std;
int main () {

list<int>my_liste;
  int num, x, y, n;
  
  for (int i = 0; i<5; i++){
  cin >> num;
    my_liste.push_back(num);
  }
   cin >> x >>y;
  my_liste.push_front(x);
  my_liste.push_back(y);
   
  cin>>n;
  my_liste.remove(n);
  
  for (int m : my_liste){
  cout << m <<" ";
  }
  return 0;
}