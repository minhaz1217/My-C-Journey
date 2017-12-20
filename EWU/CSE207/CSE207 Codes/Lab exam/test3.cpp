//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int i,temp,half1 = 0, half2 = 0, n = 5000;
    for(int i=1;i<=n;i++){
        temp = rand() %n;
        if(temp > n/2){
            half2++;
        }else{
            half1++;
        }
        //cout << temp << endl;
    }
    cout << endl << endl;
    cout << half1 << endl << half2 << endl;
    cout << "Percentage" << endl;
    cout << (double)half1/n * 100 << endl << (double)half2/n *100 << endl;
}
