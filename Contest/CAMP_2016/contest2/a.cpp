#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    for(;;){
        cin >> n;
        if(n == 0){
            break;
        }
        rt = sqrt(n);
        for(i=1;i<rt;i++){
            if(i*i*i == n || i*i*i > n){
                break;
            }
        }

        if(rt*rt == n && i*i*i == n){
            cout << "Special" << endl;
        }else{
            cout << "Ordinary" << endl;
        }


    }



    return 0;
}
