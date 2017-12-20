#include<iostream>
using namespace std;
int main(){
    int len,sum =0,flag =0,i;
    string word;
    for(;;){
        sum = 0;
        flag =0;
        cin >> word;
        if(cin.eof()){
            break;
        }
        for(i=0;word[i];i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                sum += (word[i] - 'A'+27);
            }else{
                sum += word[i] - 'a'+1;
            }
        }



        if(sum%2 ==0 && sum!= 2){
            flag = 1;
        }else{
            for(len = 3;len <= sum/2+1;len+=2){
                if(sum % len == 0){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1){
            cout << "It is not a prime word." << endl;
        }else{
            cout << "It is a prime word." << endl;
        }
    }
	return 0;
}
