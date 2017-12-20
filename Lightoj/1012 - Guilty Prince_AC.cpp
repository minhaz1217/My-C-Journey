#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

char arr[25][25];
int h,w,x,y,counter;



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
void bfs()
{
    int a,b;
    counter = 0;

    //cout << arr[x][y] << endl;
    queue<pair<int, int> >q;
    q.push(pair<int,int>(x,y));
    while(!q.empty())
    {
        a= q.front().first;
        b = q.front().second;
        //msg(a,b)
        q.pop();
        counter++;
        if(b-1 >= 0 && arr[b-1][a] == '.')
        {
            arr[b-1][a] = '#';
            q.push(pair<int, int>(a, b-1));
        }
        if(b+1 <= h && arr[b+1][a] == '.')
        {
            arr[b+1][a] = '#';
            q.push(pair<int, int>(a, b+1));
        }
        if(a-1 >= 0 && arr[b][a-1] == '.')
        {
            arr[b][a-1] = '#';
            q.push(pair<int, int>(a-1, b));
        }
        if(a+1 <= w && arr[b][a+1] == '.')
        {
            arr[b][a+1] = '#';
            q.push(pair<int, int>(a+1, b));
        }
        //display();
//        msg(q.front().first, q.front().second)
        //cout << endl;
    }
}

int main()
{

    int tc,i,j,caseCounter=1;

    cin >> tc;
    while(tc--)
    {
        clr();
        cin >> w >> h;
        for(i=0; i<h; i++)
        {
            for(j=0; j<w; j++)
            {
                cin >> arr[i][j];
                if(arr[i][j] == '@')
                {
                    x = j;
                    y = i;
                }
            }
        }
        bfs();

        cout << "Case "<< caseCounter++ << ": " << counter<< endl;

        //cout << counter <<endl;
    }



    return 0;
}
