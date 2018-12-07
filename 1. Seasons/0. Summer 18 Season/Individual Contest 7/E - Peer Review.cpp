#include<bits/stdc++.h>
using namespace std;
#define cc(a) cout << a << endl;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b  << " : " << c << endl;

int main(){

    int n,k;
    while(1){
        cin >> k >> n;
        if(k ==0 && n ==0){
            break;
        }

        int i, counter,j,p,q,index = 0,a,sz,prof1,prof2,m,l;

        string str;
        int N = n+4;
        int flag[N];
        int problem[N];
        vector<int>vec[N],reviewed;
        map<string,int>mp;
        int mat[N][N];

        index = 1;
        for(i=0;i<=n;i++){
            flag[i] = 0;
            problem[i] = 0;
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                mat[i][j] = 0;
            }
        }
        for(i=1;i<=n;i++){
            cin >> str;
            if(!mp[str]){
                mp[str] = index++;
            }
            vec[mp[str]].push_back(i);
            for(j=0;j<k;j++){
                cin >> a;
                flag[a]++;
                //mat[a][i] = 1;
                //mat[i][a] = 1;
                mat[mp[str]][a] = 1;
                if(a == i){ // reviewing his own paper
                    problem[a]++;
                }
                reviewed.push_back(a);
            }
            sz = reviewed.size();
            for(m=0;m<sz-1;m++){
                for(l=m+1;l<sz;l++){
                    if(reviewed[l] == reviewed[m]){
                        problem[l]++;
                    }
                }
            }
            reviewed.clear();
        }

        /*
for(int xx = 1;xx<=n;xx++){
    for(int yy= 1;yy<=n;yy++){
        cout << mat[xx][yy] << " ";
    }
    cout << endl;
}
*/

/*
cc("SAME PERSON REVIEWS OWN PAPER CHECK")
for(int xx=1;xx<=n;xx++){
    cout << problem[xx] << " ";
}
cout << endl;

*/
        for(i=1;i<=n;i++){
            if(flag[i] < 2 || flag[i] >k){ // paper isn't reviewed enough
               // msg("HI",i)
                problem[i] = 1;
            }
        }
/*
cc("PAPER ISn't REVIEWED ENOUGH")
for(int xx=1;xx<=n;xx++){
    cout << problem[xx] << " ";
}
cout << endl;
*/
        //msg("INDEX", index)
        int myCounter = 0,x,y;
        for(i=1;i<index;i++){
            sz = vec[i].size();
            //msg("SIZ", sz)
            for(x = 0;x<sz;x++){
                for(y = 0;y<sz;y++){
                    prof1 = vec[i][x];
                    prof2 = vec[i][y];
                    if(mat[prof1][prof2] == 1){
                        problem[prof2]++;
                        myCounter++;
                    }
                }
            }
        }
        //msg("HI", myCounter)
/*
        for(i=1;i<=index;i++){
            sz = vec[i].size();
            for(j=0;j<sz;j++){
                for(k=j;k<sz;k++){
                    prof1 = vec[i][j];
                    prof2 = vec[i][k];
                    for(p=0;p<reviewed[prof1].size();p++){
                        if( reviewed[prof1][p] == prof2){
                            problem[prof2]++;
                        }else if(reviewed[prof2][p] == prof1){
                            problem[prof1]++;
                        }
                    }
                }
            }
        }
*/
/*
cc("COLAB")
for(int xx=1;xx<=n;xx++){
    cout << problem[xx] << " ";
}
cout << endl;
*/
/*
        for(i=1;i<=n;i++){
            sz = reviewed[i].size();
            for(j=0;j<sz-1;j++){
                for(k=j+1;k<sz;k++){
                    if( reviewed[i][j] ==  reviewed[i][k] ){
                        problem[reviewed[i][j]]++;
                    }
                }
            }

        }
        */
        counter = 0;
        for(i=1;i<=n;i++){
            if(problem[i] >0){
                counter++;
            }
        }
        if(counter == 0){
            cout << "NO PROBLEMS FOUND" << endl;
        }else{
            if(counter == 1){

            cout << counter << " PROBLEM FOUND" << endl;

            }else{

            cout << counter << " PROBLEMS FOUND" << endl;
            }
        }
    }
    return 0;
}
