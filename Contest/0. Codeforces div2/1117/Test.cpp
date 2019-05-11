
#include <bits/stdc++.h>
using namespace std;

// C++ implementation to find longest increasing subsequence
// in O(n Log n) time.
// Binary search
int GetCeilIndex(vector<int>arr, vector<int> &T, int l, int r,int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l)/2;
        if (arr[T[m]] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}

int LongestIncreasingSubsequence(vector<int> arr, int n)
{
    // Add boundary case, when array n is zero
    // Depend on smart pointers

    vector<int> tailIndices(n, 0); // Initialized with 0
    vector<int> prevIndices(n, -1); // initialized with -1

    int len = 1; // it will always point to empty location
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[tailIndices[0]])
        {
            // new smallest value
            tailIndices[0] = i;
        }
        else if (arr[i] >= arr[tailIndices[len-1]])
        {
            // arr[i] wants to extend largest subsequence
            prevIndices[i] = tailIndices[len-1];
            tailIndices[len++] = i;
        }
        else
        {
            // arr[i] wants to be a potential condidate of
            // future subsequence
            // It will replace ceil value in tailIndices
            int pos = GetCeilIndex(arr, tailIndices, -1,
                                   len-1, arr[i]);

            prevIndices[i] = tailIndices[pos-1];
            tailIndices[pos] = i;
        }
    }

    cout << "LIS of given input" << endl;
    for (int i = tailIndices[len-1]; i >= 0; i = prevIndices[i])
        cout << arr[i] << " ";
    cout << endl;

    return len;
}

int main()
{
    vector<int> v;


    v.push_back(6);
    v.push_back(1);
    v.push_back(6);
    v.push_back(6);
    v.push_back(0);
    v.push_back(0);
    /*
    long long int n,a;
    cin >> n;
    while(n--){
        cin >> a;
        v.push_back(a);
    }
    */
    cout << "Length of Longest Increasing Subsequence is " << LongestIncreasingSubsequence(v,v.size()) << 'n';
/*
LIS of given input
13 10 8 7 3 2
Length of Longest Increasing Subsequence is 6n
*/
    return 0;
}
