#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool dfs_num[104];
bool dfs_num2[104] = {0};
int mat[104][104];
int n;
int found;
void dfs(int u){
    dfs_num[u] = 1;
    for(int i=0;i<n;i++){
        if(mat[u][i] == 1 && dfs_num[i] == 0){
            dfs(i);
        }
    }
}
void dfs2(int u, int x){
    if(u == x){
        return;
    }
    dfs_num2[u] = 1;
    for(int i=0;i<n;i++){
        if(mat[u][i] == 1 && dfs_num2[i] == 0){
            dfs2(i,x);
        }
    }
}
void init(){
    for(int i=0;i<n;i++){
        dfs_num2[i] = 0;
    }
}
int main(){
    int tc,k,i,j,firstFound, secondFound,caseCounter = 1;
    char t;
    cin >> tc;
    while(tc--){
        cin >> n;
        int curr[n][n];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin >> mat[i][j];
            }
            dfs_num[i] = 0;
        }
        dfs(0);
        for(i=0;i<n;i++){
                init();
            dfs2(0,i);
            for(j=0;j<n;j++){
                firstFound = dfs_num[j];
                secondFound = dfs_num2[j];
                if(firstFound == 1 && secondFound == 1){
                    curr[i][j] = 0;
                }else if(firstFound == 0 && secondFound == 1){
                    curr[i][j] = 0;
                }else if(firstFound == 1 && secondFound == 0){
                    curr[i][j] = 1;
                }else{
                    curr[i][j] = 0;
                }
            }

        }
        cout << "Case " << caseCounter++ << ":" << endl;
        cout << "+";
        for(k=1;k<=2*n-1;k++){
            cout << "-";
        }
        cout << "+" << endl;
        for(i=0;i<n;i++){
            cout << "|";
            for(j=0;j<n;j++){
                if(curr[i][j] == 1){
                    t = 'Y';
                }else{
                    t = 'N';
                }
                printf("%c|", t );
            }
            cout << endl;
            cout << "+";
            for(k=1;k<=2*n-1;k++){
                cout << "-";
            }
            cout << "+" << endl;
        }
    }


    return 0;
}
