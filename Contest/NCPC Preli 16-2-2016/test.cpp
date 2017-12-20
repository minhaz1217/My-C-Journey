#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b=3,c,sum,i,j;
    sum = 0;
    j = b;
    for(i=1;i<=10;i+=1){
        sum += j;
        j += b;
    }
    cout << sum << endl;

    return 0;
}
