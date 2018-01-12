#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    string str;
    long long i,flag1 = 0, flag2 =0,flag3= 0,flag4= 0, flag5= 0;
    cin >> str;

    for(i=0;str[i];i++){
        if(str[i] == 'h' && flag1 == 0){
            flag1 = 1;
        }else if(str[i] == 'e' && flag1 ==1&& flag2 == 0){
            flag2 = 1;
        }else if(str[i] == 'l' && flag2 == 1&& flag3 == 0){
            flag3 = 1;
        }else if(str[i] == 'l' && flag3 ==1&& flag4 == 0){
            flag4 = 1;
        }else if(str[i] == 'o' && flag4 ==1&& flag5 == 0){
            flag5 = 1;
            break;
        }
    }
    if(flag1 == 1 && flag2 == 1 && flag3 ==1 && flag4 ==1 && flag5 == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
	return 0;
}
