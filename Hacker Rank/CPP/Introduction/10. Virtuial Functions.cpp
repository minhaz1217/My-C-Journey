#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int profId = 1;
int stuId = 1;
class Person{
    public:
    string name;
    int age;
    virtual void getdata(){}
    virtual void putdata(){}
};
class Professor:public Person{
    public:
    int cur_id;
    int publications;
    Professor(){
        cur_id = profId;
        profId++;
    }
    void getdata(){
        cin >> name >> age >> publications;
    }
    void putdata(){
        cout << name << " "<< age<< " " << publications<< " " << cur_id << endl;
    }
};

class Student: public Person{
    public:
    int marks[6],sum;
     int cur_id;
     Student(){
         cur_id = stuId;
         stuId++;
         sum = 0;
     }

    void getdata(){
        cin >> name >> age;
        for(int i=0;i<6;i++){
            cin >> marks[i];
            sum+=marks[i];
        }
    }
    void putdata(){
        cout << name<< " " << age<< " " << sum<< " " << cur_id << endl;
    }
};



int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
