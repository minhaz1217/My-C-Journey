#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){
    int flag, big, counter,i,j,foundVow = 0;
    string str;
    cin >> str;
    string vow = "AEIOUY";
    big = 0;
    counter = 1;
    foundVow = 0;
    for(i=0;str[i];i++){
        flag = 0;
        for(j=0;vow[j];j++){
            if(str[i] == vow[j]){
                foundVow = 1;
                flag = 1;
                break;
            }
        }


        if(flag == 1){
            big = max(big,counter);
            counter = 1;
        }else{
            counter++;
        }
    }
    big = max(big, counter);
    if(foundVow == 0){
        cout << str.length()+1 << endl;
    }else{
        cout << big << endl;
    }

    return 0;
}
