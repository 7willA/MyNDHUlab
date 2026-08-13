#include <iostream>
using namespace std;

class Rectangle {
private:
        int weight;
        int height;

public:
    // Constructor to initialize the data
    Rectangle(int w, int h){
        weight = w;
        height = h;
    }
    // Method to display the area
    void display(){
        int area = weight * height;
        cout<<"Area: "<<area<<endl;
    }
};

int main (){
int w;
int h;
cin >> w >> h;
//create the object and pass the values
Rectangle react (w, h);

// display the result
react.display();

return 0;
}