//https://www.hackerrank.com/contests/101hack38/challenges/points-on-a-line
#include<iostream>
using namespace std;
int main(){
    int i,flag, a;
    cin >> a;
    int num[a][2];
    for(i=0;i<a;i++){
        cin >> num[i][0] >> num[i][1];
    }
    flag = 0;
    for(i=0;i<a-1;i++){
        if(num[i][0] != num[i+1][0]){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout << "YES" << endl;
    }
    if(flag != 0){
        for(i=0;i<a-1;i++){
            if(num[i][1] != num[i+1][1]){
                flag = 2;
            }
        }
    }
    if(flag == 2){
        cout << "NO" << endl;
    }else if(flag ==1){
        cout << "YES" << endl;
    }

    //1 = all x not equal

}
