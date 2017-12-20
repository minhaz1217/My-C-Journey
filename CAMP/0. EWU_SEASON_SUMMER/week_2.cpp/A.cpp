#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
int main(){
    int i;
    char str1[101], str2[101];
    cin >> str1 >> str2;
    for(i=0;str1[i];i++){
        str1[i] =  (char)tolower(str1[i]);
    }
    for(i=0;str2[i];i++){
        str2[i] =  (char)tolower(str2[i]);
    }
    cout << (int)strcmp(str1,str2) << endl;
	return 0;
}
