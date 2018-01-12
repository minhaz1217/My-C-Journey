#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << ": " << b << endl;
int main(){
    long long n,i,sum=0,a,b,remain,increment,prev;
    cin >> n;
    increment = 5;
    for(i=1;;i++){
        prev = sum;
        sum += increment;
        if(sum >= n){
            break;
        }
        increment = increment*2;
    }
    /*
    msg("SUM:" , sum);
    msg("prev" , prev)
    msg("i" , i)
    msg("n-pre" , (double)(n-prev)/ (double)(i*2))
    */
    sum = ceil( (double)(n-prev)/ (double)(increment/5) );
    switch(sum){
    case 1:
        cout << "Sheldon" << endl;
        break;
    case 2:
        cout << "Leonard" << endl;
        break;
    case 3:
        cout << "Penny" << endl;
        break;
    case 4:
        cout << "Rajesh" << endl;
        break;
    case 5:
        cout << "Howard" << endl;
        break;

    }


	return 0;
}
