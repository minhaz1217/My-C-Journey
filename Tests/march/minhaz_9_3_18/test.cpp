#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    string str,str2;
    char prev;
    int i,counter=0, lCounter = 0,prevCounter=0;
    vector<char>vec;
    cin >> str;
    str2 = str;
    prev = str[0];
    counter = 1;
    vec.push_back(prev);
    //str2[lCounter++] = prev;
    for(i=1;str[i];i++){
        if(str[i] == prev){
            counter++;
            if(counter == 3){
                //vec.push_back(str[i]);
                str[i]= 'A';
                str[i-1] = 'A';
                counter = 1;
            }
        }else{
            prevCounter = counter;
            counter = 1;
            prev = str[i];
        }
        if(prevCounter >=2 && counter >=2){
            str[i] = 'A';
            counter = 1;
        }
    }
    for(i=0;str[i];i++){
        if(str[i]!='A'){
            cout << str[i];
        }
    }
    cout << endl;
    return 0;
}
