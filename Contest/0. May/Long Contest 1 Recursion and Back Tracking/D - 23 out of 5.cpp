#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int arr[10], taken[10],pos[10];
int n=5,funcFlag = 1;

int calculate(int a, int b, int c){
    int ans;
    if(c == 1){
        ans =a+b;
    }else if(c==2){
        ans = a-b;
    }else{
        ans = a*b;
    }
    return (ans);
}

void gnrt(int id){
    int i,j,k,l,flag = 1,ans;
    if(funcFlag == 0){
        return;
    }
    if(id == n){
        for(i=1;i<=3 && flag;i++){
            for(j=1;j<=3 && flag;j++){
                for(k=1;k<=3 && flag;k++){
                    for(l=1;l<=3 && flag;l++){
                        ans = calculate(pos[0],pos[1],i);
                        ans = calculate(ans,pos[2],j);
                        ans = calculate(ans,pos[3],k);
                        ans = calculate(ans,pos[4],l);
                        if(ans == 23){
                            //cout << "Possible" << endl;
                            //exit(0);
                            flag = 0;
                            funcFlag = 0;
                            break;
                        }
                    }
                }
            }
        }
        return;
    }
    for(i=0;i<n && funcFlag;i++){
        if(taken[i] == 0){
            taken[i] = 1;
            pos[id] = arr[i];
            gnrt(id+1);
            taken[i] = 0;
        }
    }
}



int main(){
    int a,b,c,d,e,i,j,k,l,m,flag,ans,runWhile= 1, n =5;
    while(runWhile){
        runWhile = 0;
        funcFlag = 1;
        for(i=0;i<n;i++){
            cin >> arr[i];
            taken[i] = 0;
            if(arr[i] != 0 && runWhile == 0){
                runWhile = 1;
            }
        }
        if(runWhile == 1){
            gnrt(0);
            if(funcFlag){
                cout << "Impossible" << endl;
            }else{
                cout << "Possible" << endl;
            }
            //funcFlag =1;
        }
    }
    return 0;
}
