#include<iostream>
using namespace std;
struct Phone{
    int areaCode, extension, number;
};

int main(){
    Phone p1, p2;
    p1 = { 306, 200, 8989};
    cout << "Enter area code , extension and number: ";
    cin >> p2.areaCode >> p2.extension >> p2.number;
    cout << "My Number is: (" << p1.areaCode << ") " << p1.extension << "-"<< p1.number << endl;
    cout << "Your Number is: (" << p2.areaCode << ") " << p2.extension << "-"<< p2.number << endl;
    return 0;
}
