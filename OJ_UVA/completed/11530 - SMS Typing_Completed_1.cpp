#include<iostream>
using namespace std;
int main(){
    int i,num,sum = 0,flag  =0,j,a,k,arrCounter = 0;
    string name, one = "adgjmptw " , two= "behknqux" , three="cfilorvy", four="sz";
    cin >> a;
    int arr[a];
    cin.ignore();
    for(k=1;k<=a;k++){
        getline(cin , name);
        for(i=0;name[i];i++){
            flag = 0;
            for(j=0;one[j];j++){
                if(name[i] == one[j]){
                    flag =1;
                    sum += 1;
                    break;
                }
            }
            if(flag != 1){
                for(j=0;two[j];j++){
                    if(name[i] == two[j]){
                        flag =1;
                        sum += 2;
                        break;
                    }
                }
            }
            if(flag != 1){
                for(j=0;three[j];j++){
                    if(name[i] == three[j]){
                        flag =1;
                        sum += 3;
                        break;
                    }
                }
            }
            if(flag != 1){
                for(j=0;four[j];j++){
                    if(name[i] == four[j]){
                        flag =1;
                        sum += 4;
                        break;
                    }
                }
            }
        }
        arr[arrCounter] = sum;
        arrCounter++;
        sum = 0;
    }
    for(i=0;i<arrCounter;i++){
        cout << "Case #" << i+1 << ": "<< arr[i] << endl;
    }
    return 0;
}
