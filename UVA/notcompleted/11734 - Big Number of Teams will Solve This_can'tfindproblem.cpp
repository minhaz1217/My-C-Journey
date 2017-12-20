#include<iostream>
using namespace std;
int main(){
    int i,j,tLength, jLength,lenFlag = 0,tempCounter = 0, verdict = 0,a, arrCounter = 0;
    string judge, team,temp;
    cin >> a;
    int arr[a];
    cin.ignore();
    for(i=1;i<=a;i++){
        lenFlag = 0;
        getline(cin ,team);
        temp = team;
        getline(cin ,judge);
        for(tLength = 0;team[tLength];tLength++);
        for(jLength = 0; judge[jLength]; jLength++);
        if(tLength == jLength){
          5  for(jLength = 0;team[jLength];jLength++){
                if(team[jLength] != judge[jLength]){
                    lenFlag = 1;
                    break;
                }
            }
            if(lenFlag != 1){
                verdict =1;
            }else if(lenFlag == 1){
                verdict =2;
            }
        }else{
            lenFlag = 0;
            for(tLength = 0;team[tLength];tLength++){
                if(team[tLength]!= ' '){
                    temp[tempCounter] = team[tLength];
                    tempCounter++;
                }
            }
            temp[tempCounter] = NULL;
            if(tempCounter == jLength){
                for(tLength =0; temp[tLength];tLength++){
                    if(judge[tLength] != temp[tLength]){
                        lenFlag = 1;
                        break;
                    }
                }
                if(lenFlag == 1){
                    verdict = 2;
                }else{
                    verdict = 3;
                }
            }else{
                verdict = 2;
            }
        }
        switch(verdict){
            case 1:
            arr[arrCounter] = 1;
            break;
            case 2:
            arr[arrCounter] = 2;
            break;
            case 3:
            arr[arrCounter] = 3;
            break;
        }
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        cout << "Case " << i+1 << ": ";
        switch(arr[i]){
            case 1:
            cout << "Yes";
            break;
            case 2:
            cout << "Wrong Answer";
            break;
            case 3:
            cout << "Output Format Error";
            break;
        }
        cout << endl;
    }

    return 0;
}
