#include<iostream>
using namespace std;
int main(){
    int a,playerCount,i,temp,j,m,n,arrCounter = 0;
    cin >> a;
    int arr[a];
    for(i=0;i<a;i++){
        cin >> playerCount;
        int p[playerCount];
        for(j=0;j<playerCount;j++){
            cin >> p[j];
        }

        for(m=0;m<playerCount;m++){
            for(n=m+1;n<playerCount;n++){
                if(p[n] < p[m]){
                    temp = p[m];
                    p[m] = p[n];
                    p[n] = temp;
                }
            }
        }
        if(playerCount%2 == 0){
            arr[arrCounter] = p[(playerCount/2) + 1];
        }else{
            arr[arrCounter] = p[(playerCount /2)];
        }

        arrCounter++;
    }

    for(i=0;i<arrCounter;i++){
        cout << "Case " << i+1 << ": " << arr[i] << endl;
    }
    return 0;
}
