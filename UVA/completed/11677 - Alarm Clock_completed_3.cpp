#include<iostream>
using namespace std;
int main(){
    int i,flag= 0,k,arr[1000], arrCounter = 0,j=0,h1,h2,m1,m2,mCounter = 0;
    for(;;){
        cin >> h1 >> m1 >> h2 >> m2;
        if(h1==0 &&  h2==0 && m1==0 && m2==0){
            break;
        }
        flag = 0;
        mCounter = 0;
        for(j=h1;;j++){
            if(j==24){
                j=0;
            }
            for(k=m1;k<=59;k++){
                if(j == h2 && k==m2){
                    flag = 1;
                    break;
                }
                mCounter++;
            }
            if(flag == 1) break;
            m1 = 0;
        }
        arr[arrCounter] = mCounter;
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << arr[i] << endl;
    }

    return 0;
}
