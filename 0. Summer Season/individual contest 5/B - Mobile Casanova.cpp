#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define cc(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
#define msg2(a,b,c) cout << a << " : " << b << " : " << c << endl;

/*
long long int match(string  a, string b){
    for(i=0;a[i];i++){
        if(a[i] != b[i]){
            break;
        }
    }

}
*/
int main(){

    int tc,j,l,caseCounter=1;
    while(1){
        cin >> tc;
        if(tc == 0){
            break;
        }
        vector<string>vec;
        map<string, int>mp;
        string str,start;
        int i,a,b,counter;
        while(tc--){
            cin >> str;
            vec.push_back(str);
            //cc(str)
           // vec2.push_back(b);

        }
        cout << "Case " << caseCounter++ <<":"<< endl;
        //cc("HI")
        //sort(vec.begin(), vec.end());
        counter = 0;
        for(i=0;i<vec.size()-1;i++){
            stringstream ss(vec[i]);
            ss >> a;
            stringstream ss2(vec[i+1]);
            ss2 >> b;
            //msg(a,b)
            if(b == a+1){
                counter++;
                //cc(counter)
                if(counter==1){
                    start = vec[i];
                    //msg("ST", start)
                    //series.push_back(start);
                }
                mp[start] = counter;
                //msg(start, counter)
            }else{
                mp[vec[i]] = 0;
                counter = 0;
            }
        }
        string str1, str2;
        //cc("END\n\n")
        //for(i=0;i<vec.size();i++)cc(vec[i])

        for(i=0;i<vec.size();i++){
            //msg("HI", mp[vec[i]])
            if(mp[vec[i]] == 0){
                cout << vec[i] << endl;
            }else{
                str1 = vec[i];
                str2 = vec[i +mp[vec[i]]];
                //msg2("MY STRING", str1, str2)
                for(j=0;str1[j];j++){
                    if(str1[j] != str2[j]){
                        l = j;
                        break;
                    }
                }
                cout << str1 << "-";
                for(j=l;str2[j];j++){
                    cout << str2[j];
                }
                cout << endl;
                i+= mp[vec[i]];
            }
        }
        cout << endl;

    }
    return 0;
}
