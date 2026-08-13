#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    string name;
    string student_ID;
    int age;

void display(){
    cout<<"Name: "<<name<<"\n";
    cout<<"ID: "<<student_ID<<"\n";
    cout<<"Age: "<<age<<"\n";
}
};

int main(){

Student s;

cin>>s.name;
cin>>s.student_ID;
cin>>s.age;

s.display();

return 0;
}

