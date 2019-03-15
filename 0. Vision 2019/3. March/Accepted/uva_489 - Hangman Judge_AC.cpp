/*
Minhazul Hayat Khan
minhaz1217.github.io
EWU, Bangladesh
Problem Name:
Problem Link: https://vjudge.net/problem/UVA-489
Date : 15 / March / 2019
Comment: easy problem, had to read the problem carefully.
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;
#define msg3(a,b,c,d) cout << a << " : " << b << " : " << c << " : " << d << endl;
#define _INIT ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){
    string str1,str2;
    char arr[28];
    while(1){
        int n,counter, match,total;
        cin >> n;
        if(n == -1){
            break;
        }
        for(int i=0;i<28;i++){
            arr[i] = 0;
        }
        cin >> str1 >> str2;
        for(int i=0;i<str1.size();i++){
            arr[ str1[i]-'a'+1 ] = 1;
        }
        total = 0;
        for(int i=0;i<28;i++){
            if(arr[i] > 0){
                total++;
            }
        }
        counter = 0;
        match = 0;
        for(int i=0;i<str2.size();i++){
            if(arr[ str2[i]-'a'+1 ] == 1){
                match++;
                arr[ str2[i]-'a'+1 ] = 2;
            }else if(arr[ str2[i]-'a'+1] == 0){
                counter++;
                arr[ str2[i]-'a'+1 ] = 2;
                if(counter == 7){
                    break;
                }
            }
        }
        //msg3("SIZE", mp.size(), match, counter)
        cout << "Round " << n << endl;
        if(match >=total){
            cout <<"You win." << endl;
        }else if(counter>=7){
            cout << "You lose." << endl;
        }else{
            cout << "You chickened out." <<endl;
        }
    }
    return 0;
}
