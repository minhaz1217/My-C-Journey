//UVA-490

#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int i,counter,j,big;
    string str[200];
    char str2[200][200];
    counter = 0;
    /*
    for(i=0;i<200;i++){
        for(j=0;j<200;j++){
            str[i][j] = ' ';
        }
    }
    */
    big = 0;
    while(1){

        getline(cin, str[counter]);
        if(cin.eof()){
            break;
        }
        //cout << str[counter].length() << endl;
        big = max(big, (int)str[counter].length());
        counter++;
    }
    //cout << big << endl;
    for(i=0;i<big;i++){
        for(j=counter-1;j>=0;j--){
            if(i < str[j].length()){
            cout << str[j][i];
            }else{
                cout << " ";
            }
        }
        cout << endl;

    }
    /*
    big = 0;
    for(i=counter-1;i>=0;i--){
        for(j=0;str[i][j];j++){
            str2[j][counter-1-i] = str[i][j];
        }
        big = max(big, j);
    }
    for(i=0;i<j;i++){
        cout << str2[i] << endl;
    }
    */

    return 0;
}
