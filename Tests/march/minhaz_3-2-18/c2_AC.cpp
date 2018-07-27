#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c<< endl;

int main(){
    int tc,i,counter;
    string str1,str2;
    int arr[30];
    cin >> tc;
    while(tc--){
        cin >> str1 >> str2;
        for(i=0;i<30;i++){
            arr[i] = 0;
        }
        for(i=0;str2[i];i++){
            arr[str2[i]-'a']++;
        }
        counter = 0;
        //cc("HI")
        for(i=0;str1[i];i++){
            arr[str1[i]-'a']--;
            if(arr[str1[i]-'a'] <= -1){
                break;
            }else{
                counter++;
            }
        }
        cout << counter << endl;
    }

    return 0;
}
