/*
critical case :
a b
b c
c a
should output no
my code > yes



*/



#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
struct drinks{
    string pre;
    int taken=0;
};

int main(){
    int n,flag=0,drunk = 1,arrCounter = 0,i,caseCounter = 1,tc;
    string str1,str2;
    cin >> tc;
    while(tc--){
        cin >>n;
        string str[n][2];
        arrCounter = 0;
        flag = 0;
        drunk = 1;
        while(n--){
            cin >> str1 >> str2;
            if(str1 == str2){
                drunk = 0;
            }
            if(drunk){
            for(i=0;i<arrCounter;i++){
                if(str[i][0] == str2){
                    if(str[i][1] == str1){
                        flag = 1;
                        break;
                    }
                }
            }

            }

            if(flag == 0){
                str[arrCounter][0] = str1;
                str[arrCounter++][1] = str2;
            }else{
                drunk = 0;
            }

        }
        cout << "Case " << caseCounter++ << ": ";
        if(drunk == 0){
            cout << "No"<< endl;
        }else{
            cout << "Yes" << endl;
        }
    }


	return 0;
}
