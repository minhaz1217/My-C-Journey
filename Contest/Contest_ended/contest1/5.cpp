#include<iostream>
using namespace std;
int main(){
    int a,i,j,xCounter =0, oCounter = 0,arrCounter = 0;
    char place[3][3],check;
    cin >> a;
    int arr[a];
    for(c=0;c<a;c++){
        xCounter = 0;
        oCounter = 0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cin >> place[i][j];
                if(place[i][j] == 'x' || place[i][j] == 'X'){
                    xCounter++;
                }else if(place[i][j] == 'o' || place[i][j] == 'O'){
                    oCounter++;
                }
            }
        }
        if((xCounter - oCounter)<-1 ||(xCounter - oCounter) > 1){
            arr[arrCounter] = 0;
            arrCounter++;
            continue;
        }
        check = 'X';
        if(place[0][0] == check && place[0][1] == check && place[0][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[1][0] == check && place[1][1] == check && place[1][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[2][0] == check && place[2][1] == check && place[2][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][0] == check && place[1][0] == check && place[2][0] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][1] == check && place[1][1] == check && place[2][1] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][2] == check && place[1][2] == check && place[2][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][0] == check && place[1][1] == check && place[2][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][2] == check && place[1][1] == check && place[2][0] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        check = 'O';
        if(place[0][0] == check && place[0][1] == check && place[0][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[1][0] == check && place[1][1] == check && place[1][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[2][0] == check && place[2][1] == check && place[2][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][0] == check && place[1][0] == check && place[2][0] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][1] == check && place[1][1] == check && place[2][1] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][2] == check && place[1][2] == check && place[2][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][0] == check && place[1][1] == check && place[2][2] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        if(place[0][2] == check && place[1][1] == check && place[2][0] == check){
            arr[arrCounter] = 1;
            arrCounter++;
            continue;
        }
        arr[arrCounter] = 0;
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        if(arr[i] == 1){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }

	return 0;
}
