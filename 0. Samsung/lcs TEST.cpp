/* Dynamic Programming implementation of LCS problem */
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs( char *X, char *Y, int n, int m)
{
    int L[n+4][m+4];
    cout << "PRint X" << endl;
    for(int i=0; i<n; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
    cout << "PRint Y" << endl;

    for(int i=0; i<m; i++)
    {
        cout << Y[i] << " ";
    }
    cout << endl;
    cout << n << "  " << m << endl;
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
    	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (int i=0; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    cout << "PRINT LCS" << endl;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout << L[i][j]<< " ";
        }
        cout << endl;
    }
// Following code is used to print LCS
    int index = L[n][m];

// Create a character array to store the lcs string
    char lcs[index+1];
    lcs[index] = '\0'; // Set the terminating character

// Start from the right-most-bottom-most corner and
// one by one store characters in lcs[]
    int i = n, j = m;
    cout << i << " -> " << j << endl;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (X[i-1] == Y[j-1])
        {
            cout << "HI " << X[i-1] << endl;
            lcs[index-1] = X[i-1]; // Put current character in result
            i--;
            j--;
            index--;	 // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }
    cout << "RESULT  " << L[n][m] << endl;
// Print the lcs
    cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

/* Driver program to test above function */
int main()
{
    char X[] = "2316546";
    char Y[] = "1356";
    int n = strlen(X);
    int m = strlen(Y);
    cout << n << " " << m << endl;
    lcs(X, Y, n, m);
    return 0;
}
