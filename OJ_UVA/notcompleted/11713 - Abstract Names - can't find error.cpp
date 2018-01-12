#include<iostream>
using namespace std;
int main(){
    int i,rLen,gLen,j,vCheck1 = 0,vCheck2 = 0,a,arrCounter = 0;
    string rName, gName,vow = "aeiou";
    cin >> a;
    int arr[a];
    for(i=0;i<a;i++){
        vCheck1 = 0;
        vCheck2 = 0;
        rLen = 0;
        gLen = 0;
        cin >> rName;
        cin >> gName;
        for(rLen = 0 ;rName[rLen];rLen++);
        for(gLen = 0 ;gName[gLen];gLen++);
        if(rLen == gLen){
            for(rLen=0;rName[rLen];rLen++){
                vCheck1 = 0;
                vCheck2 = 0;
                if(gName[rLen] != rName[rLen]){
                    for(j=0;vow[j];j++){
                        if(rName[rLen] == vow[j]){
                            vCheck1 = 1;
                            break;
                        }
                    }
                    for(j=0;vow[j];j++){
                        if(gName[rLen] == vow[j]){
                            vCheck2 = 1;
                            break;
                        }
                    }
                    if(vCheck1 == 1 && vCheck2 == 1){
                        arr[arrCounter] =1;
                    }else{
                        arr[arrCounter] = 0;
                        break;
                    }
                }
            }
        }else{
            arr[arrCounter] =0;
        }
        arrCounter++;
    }
    for(i=0;i<arrCounter;i++){
        if(arr[i] == 0){
        	cout << "No" << endl;
        }else{
        	cout << "Yes" << endl;
        }
    }
	return 0;
}
