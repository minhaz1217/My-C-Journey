#include<iostream>
using namespace std;
int main(){
    int a,c,i,j, b1[1][2], b2[1][2],x,y,flag=0,arrCounter = 0;
    char place1[8][8];
    cin >> a;
    int arr[a];
    for(c=0;c<a;c++){
    //b1,b2 = -1, flag=0
        flag =0;
        b1[0][0] = -1;
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                cin >> place1[i][j];
                cout << place1[i][j];
                if(place1[i][j] == 'B'){
                    if(b1[0][0] == -1){
                        b1[0][0] = i;
                        b1[0][1] = j;
                    }else{
                        b2[0][0] = i;
                        b2[0][1] = j;
                    }
                }
            }
        }
        if(flag != 1){
            for(x = b1[0][0],y=b1[0][1];x<8&& y<8;x++,y++){
                if(x == b2[0][0] && y == b2[0][1]){
                    flag = 1;
                    break;
                }
            }
        }// direction top left
        if(flag != 1){
            for(x = b1[0][0],y=b1[0][1];x>=0&&y<8;x--,y++){
                if(x == b2[0][0] && y == b2[0][1]){
                    flag = 1;
                    break;
                }
            }
        }//directiong bot left
        if(flag != 1){
            for(x = b1[0][0],y=b1[0][1];x>=0&& y>=0;x--,y--){
                if(x == b2[0][0] && y == b2[0][1]){
                    flag = 1;
                    break;
                }
            }
        }// direction top left
        if(flag != 1){
            for(x = b1[0][0],y=b1[0][1];x<8&& y>=0;x++,y--){
                if(x == b2[0][0] && y == b2[0][1]){
                    flag = 1;
                    break;
                }
            }
        }// direction top right
        if(flag == 1){
            arr[arrCounter] = 1;
        }else{
            arr[arrCounter] = 0;
        }
        arrCounter++;
    }
    for(i=0;i<arrCounter; i++){
        if(arr[i] == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

	return 0;
}
