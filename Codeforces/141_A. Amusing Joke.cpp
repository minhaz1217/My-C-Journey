#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long i,j,counter = 0;
    string str1,str2, str;
    cin >> str1 >> str2 >> str;
    if(str.length() == str1.length() + str2.length()){
        for(i=0;str1[i];i++){
            for(j=0;str[j];j++){
                if(str[j] == str1[i]){
                    str[j] = '.';
                    counter++;
                    break;
                }
            }

        }
        for(i=0;str2[i];i++){
            for(j=0;str[j];j++){
                if(str[j] == str2[i]){
                    str[j] = '.';
                    counter++;
                    break;
                }
            }

        }
        if(counter == (str1.length() + str2.length())){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        cout << "NO" << endl;
    }

	return 0;
}
