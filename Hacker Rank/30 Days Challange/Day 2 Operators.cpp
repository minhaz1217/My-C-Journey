#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double meal,tip,tax;
    double total;
    cin >> meal >> tip >> tax;
    total = meal + (meal * tip/100) + (meal * tax/100);
    cout << "The total meal cost is " << round(total) << " dollars." << endl;


    return 0;
}
