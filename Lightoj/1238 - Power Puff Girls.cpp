#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

char arr[60][60];
int h,w,x,y,counter,aa[2],bb[2],cc[2],hh[2];



void display()
{

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }

}
void clr()
{

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            arr[i][j] = '#';
        }
    }

}
bool checked(int s1, int s2, char c){
    char tmp = arr[s1][s2];
    if(arr[s1][s2] == c){
        return 1;
    }else if(tmp == 'a' || tmp=='b' || tmp == 'm' || tmp =='c' || tmp == 'h'){
        return 1;
    }else{
        return 0;
    }
}



int bfs(int s1,int s2){

    int counter = 0,i,j,a,b,cc1,cc2;
    queue<pair<int, int> >q;
    int visited[60][60], level[60][60] = {0},cost[60][60]={0};




    for(i=0;i<60;i++){
        for(j=0;j<60;j++){
            visited[i][j] = 0;
        }
    }

    q.push(pair<int,int>(s1,s2));
    cost[s1][s2] = 0;
    while(!q.empty()){
        a = q.front().first;
        b = q.front().second;
        visited[a][b] =1;
        q.pop();
        counter++;
        /*
        a+1 b
        a-1 b
        a b+1
        a b-1
        */

        if(checked(a,b,'h')){
            cost[a][b] = cost[a][b] + 1;
            break;
        }

        cc1 = a+1;
        cc2 = b;
        if(cc1 <= h){
            if(checked(cc1, cc2, 'h')){
                cost[cc1][cc2] = cost[a][b] + 1;
                break;
            }else if(checked(cc1,cc2,'.') && !visited[cc1][cc2]){
                q.push(pair<int,int>(cc1,cc2) );
                cost[cc1][cc2] = cost[a][b] + 1;
            }
        }
        cc1 = a-1;
        cc2 = b;
        if(a-1 >=0){
            if(checked(cc1, cc2, 'h')){
                cost[cc1][cc2] = cost[a][b] + 1;
                break;
            }else if(checked(cc1,cc2,'.') && !visited[cc1][cc2]){
                q.push(pair<int,int>(cc1,cc2) );
                cost[cc1][cc2] = cost[a][b] + 1;
            }

        }
        cc1 = a;
        cc2 = b+1;
        if(b+1 <= w){
            if(checked(cc1, cc2, 'h')){
                cost[cc1][cc2] = cost[a][b] + 1;
                break;
            }else if(checked(cc1,cc2,'.') && !visited[cc1][cc2]){
                q.push(pair<int,int>(cc1,cc2) );
                cost[cc1][cc2] = cost[a][b] + 1;
            }

        }
        cc1 = a;
        cc2 = b-1;
        if(b-1 >=0){
            if(checked(cc1, cc2, 'h')){
                cost[cc1][cc2] = cost[a][b] + 1;
                break;
            }else if(checked(cc1,cc2,'.') && !visited[cc1][cc2]){
                q.push(pair<int,int>(cc1,cc2) );
                cost[cc1][cc2] = cost[a][b] + 1;
            }
        }
    }
    //msg("HI: ", counter)
    msg(a, b);
    return cost[hh[0]][hh[1]];
}

int main()
{

    int tc,i,j,caseCounter=1;

    cin >> tc;
    while(tc--)
    {
        clr();
        cin >> h >> w;
        for(i=0; i<h; i++)
        {
            for(j=0; j<w; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j] == 'a'){
                    aa[0] = i;
                    aa[1] = j;
                }else if(arr[i][j] == 'b'){
                    bb[0] = i;
                    bb[1] = j;
                }else if(arr[i][j] == 'c'){
                    cc[0] = i;
                    cc[1] = j;
                }else if(arr[i][j] == 'h'){
                    hh[0] = i;
                    hh[1] = j;
                }
            }
        }
        cout << "Case "<< caseCounter++ << ": ";

        cout << bfs(cc[0], cc[1]) << endl;
        cout << bfs(bb[0], bb[1]) << endl;
        cout << bfs(aa[0], aa[1]) << endl;


        //cout << max( bfs(aa[0],aa[1]) , max( bfs(bb[0],bb[1]) , bfs(cc[0],cc[1]) ))  << endl;


        //cout << "Case "<< caseCounter++ << ": " << counter<< endl;

        //cout << counter <<endl;
    }



    return 0;
}
