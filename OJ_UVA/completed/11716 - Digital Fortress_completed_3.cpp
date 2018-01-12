#include<iostream>
#include<math.h>
using namespace std;
int main(){
    string str;
    int i,j,flag = 0,b,strCounter = 0,a,k,arrCounter = 0;
    cin >> a;
    string arr[a];
    cin.ignore();
    for(k=0;k<a;k++){
        getline(cin , str);
        for( i=0;str[i];i++);
        b = sqrt(i);
        if(i == b*b){
            flag = 1;
        }else{
            flag = 0;
            arr[arrCounter] = "INVALID";
            arrCounter++;
            continue;
        }
        char temp[b][b];
        strCounter = 0;
        for(i=0;i<b;i++){
            for(j=0;j<b;j++){
                temp[i][j] = str[strCounter];
                strCounter++;
            }
        }
        strCounter = 0;
        for(i=0;i<b;i++){
            for(j=0;j<b;j++){
                str[strCounter] = temp[j][i];
                strCounter++;
            }
        }
        arr[arrCounter] = str;
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << arr[i] << endl;
    }

	return 0;
}
