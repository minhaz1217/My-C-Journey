#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    long long a,i,arrCounter = 0;
    string str;
    getline(cin, str);
    long long arr[str.length()+2];
    stringstream ss(str);
    while(ss >> arr[arrCounter++]){
        //cout << arr[arrCounter-1] << endl;
    }
    sort(arr, arr + arrCounter-1);
    cout << arr[0];
    for(i=1;i<arrCounter-1;i++){
        cout << "+"<< arr[i] ;
    }
	return 0;
}
