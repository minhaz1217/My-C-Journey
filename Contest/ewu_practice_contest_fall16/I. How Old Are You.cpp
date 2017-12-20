#include<iostream>
using namespace std;
int main(){
    long long d1,d2, m1,m2, y1,y2, i ,a,flag=0,resYear=0, arrCounter = 0,caseCounter = 1;
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
            //cout << resYear << endl;
            if(resYear > 130){
                flag = 2;
            }else if(resYear < 0){
                flag = 1;
            }else{
                flag = 3;
            }
        }
        cout << "Case #" << caseCounter++ << ": ";
        switch(flag){
        case 0:
            cout << 0 << endl;
            break;
        case 1:
            cout << "Invalid birth date" << endl;
            arr[arrCounter][0] = 1;
            break;
        case 2:
            cout << "Check birth date" << endl;
           // cout << resYear << endl;
           // cout << "Check birth date" << endl;
            break;
        case 3:
            cout << resYear << endl;
        }
    }
    return 0;
}
