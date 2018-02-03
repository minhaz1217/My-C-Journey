#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define MX 30
#define INFINITE 50000
int young[MX][MX], old[MX][MX];
int arr[MX];


int main(){
    int tc,i,j,nodes,w,currMin,n,k,y,o, minX,caseCounter = 1,counter;
    char a, dir, u , v;
    map<char, int>nodeName;

    while(1){
        cin >> tc;
        if(tc == 0){
            break;
        }
        /*
        if(caseCounter>1){
            cout << endl;
        }
        caseCounter++;
        */
        for(i=0;i<MX;i++){
            for(j=0;j<MX;j++){
                young[i][j] = INFINITE;
                old[i][j] = INFINITE;
            }
            young[i][i] = 0;
            old[i][i] = 0;
            arr[i] = 0;
        }

        nodes = 1;
        nodeName.clear();
        while(tc--){
            cin >> a >> dir >> u >> v >> w;
            if(!nodeName[u]){
                nodeName[u] = nodes++;
            }
            if(!nodeName[v]){
                nodeName[v] = nodes++;
            }

            if(a == 'Y'){
                    young[nodeName[u]][nodeName[v]] = w;
                if(dir == 'B'){
                    young[nodeName[v]][nodeName[u]] = w;
                }
            }else{
                    old[nodeName[u]][nodeName[v]] = w;
                if(dir == 'B'){
                    old[nodeName[v]][nodeName[u]] = w;
                }
            }
        }
        nodes--;

        for(k=1;k<=nodes;k++){
            for(i=1;i<=nodes;i++){
                for(j=1;j<=nodes;j++){
                    if(young[i][j] > young[i][k] + young[k][j]){
                        young[i][j] = young[i][k] + young[k][j];
                    }
                    if(old[i][j] > old[i][k] + old[k][j]){
                        old[i][j] = old[i][k] + old[k][j];
                    }
                }
            }
        }



        cin >> u >> v;
        counter = 0;
        y = nodeName[u];
        o = nodeName[v];
        currMin = INFINITE;

        for(i=1;i<=nodes;i++){
            if(young[y][i] + old[o][i] < currMin){
                currMin = young[y][i] + old[o][i];
            }
        }
        for(i=1;i<=nodes;i++){
            //msg(i, young[y][i] + old[o][i])
            if(young[y][i] + old[o][i] == currMin){
                //arr[counter++] = i;
                for(j='A';j<='Z';j++){
                    if(nodeName[(char)j] == i){
                        arr[counter++] = j;
                    }
                }
            }
        }
        if(currMin > 0 && u == v){
            cout << 0 << " " << u << endl;
        }else if(currMin >= INFINITE ){
            cout << "You will never meet." << endl;
        }else{
            sort(arr, arr+counter);
            cout << currMin;
            for(i=0;i<counter;i++){
                cout << " " << (char)arr[i];
            }
            cout << endl;
        }
        //cout << minX << endl;
        //msg(currMin, minX)
}


    return 0;
}
