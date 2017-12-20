#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;

int checkEq(int a, int b,int c,int x, int y){
    if(a*x + b*y + c == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    /*
    long long int a,b,c,i;
    cin >> a >> b >> c;
    for(i=3;;i+=2){
        if((c+b*i)%a == 0){
            break;
        }
    }
    cout << -(c+b*i)/a << " " << i << endl;
    */
    cout << checkEq(13,17,41,533,-410) << endl;


	return 0;
}
