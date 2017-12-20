#include<iostream>
using namespace std;
int main(){
    int num=0,i,j,len,a,cases=1;
    string str;
    char temp;
    cin >> a;
    while(a--){
        cout << "Case " << cases++ << ": ";
        cin >> str;
        len = str.length();
        for(i=0;i<len;i++){
            if(str[i] >=48 && str[i] <= 57){
                if(str[i-1] >= 65 && str[i-1] <= 90){
                    temp = str[i-1];
                }
                num = (num*10) + (str[i]-48);
            }
            if(i+1>=len || (str[i+1] >= 65 && str[i+1] <=90)){
                for(j=1;j<=num;j++){
                    cout << temp;
                }
                num = 0;
            }
        }
        cout << endl;
    }

	return 0;
}
