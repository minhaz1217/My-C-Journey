#include<iostream>
using namespace std;
int main(){
    int hh, mm,i,a,arrCounter = 0,nh,nm;
    cin >> a;
    char extra;
    int arr[a][2];
    for(i=0;i<a;i++){
        cin >> hh >> extra >> mm;

        if(mm > 0){
            nh = (12 - hh)-1;
        }else{
            nh = 12-hh;
        }
        if(nh == 0){
            nh = 12;
        }
        if(nh == -1){
            nh = 11;
        }
        nm = 60-mm;
        if(nm == 60){
            nm = 0;
        }
        arr[arrCounter][0] = nh;
        arr[arrCounter][1] = nm;
        arrCounter++;
    }

    for(i=0;i<arrCounter;i++){
        if(arr[i][0] <= 9 ){
            cout << "0" << arr[i][0] << ":";
        }else{
            cout << arr[i][0] << ":";
        }
        if(arr[i][1] <= 9 ){
            cout << "0" << arr[i][1];
        }else{
            cout << arr[i][1] ;
        }
        cout << endl;
    }


    return 0;
}
