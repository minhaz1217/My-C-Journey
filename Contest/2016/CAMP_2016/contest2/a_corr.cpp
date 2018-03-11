#include<bits/stdc++.h>
using namespace std;
int main(){
    long int nums[21] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441, 1000000,1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121};
    long long int n,i,flag;
    for(;;){
        cin >> n;
        if(n == 0){
            break;
        }
        flag = 0;
        for(i=0;i<21;i++){
            if(nums[i] == n){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "Ordinary" << endl;
        }else{
            cout << "Special" << endl;
        }

    }
  return 0;
}
