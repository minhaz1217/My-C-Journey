#include<iostream>
using namespace std;
int main()
{
    int stock_prices[200];
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
