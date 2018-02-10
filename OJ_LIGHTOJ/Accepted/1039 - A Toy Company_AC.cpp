#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;


char makeChange(char c, int op){
    if(op == 1){
        if(c+1 > 'z'){
            return 'a';
        }else{
            return (c+1);
        }
    }else{
        if(c-1 <'a'){
            return 'z';
        }else{
            return (c-1);
        }
    }
}


int main(){

    string s1, s2, s3,str1, str2, u,tmp, temp = "aaa";
    int tc,i,j,k,mk, v,n,caseCounter = 1;
    cin >> tc;

    while(tc--){
        queue<pair<string, int> >q;
        map<string , bool>mp;
        cin >> str1 >> str2;
        cin >> n;
        while(n--){
            cin >> s1 >> s2 >> s3;
            for(i=0;i<s1.size();i++){
                for(j=0;j<s2.size();j++){
                    for(k=0;k<s3.size();k++){
                        temp[0] = s1[i];
                        temp[1] = s2[j];
                        temp[2] = s3[k];
                        if(!mp[temp]){
                            //check(temp)
                            mp[temp] = 1;
                        }
                    }
                }
            }
        }
        //cc("HI")

        mk = INT_MAX;
        if(!mp[str1]){
            q.push(make_pair(str1, 0));
            mp[str1] = 1;
        }
        while(!q.empty()){
            u = q.front().first;
            v = q.front().second;
            q.pop();
            if(u == str2){
                mk = min(mk, v);
                break;
            }

            temp = u;
            temp[0] = makeChange(u[0], 1);
            if(!mp[temp]){
                q.push(make_pair(temp, v+1));
                mp[temp] = 1;
            }

            temp = u;
            temp[0] = makeChange(u[0], 2);
            if(!mp[temp]){
                q.push(make_pair(temp, v+1));
                mp[temp] = 1;
            }
            temp = u;
            temp[1] = makeChange(u[1], 1);
            if(!mp[temp]){
                q.push(make_pair(temp, v+1));
                mp[temp] = 1;
            }
            temp = u;
            temp[1] = makeChange(u[1], 2);
            if(!mp[temp]){
                q.push(make_pair(temp, v+1));
                mp[temp] = 1;
            }
            temp = u;
            temp[2] = makeChange(u[2], 1);
            if(!mp[temp]){
                q.push(make_pair(temp, v+1));
                mp[temp] = 1;
            }
            temp = u;
            temp[2] = makeChange(u[2], 2);
            if(!mp[temp]){
                q.push(make_pair(temp, v+1));
                mp[temp] = 1;
            }

        }

        if(mk == INT_MAX){
            mk = -1;
        }
        cout << "Case "<< caseCounter++ << ": " << mk << endl;

    }
    return 0;
}
