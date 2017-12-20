#include<iostream>

using namespace std;
int main(){
    int a = 5,b=5;
    double res =0;
    res = (a*1.5);
    cout << res;


    /*
    a=5
    test1 = static_cast<double>(a/2); >> results 2
    test1 = static_cast<double>(a)/2; >> results 2.5
    test1 = a+2.5 >> results 7.5
    test1 = (a+3.5)* (a/2)>> results 17
    test1 = (a+3.5)* (static_cast<double>(a)/2)>> results 21.25

    test1 = static_cast<double>(a)/2; >> results 2.5
    */
    return 0;
}
