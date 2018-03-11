# include <iostream>
# include <cstdio>
using namespace std;

int main()
{
    int p, q,y, res;
    scanf("%d %d %d", &p , &q, &y);
    res = ((p*5 + 2*q ) * 52 ) * y;
    printf("%d\n", res);
    return 0;
}
