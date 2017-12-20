# include <iostream>
# include <cstdio>
# include <string>
# include <vector>
# include <map>
using namespace std;
# define MAX 20000
int main(){
    int t, m;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        map <string, int> ma;
        vector <int> v[MAX];
        int Assign = 0, x, y;
        scanf("%d", &m);
        string a, b;
        for(int j = 0; j < m; j++){
            cin >> a >> b;
            if(ma.find(a) == ma.end()){
                ma[a] = Assign;
                Assign++;
            }
            if(ma.find(b) == ma.end()){
                ma[b] = Assign;
                Assign++;
            }
            x = ma[a];
            y = ma[b];
            v[y].push_back(x);
        }
        int yes = 1;
        for(int j = 0; j < Assign; j++){
            int len = v[j].size();
            for(int k = 0; k < len; k++){
                int pre = v[j][k];
                int len2 = v[pre].size();
                for(int z = 0; z < len2; j++){
                    if(v[pre][z] == j){
                        yes = 0;
                        break;
                    }
                }
                if(yes == 0){
                    break;
                }
            }
            if(yes == 0){
                break;
            }
        }
        if(yes == 1){
            printf("Case %d: Yes\n", i);
        }
        else{
            printf("Case %d: No\n", i);
        }
    }
    return 0;
}
