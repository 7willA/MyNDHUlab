#include <iostream>
using namespace std;

int main(){
int n;
cout<<"Enter the size of the array: ";
 cin>>n;
int arr[n];
for (int i =0; i<=n; i++){
    cin>>arr[i];
}
int x;
cout<<"Enter the number of element you want too search: ";
cin>>x;

bool flag = false;
for(int i=0; i<=n-1; i++){
    if(arr[i]=x) flag = true;

    if(flag=true) cout<<"Element found";

    else cout<<"Element not found";
}

}