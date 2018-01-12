#include<bits/stdc++.h>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    long long m,n,i,j,caseCounter = 1;
    char ch;
    for(;;){
        cin >> m >> n;
        if(m==0 && n == 0){
            break;
        }else if(caseCounter > 1){
            cout << endl;
        }
        int arr[m][n];
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                arr[i][j] = 0;
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cin >> ch;
                if(ch == '*'){
                    arr[i][j] = -9;
                    if(i-1 >= 0){
                        if(arr[i-1][j] != -9){
                            arr[i-1][j]++;
                        }
                        if(j-1 >= 0){
                        if(arr[i-1][j-1] != -9){
                            arr[i-1][j-1]++;
                        }
                        }
                        if(j+1 <n){
                            if(arr[i-1][j+1] != -9){
                                arr[i-1][j+1]++;
                            }
                        }
                    }
                    if(i+1 < m){
                        if(arr[i+1][j] != -9){
                            arr[i+1][j]++;
                        }
                        if(j-1 >=0 && arr[i+1][j-1]!= -9){
                        arr[i+1][j-1]++;
                        }
                        if(j+1 < n && arr[i+1][j+1]!= -9){
                        arr[i+1][j+1]++;
                        }
                    }
                    if(j+1 <n && arr[i][j+1]!= -9){
                        arr[i][j+1]++;
                    }
                    if(j-1 >=0 && arr[i][j-1]!= -9){
                        arr[i][j-1]++;
                    }

                }
            }
        }
        cout << "Field #"<< caseCounter++ << ":"<<endl;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                if(arr[i][j] == -9){
                    cout << "*";
                }else{
                cout << arr[i][j];
                }
            }
            cout << endl;
        }
    }
	return 0;
}
