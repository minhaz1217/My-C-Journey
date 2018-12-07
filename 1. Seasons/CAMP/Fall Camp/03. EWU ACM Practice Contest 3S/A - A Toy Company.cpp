#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define c(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

char inc(char c){
    if(c=='z'){
        return 'a';
    }else{
        return ++c;
    }
}
char dec(char c){
    if(c=='a'){
        return 'z';
    }else{
        return --c;
    }
}
int strFound,counter;

void BFS(string str1, string str2, map<string, bool> mp){
    string str3 = str1;
    map<string, string>vis;
    queue<string> q;
    q.push(str1);
    while(!q.empty()){
        str1 = q.front();
        q.pop();
        str3 = str1;
        str3[0] = inc(str1[0]);
        if(str3 == str2){
            strFound = 1;
            break;
        }else if(!mp[str3]){
            vis[str3] = str1;
            mp[str3] = 1;
            q.push(str3);
        }

        str3 = str1;
        str3[1] = inc(str1[1]);
        if(str3 == str2){
            strFound = 1;
            break;
        }else if(!mp[str3]){
            vis[str3] = str1;
            mp[str3] = 1;
            q.push(str3);
        }

        str3 = str1;
        str3[2] = inc(str1[2]);
        if(str3 == str2){
            strFound = 1;
            break;
        }else if(!mp[str3] ){
            vis[str3] = str1;
            mp[str3] = 1;
            q.push(str3);
        }
        /*
        str3 = str1;
        str3[0] = inc(str1[0]);
        str3[1] = inc(str1[1]);
        if(str3 == str2){
            strFound = 1;
            return;
        }else if(!mp[str3] && !vis[str3]){
            vis[str3] = 1;
            q.push(str3);
        }

        str3 = str1;
        str3[0] = inc(str1[0]);
        str3[2] = inc(str1[2]);
        if(str3 == str2){
            strFound = 1;
            return;
        }else if(!mp[str3] && !vis[str3]){
            vis[str3] = 1;
            q.push(str3);
        }

        str3 = str1;
        str3[1] = inc(str1[1]);
        str3[2] = inc(str1[2]);
        if(str3 == str2){
            strFound = 1;
            return;
        }else if(!mp[str3] && !vis[str3]){
            vis[str3] = 1;
            q.push(str3);
        }
        str3 = str1;
        str3[0] = inc(str1[0]);
        str3[1] = inc(str1[1]);
        str3[2] = inc(str1[2]);
        if(str3 == str2){
            strFound = 1;
            return;
        }else if(!mp[str3] && !vis[str3]){
            vis[str3] = 1;
            q.push(str3);
        }
        */

        str3 = str1;
        str3[0] = dec(str1[0]);
        if(str3 == str2){
            strFound = 1;
            break;
        }else if(!mp[str3]){
            vis[str3] = str1;
            mp[str3] = 1;
            q.push(str3);
        }

        str3 = str1;
        str3[1] = dec(str1[1]);
        if(str3 == str2){
            strFound = 1;
            break;
        }else if(!mp[str3]){
            vis[str3] = str1;
            mp[str3] = 1;
            q.push(str3);
        }

        str3 = str1;
        str3[2] = dec(str1[2]);
        if(str3 == str2){
            strFound = 1;
            break;
        }else if(!mp[str3]){
            vis[str3] = str1;
            mp[str3] = 1;
            q.push(str3);
        }

        counter++;
    }
    string temp;
    if(strFound){
        counter = 0;
        temp = vis[str2];
        while(temp!= str1){
            counter++;
            temp = vis[temp];
        }


    }



}
int main(){
    int tc,k;
    char a,b,c;
    string str1,str2,str3 = "AAA";
    cin >> tc;
    map<string ,bool> mp;
    while(tc--){
        cin >> str1;
        cin >> str2;
        cin >> k;
        while(k--){
            cin >> a >> b >> c;
            str3[0] = a;
            str3[1] = b;
            str3[2] = c;
            mp[str3] = 1;
            //cout << ++str3[0] << endl;
        }

        strFound = 0;
        counter = 0;
        BFS(str1,str2, mp);
        if(strFound == 1){
            cout << counter << endl;
        }else{
            cout << -1 << endl;
        }
    }




    return 0;
}
