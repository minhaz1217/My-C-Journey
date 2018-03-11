#include<bits/stdc++.h>
using namespace std;
#define MX 1002
int stock_prices[MX], nDay, marked[MX];
int getMaximum(int start, int end)
{
    int ret = -1, mx = 0;
    for(int i = start; i <= end; i++)
    {
        if(!marked[i] && mx <= stock_prices[i])
        {
            mx = stock_prices[i];
            ret = i;
        }
    }
    return ret;
}
int getMinimum(int start, int end)
{
    int ret = -1, mn = 1000000000;
    for(int i = start; i <= end; i++)
    {
        if(!marked[i] && mn > stock_prices[i])
        {
            mn = stock_prices[i];
            ret = i;
        }
    }
    return ret;
}
int optimalResult(int stock_prices[], int a, int b)
{
    int mm = 0, mn= 100000000;
    for(int i=a; i<=b; i++)
    {
        if(stock_prices[i] < mn)
        {
            mn = stock_prices[i];
        }
        if(stock_prices[i] > mm)
        {
            mm = stock_prices[i];
        }
    }
    return mm - mn;
}


int getProfit(int start, int end)
{
    int profit = 0, i;
    for(i = start; i <= end; i++) marked[i] = 0;
    while(1)
    {
        int X = getMaximum(start, end);
        int Y = getMinimum(start, X - 1);
        if(X==-1 || Y==-1)break;
        profit += stock_prices[X] - stock_prices[Y];
        marked[X] = marked[Y] = 1;
        //cout << ("HI") << endl;
    }
    return profit;
}


bool check(int stock_prices[], int nDay)
{
    int k;
    for(k = 1 ; k <= nDay - 4 ; k++ )
    {
        int X = getProfit(1, k);
        int Y = optimalResult(stock_prices, 1, k);
        if(X != Y)
        {
            cout << X << ": " << Y << endl;
            return false;
        }
    }
    return true;
}


int main()
{
    int i;
    int nDay =110;
    int s = 1;
    cout << nDay << endl;

    /*
    for(i=1;i<=nDay;i++){
        s +=2;
        stock_prices[i] = s;
    }
    */

    for(i=1; i<=nDay; i++)
    {
        s+=0;
        stock_prices[i]= s;
    }
    stock_prices[2]= 10;

    for(i=1; i<=nDay; i++)
    {
        cout << stock_prices[i] << " ";
    }
    cout << endl;
    /*
    cout << "CHECK: "<< check(stock_prices, nDay) << endl;
    cout << "CHECK2: "<< optimalResult(stock_prices,1, nDay) << endl;
    int profit = getProfit(1, nDay);
    printf("Profit: %d\n", profit);
    */
    return 0;
}

