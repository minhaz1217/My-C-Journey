//http://acm.hust.edu.cn/vjudge/contest/view.action?cid=119841#problem/B
// if only int a,b; it doesn't work, the verdict is wa.
#include <iostream>
#include <cstdlib>

using namespace std;

int main ()
{
    long long a, b,arr[200000],arrCounter = 0;
    for(;;){
        cin >>a;
        if(cin.eof()){
            break;
        }
        cin >> b;
        if(cin.eof()){break;}
        arr[arrCounter] =  abs(a-b);
        arrCounter++;
    }
    for(a=0;a<arrCounter;a++){
        cout << arr[a] << endl;
    }
    /*
    while(cin >> a >> b)
    {
        if (cin.eof())
           return 0;
       cout << abs(a-b) << endl;
    }
    */
}






/*
#include<iostream>
#include<stdio.h>
using namespace std;
int main(){


    /*
    long long int a,b,arr[100000],arrCounter =0;
    while(scanf("%lld %lld", &a, &b) != EOF){
        arr[arrCounter] = a > b ? (a-b) : (b-a);
        arrCounter++;
    }
    for(a=0;a<arrCounter;a++){
        cout << arr[a] << endl;
    }
    */



    /*
    long a,b;
    int arr[10000],arrCounter = 0;
    for(;;){
        cin >>a;
        if(cin.eof()){break;}
        cin >>b;
        if(cin.eof()){break;}
        arr[arrCounter] = a >b ? (a-b) : (b-a);
        arrCounter++;
    }

    for(a=0;a<arrCounter;a++){
        cout << arr[a] << endl;
    }*/
    /*
	return 0;
}

*/
