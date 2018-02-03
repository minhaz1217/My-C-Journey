# include <bits/stdc++.h>
using namespace std;

# define pp pair <int, int>
# define mx 30
const int INF = INT_MAX;

class Prioritize{
public:
    bool operator () (const pp& p1, const pp& p2){
        return p1.second < p2.second;
    }
};

int main(){

    int n, c;
    char YorM, UorB, x, y, pos1, pos2;
    scanf("%d", &n);
    while(n != 0){
        int node = 0;
        map <char, int> m1;
        map <char, int> :: iterator it;
        map <int, char> m2;
        vector <pp> GforY[mx];
        vector <pp> GforM[mx];
        for(int i = 0; i < n; i++){
            scanf(" %c %c %c %c %d", &YorM, &UorB, &x, &y, &c);
            it = m1.find(x);
            if(it == m1.end()){
                m1[x] = ++node;
                m2[node] = x;
            }
            it = m1.find(y);
            if(it == m1.end()){
                m1[y] = ++node;
                m2[node] = y;
            }
            if(YorM == 'Y'){
                if(UorB == 'U'){
                    GforY[m1[x]].push_back(pp(m1[y], c));
                }
                else{
                    GforY[m1[x]].push_back(pp(m1[y], c));
                    GforY[m1[y]].push_back(pp(m1[x], c));
                }
            }
            else{
                if(UorB == 'U'){
                    GforM[m1[x]].push_back(pp(m1[y], c));
                }
                else{
                    GforM[m1[x]].push_back(pp(m1[y], c));
                    GforM[m1[y]].push_back(pp(m1[x], c));
                }
            }
        }
        scanf(" %c %c", &pos1, &pos2);
        it = m1.find(pos1);
        if(it == m1.end()){
            m1[pos1] = ++node;
            m2[node] = pos1;
        }
        it = m1.find(pos2);
        if(it == m1.end()){
            m1[pos2] = ++node;
            m2[node] = pos2;
        }
        int dis1[node+1];
        int dis2[node+1];
        for(int i = 1; i <= node; i++){
            dis1[i] = INF;
            dis2[i] = INF;
        }
        dis1[m1[pos1]] = 0;
        priority_queue <pp, vector <pp>, Prioritize> q1;
        q1.push(pp(m1[pos1], dis1[m1[pos1]]));
        while(!q1.empty()){
            int a = q1.top().first;
            q1.pop();
            int s = GforY[a].size();
            for(int i = 0; i < s; i++){
                int b = GforY[a][i].first;
                int w = GforY[a][i].second;
                if(dis1[b] > dis1[a] + w){
                    dis1[b] = dis1[a] + w;
                    q1.push(pp(b, dis1[b]));
                }
            }
        }
        dis2[m1[pos2]] = 0;
        priority_queue <pp, vector <pp>, Prioritize> q2;
        q2.push(pp(m1[pos2], dis2[m1[pos2]]));
        while(!q2.empty()){
            int a = q2.top().first;
            q2.pop();
            int s = GforM[a].size();
            for(int i = 0; i < s; i++){
                int b = GforM[a][i].first;
                int w = GforM[a][i].second;
                if(dis2[b] > dis2[a] + w){
                    dis2[b] = dis2[a] + w;
                    q2.push(pp(b, dis2[b]));
                }
            }
        }
        int ans = INF;
        vector <char> ansc;
        for(int i = 1; i <= node; i++){
            if(dis1[i] != INF && dis2[i] != INF){
                if(ans > dis1[i] + dis2[i]){
                    ans = dis1[i] + dis2[i];
                    ansc.clear();
                    ansc.push_back(m2[i]);
                }
                else if(ans == dis1[i] + dis2[i]){
                    ansc.push_back(m2[i]);
                }
            }
        }
        if(ans == INF){
            printf("You will never meet.\n");
        }
        else{
            printf("%d", ans);
            int s = ansc.size();
            sort(ansc.begin(), ansc.end());
            for(int i = 0; i < s; i++){
                printf(" %c", ansc[i]);
            }
            printf("\n");
        }
        scanf("%d", &n);
    }
    printf("\n");

}
