/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 25 / August / 2021
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define DEBUG 1
#define check(a) DEBUG==1?(cout << a << endl):null;
#define cc(a) DEBUG==1?(cout << a << endl):cout<<"";
#define msg(a,b) DEBUG==1?(cout << a << " : " << b << endl):cout<<"";
#define msg2(a,b,c) DEBUG==1?(cout << a << " : " << b << " : " << c << endl):cout<<"";
#define msg3(a,b,c,d) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << endl):cout<<"";
#define msg4(a,b,c,d,e) DEBUG==1?(cout << a << " : " << b << " : " << c << " : " << d << " : " << e << endl):cout<<"";
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
public:
    int getRealPart(string num){
        string str = num.substr(0, num.find("+"));
        stringstream ss(str);
        int a;
        ss >> a;
        return a;
    }
    int getImaginaryPart(string num){
        int plusPosition = num.find("+");
        string str = num.substr(plusPosition+1, num.size() - plusPosition - 2);
        stringstream ss(str);
        int a;
        ss >> a;
        return a;
    }

    string complexNumberMultiply(string num1, string num2) {
        int real1, real2, imaginary1, imaginary2, a, b, c;
        real1 = getRealPart(num1);
        real2 = getRealPart(num2);
        imaginary1 = getImaginaryPart(num1);
        imaginary2 = getImaginaryPart(num2);

        a = real1 * real2;
        b = real1 * imaginary2 + real2 * imaginary1;
        c = imaginary1 * imaginary2 * -1;
        // cout << a << " " << b << " " << c << endl;
        a = a + c;
        string str, temp;
        stringstream ss;
        ss << a;
        ss >> temp;
        str = temp + "+";
        ss.clear();
        ss << b;
        ss >> temp;
        str += temp + "i";

        return str;
    }
};
int main(){

    return 0;
}
