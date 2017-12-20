#include<iostream>
#include "13_3_memberClass1.h"
using namespace std;
Student::Student(float n=0, int i=0){
    name = n;
    id = i;
}

void Student::display(){
    cout << name << endl;
    cout << id << endl;
}
