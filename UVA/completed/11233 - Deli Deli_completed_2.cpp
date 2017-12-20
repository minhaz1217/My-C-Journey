#include<iostream>
using namespace std;
int main(){
    int i,j,l,n,flag =0,len;
    cin >> l >> n;
    string irr[l][2],word,subStr;
    for(i=0;i<l;i++){
        cin >> irr[i][0] >> irr[i][1];
    }
    for(i=0;i<n;i++){
        cin >> word;
        flag =0;
        for(j=0;j<l;j++){
            if(word == irr[j][0]){
                flag =1;
                cout << irr[j][1] << endl;
                break;
            }
        }

        if(flag != 1){
            len = word.length() -1;
            subStr = word.substr(len-1,len);
            if(!(subStr == "ay" || subStr == "ey" || subStr == "iy" || subStr == "oy" || subStr == "uy" ) && word[len] == 'y'){
                word.erase(len,len);
                cout << word << "ies" << endl;
            }else if(subStr == "ch" ||subStr=="sh"|| subStr == "es" ||word[len]=='o' || word[len]=='s' || word[len]=='x'){
                cout << word << "es" << endl;
            }else{
                cout << word << "s" << endl;
            }
        }
    }
	return 0;
}
