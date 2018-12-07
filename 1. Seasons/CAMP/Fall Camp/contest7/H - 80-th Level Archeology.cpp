#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
int c;
int rot(int &a){
    if(a == c){
        a = 1;
    }else{
        a++;
    }
}
int main(){
    int tc,a,b,i,j,n,k,myRt, flag,q,p,x,y;
    string str;
    //cin >> n >> c;
    scanf("%d %d", &n, &c);
    vector<int> v[n];
    int ss[n];
    for(i=0;i<n;i++){
        scanf("%d", &ss[i]);
        //cin >> a;
        a = ss[i];
        while(a--){
            scanf("%d", &b);
            //cin >> b;
            v[i].push_back(b);
        }
    }

    myRt = 0;
    for(k=1;k<c;k++){
        for(i=0;i<n-1;i++){
            for(j=0;j<ss[i];j++){
                flag = 0;
                if(!(j<ss[i+1])){
                    break;
                }
                if( (v[i][j] > v[i+1][j])){
                    flag = 1;
                    break;
                }else if(v[i][j] < v[i+1][j]){
                    break;
                }
            }
            if(flag == 1 && myRt <c){
                for(p=0;p<n;p++){
                    for(q=0;q<ss[p];q++){
                        rot(v[p][q]);
                    }
                }
                myRt++;

                /*
               msg("ROTATED", myRt)
            for(x=0;x<n;x++){
                for(y=0;y<v[x].size();y++){
                    //rot(v[i][j]);
                    cout << v[x][y] << " ";
                }
                cout << endl;
            }
            cout << endl;
            */

                k--;
                break;
            }
        }
    }

    /*
    cout << myRt << endl;
    cout << endl << endl;
    */
    /*
    for(x=0;x<n;x++){
        for(y=0;y<v[x].size();y++){
            //rot(v[i][j]);
            cout << v[x][y] << " ";
        }
        cout << endl;
    }
    cout << endl;
    */
    if(myRt >= c){
        printf("-1\n");
        //cout << -1 << endl;
    }else{
        printf("%d", myRt);
        //cout << myRt << endl;
    }

    return 0;
}
