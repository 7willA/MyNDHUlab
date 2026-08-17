#include <iostream>
#include <vector>
using namespace std;

void display (vector <int> &a){
    for (int i = 0; i<a.size(); i++){
        cout<<a[i]<<" ";

    }
    cout<<endl;
}
void reverse_part(int i, int j, vector<int>&v){
    while(i<=j){
        int temp = v[i];
        v[i]=v[j];
        v[j]= temp;
        i++;
        j--;
    }
}

int main (){
    vector<int>v;
    int n;
    if(!(cin>>n)) return 0;
    v.resize(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int k;
    if(!(cin>>k)) k = 0;
    int sz = v.size();
    if(sz>0){
        k %= sz;
        if(k<0) k += sz;
        if(k!=0){
            reverse_part(0, sz-1, v);
            reverse_part(0, k-1, v);
            reverse_part(k, sz-1, v);
        }
    }
    display(v);
    return 0;
}