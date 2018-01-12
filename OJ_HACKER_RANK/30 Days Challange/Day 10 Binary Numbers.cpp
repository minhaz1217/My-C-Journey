#include<bits/stdc++.h>

using namespace std;


int main(){
    int n,counter = 0,prev = 0, big = 0,i;
    cin >> n;
    string str = bitset<16>(n).to_string();
   // cout << str << endl;


    for(i=str.length() - 1;i >= 0;i--){

        if(str[i] == '1'){
            counter++;
        }else{
            counter = 0;
        }

       // cout << counter << endl;
        big = max(big, counter);
    }
    cout << big << endl;


    return 0;
}
