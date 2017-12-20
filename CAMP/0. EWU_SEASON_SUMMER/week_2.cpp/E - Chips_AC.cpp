#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int n,m,curr = 1,i;
    cin >> n >> m;
    while(1){

        if(m - curr <0){
            break;
        }else{
            m = m-curr;
        }
        curr++;
        if(curr > n){
            curr = 1;
        }
        //cout << m << endl;
    }
    cout << m << endl;

    return 0;
}
