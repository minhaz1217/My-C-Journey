
#include <bits/stdc++.h>
using namespace std;
/// N Log(N) solution for LIS
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}


vector<int> lis(vector<int> const& a) {
    int n = a.size();
    vector<int> d(n, 1), p(n, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && d[i] < d[j] + 1) {
                d[i] = d[j] + 1;
                p[i] = j;
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (d[i] > ans) {
            ans = d[i];
            pos = i;
        }
    }

    vector<int> subseq;
    while (pos != -1) {
        subseq.push_back(a[pos]);
        pos = p[pos];
    }
    reverse(subseq.begin(), subseq.end());
    return subseq;
}
int main()
{
    vector<int> v;

    v.push_back(389);
    v.push_back(207);
    v.push_back(155);
    v.push_back(300);
    v.push_back(299);
    v.push_back(170);
    v.push_back(158);
    v.push_back(65);
    //v.push_back(6);
    /*
    long long int n,a;
    cin >> n;
    while(n--){
        cin >> a;
        v.push_back(a);
    }
    */
    reverse(v.begin(),v.end());
    vector<int>vv = lis(v);
    for(auto it: vv){
        cout << it << endl;
    }
    cout << "Length of Longest Increasing Subsequence is " << lis(v).size() << '\n';
/*
LIS of given input
13 10 8 7 3 2
Length of Longest Increasing Subsequence is 6n
*/
    return 0;
}
