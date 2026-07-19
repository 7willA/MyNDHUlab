#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
  vector<double>areas;

int type;
while(cin >> type){
if (type==1){
    double a, b, c;
    cin>> a >> b >> c;
    Triangle t(a, b, c);
    areas.push_back(t.area());
    
}
else if (type ==2){
double x1,y1,x2,y2,x3,y3;
cin>> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
Triangle t(x1, y1, x2, y2, x3, y3);
areas.push_back(t.area());
}
}
sort(areas.begin(), areas.end());

    for (size_t i = 0; i < areas.size(); i++) {
        cout << areas[i] << endl;
    }
return 0;
}