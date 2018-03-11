#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double tc,n,bNum=0,sNum=0,ans;
    int caseCounter = 1;
    cin >>tc;
    if(tc!=0){
        cin >> n;
        bNum = n;
        sNum = n;
        ans = bNum/sNum;
        printf("Case %d: %.2lf\n", caseCounter++, ans);
        tc--;
    }
    while(tc--){
        cin >> n;
        if(n>bNum){
            bNum = n;
        }else if(n< sNum){
            sNum = n;
        }
        ans = bNum/sNum;
        printf("Case %d: %.2lf\n", caseCounter++, ans);
    }
        return 0;
}
