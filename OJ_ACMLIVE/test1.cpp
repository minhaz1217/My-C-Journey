#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int main(){

    int i,counter=0, flag,j;
    int a = 11;
    cout << (bitset<8>)(a) << ": " << (bitset<8>)(3) << endl;

    counter = 0;
    for(i=1;i<=9999999999;i++){

        string str;
        str = ((bitset<64>)i).to_string();
        flag = 1;
        for(j=1;str[j];j++){
            if(str[j] == '1' && str[j-1] == '1'){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            //msg(counter, i)
            //cout << (bitset<8>)(i) << endl;
            counter++;
        }
        //cout << "Sh: " << i+1 << ": " << (bitset<8>)(a & (3<<i)) << endl;
        //msg(i, (bitset<8>)i)
        //cout << (bitset<8>)i << endl;
    }
    cout << counter << endl;

    return 0;
}
