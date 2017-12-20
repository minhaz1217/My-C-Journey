#include<iostream>
using namespace std;
int main(){
    int n,k,flag = 0,num;
    cin >> n >> k;
    while(n--){
        cin >> num;
        if(flag == 1){
            continue;
        }
        if(num%k == 0){
            flag = 1;
        }
    }
    if(flag == 1){
        cout << "Yes";
    }else{
        cout << "No";
    }
	return 0;
}
