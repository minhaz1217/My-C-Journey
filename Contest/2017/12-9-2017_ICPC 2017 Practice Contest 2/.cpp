//UVA-11854


#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int i, num[3], arr[1000],arrCounter = 0,temp,x,y;
    for(;;){
        cin >> num[0] >> num[1] >> num[2];

            for(x=0;x<=2;x++){
                for(y=x+1;y<=2;y++){
                    if(num[x] > num[y]){
                        temp = num[x];
                        num[x] = num[y];
                        num[y] = temp;
                    }
                }
            }


        if(num[0] == 0 && num[1] == 0 && num[2] == 0){
            break;
        }

        if((num[0]*num[0] + num[1]*num[1])==(num[2]*num[2])) {
            arr[arrCounter] = 1;
        }else{
            arr[arrCounter] = 0;
        }
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        if(arr[i] == 1){
            cout<< "right"<<endl;
        }else{
            cout << "wrong"<<endl;
        }
    }
    return 0;
}
