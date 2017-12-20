#include<bits/stdc++.h>
using namespace std;
int poww;
int power(int x, int y){
    if(y==0){
        return 1;
    }else{
        poww *= x;
        power(x, y-1);
    }
}
int main(){
    poww = 1;
    power(2,3);
    cout << poww << endl;


}
