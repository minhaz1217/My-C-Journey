#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int caseCounter=1,n,p,match,maxMatch;
    double price,minPrice;
    string str, name,maxName;
    while(1){
        cin >> n >> p;
        maxMatch = INT_MIN;
        if( !(n&&p)){
            break;
        }
        getchar();
        while(n--){
            getline(cin,str);
        }
        while(p--){
            getline(cin,name);
            cin >> price >> match;
            if(match > maxMatch){
                maxMatch = match;
                maxName = name;
                minPrice = price;
            }else if(match == maxMatch && price < minPrice){
                minPrice = price;
                maxName = name;
            }
            getchar();
            while(match--){
                getline(cin,str);
            }
        }
            if(caseCounter >1){
                cout << endl;
            }
            cout << "RFP #"<<caseCounter++ << endl;
            cout << maxName << endl;
    }

    return 0;
}
