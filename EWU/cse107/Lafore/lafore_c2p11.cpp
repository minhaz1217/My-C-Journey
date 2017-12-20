#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int a = 16, b= 12;

    cout << setiosflags(ios::left) << setw(a) << "Last Name" << setw(a) << "First Name" << setw(a) << "Street address" << setw(a) << "Town" << setw(a)<< "State"<< endl;
    cout << setw(a) << "Jones" << setw(a) << "Coleen" << setw(a) << "422 E. 99th AVE." << setw(a)<< "Bigcity"<< endl;

	return 0;
}
