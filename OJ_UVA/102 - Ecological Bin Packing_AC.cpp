#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

int main(){
    int arr[10];
    char code[]  = {'B', 'G','C'}, currStr[10],temp[10];
    int i,j,k,brown,green, clr,sum,l,currMin;
    while(cin >> arr[0] >> arr[1] >> arr[2] >> arr[3]>> arr[4] >> arr[5] >> arr[6] >> arr[7] >> arr[8]){
        currMin = INT_MAX;
        currStr[0] = 'B';
        currStr[1] = 'C';
        currStr[2] = 'G';
        currStr[3] = '\0';
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                    if(i==j || i ==k || j == k){
                        continue;
                    }else{
                        /// 0 - brown 1 = green 2 = clear
                        sum = 0;
                        l = i;
                        if(l==0){
                            sum += arr[3] + arr[6];
                        }else if(l==1){
                            sum += arr[4]+ arr[7];
                        }else if(l==2){
                            sum += arr[5] + arr[8];
                        }
                        l = j;
                        if(l==0){
                            sum += arr[0] + arr[6];
                        }else if(l==1){
                            sum += arr[1]+ arr[7];
                        }else if(l==2){
                            sum += arr[2] + arr[8];
                        }
                        l = k;
                        if(l==0){
                            sum += arr[3] + arr[0];
                        }else if(l==1){
                            sum += arr[4]+ arr[1];
                        }else if(l==2){
                            sum += arr[5] + arr[2];
                        }
                        //msg2(i,j,k);
                        //cc(sum);

                        temp[0] = code[i];
                        temp[1] = code[j];
                        temp[2] = code[k];
                        temp[3] = '\0';
                        //msg2(temp, currMin,strcmp(temp, currStr))
                        if(sum < currMin){
                            currMin = sum;
                            currStr[0] = code[i];
                            currStr[1] = code[j];
                            currStr[2] = code[k];
                            currStr[3] = '\0';
                        }else if(sum == currMin && strcmp(temp, currStr) < 0){
                            strcpy(currStr, temp);
                            //currStr = temp;
                        }
                    }
                }
            }
        }
        printf("%s %d\n", currStr, currMin);
        //cout << currStr << " " << currMin << endl;
    }

    return 0;
}
