#include<iostream>
using namespace std;
int main(){
    int d1,d2, m1,m2, y1,y2, i ,a,flag=0,resYear=0, arrCounter = 0;
    char extra;
    cin >> a;
    int arr[a][2];
    for(i=0;i<a;i++){
        flag = 0;
        cin >> d1 >> extra >> m1 >> extra >> y1;
        cin >> d2 >> extra >> m2 >> extra >> y2;
        if(y1 == y2 && m1 == m2 && d1 == d2){
            flag = 0;
        }else if(y1 <= y2 ){
            flag = 1;
        }
        if(y1 > y2){
            if(m1 >= m2){
                resYear = y1 - y2;
            }else{
                resYear = (y1 - y2)-1;
            }
            cout << resYear << endl;
            if(resYear > 130){
                flag = 2;
            }else if(resYear < 0){
                flag = 1;
            }else{
                flag = 3;
            }
        }

        switch(flag){
        case 0:
            arr[arrCounter][0] = 0;
            //cout << resYear << endl;
            //cout << 0 << endl;
            break;
        case 1:
            arr[arrCounter][0] = 1;
           // cout << resYear << endl;
            //cout << "Invalid birth date" << endl;
            break;
        case 2:
            arr[arrCounter][0] = 2;
           // cout << resYear << endl;
           // cout << "Check birth date" << endl;
            break;
        case 3:
            arr[arrCounter][0] = 3;
            arr[arrCounter][1] = resYear;
           // cout << resYear << endl;
        }
        arrCounter++;
    }

    for(i=0;i<arrCounter;i++){
        if(arr[i][0] == 0 ){
            cout << "Case #" << i+1 << ": " << 0 << endl;
        }else if(arr[i][0] == 1 ){
            cout << "Case #" << i+1 << ": " <<"Invalid birth date" << endl;
        }else if(arr[i][0] == 2 ){
            cout << "Case #" << i+1 << ": " <<"Check birth date" << endl;
        }else if(arr[i][0] == 3 ){
            cout << "Case #" << i+1 << ": " <<arr[i][1] << endl;
        }
    }


    return 0;
}
