#include<iostream>
using namespace std;
struct Employee{
    int number;
    float compensation;
};
int main(){
    Employee e[3];
    int i;
    for(i=0;i<3;i++){
        cout <<  "Enter employee"<< i+1 << "'s number , compensation: ";
        cin >> e[i].number >> e[i].compensation;
    }
    for(i=0;i<3;i++){
        cout << "Employee" << i+1 << "'s number: " << e[i].number << ", Compensation: " << e[i].compensation << endl;
    }

	return 0;
}
