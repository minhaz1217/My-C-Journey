#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
string add(string a, string b){
    int i,j,prev=0,x;
    string big = a.length() > b.length() ? a:b;
    string small = a.length() > b.length()? b : a;
    string temp = big;
    for(i=small.length()-1,j=big.length()-1;i>=0;i--,j--){
        x = (small[i] -'0') + (big[j] - '0') + prev;
        if(x >= 10){
            prev = 1;
            x = x - 10;
        }else{
            prev = 0;
        }
        temp[j] = x + '0';
    }
    if(prev == 1 && big.length() == small.length()){
        temp = "1" + temp;
    }else if(prev == 1){
        for(i=j;i<=big.length()-1;i++){
            x = temp[i] - '0' + prev;
            if(x >= 10){
                prev = 1;
                x = x - 10;
            }else{
                temp[j] = x + '0';
                break;
            }
            temp[j] = x + '0';
        }
        if(prev == 1 && i > big.length()){
            temp = "1" + temp;
        }
    }
    //cout << "B: " << big << " S: " << small << endl;
    return temp;

}

int main(){
int counter = 0;
    string result = "00",str;
    for(;;){
        cin >> str;
        result = add(str, result);
        if(str == "0"){
           break;
        }
    }
    cout << result << endl;
	return 0;
}
