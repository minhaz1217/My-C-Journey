// Dynamic Programming code for Optimal Binary Search
// Tree Problem
#include<bits/stdc++.h>
using namespace std;
#define MX 1000
#define INFINITY 999999

#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;

int p[MX] = {0},q[MX] = {0}, number;
int root[MX][MX];
int tree[MX];
int createTree(int rt, int l, int r, int keys[]){

    int n = sizeof(keys)/sizeof(keys[0]);
    msg("N: ", n)
    int temp, curr;
    cout << l << " : " << r << endl;
    if(l==r){
        return l;
    }else{
        temp = root[l][r];
        tree[2*rt] = keys[createTree(temp, l, temp-1, keys)];
        tree[2*rt+1] = keys[createTree(temp, temp+1, r, keys)];
    }
    return root[l][r];
}



void obst(int n){
    int i,j,k,l,r,temp;
    int e[n+2][n+1] = {0} , w[n+2][n+1] = {0};

    //Initialize all to zeros
    for(i=0;i< n+2;i++){
        for(j=0;j<n+1;j++){
            e[i][j] = 0;
            w[i][j] = 0;
        }
    }
    for(i=0;i< n+1;i++){
        for(j=0;j<n+1;j++){
            root[i][j] = 0;
        }
    }


    for(i=1;i<=n+1;i++){
        e[i][i-1] = 0;
        //e[i][i-1] = q[i-1];
        w[i][i-1] = 0;
        //w[i][i-1] = q[i-1];
    }
    for(l=1;l<= n;l++){
        for(i=1;i<=n-l+1;i++){
            j = i+l-1;
            e[i][j] = INFINITY;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            for(r=i;r<=j;r++){
                temp = e[i][r-1] + e[r+1][j] + w[i][j];
                if(temp < e[i][j]){
                    e[i][j] = temp;
                    root[i][j] = r;
                }
            }
        }
    }
    for(i=1;i<=n+1;i++){
        for(j=1;j<=n;j++){
            printf("%2d( %d ) ", e[i][j],root[i][j]);
        }
        cout << endl;
    }
/*
    for(i=1;i<=n;i++){
        if()
    }
*/
}






// A utility function to get sum of array elements
// freq[i] to freq[j]
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
       s += freq[k];
    return s;
}

// Driver program to test above functions
int main()
{
    int i;
    int keys[] = {0, 1,2,3,4,5};
    //int freq[] = {0, 34, 8, 50, 20, 25, 19};
    int freq[] = {0, 15,10,5,10,20};
    int n = sizeof(freq)/sizeof(freq[0])-1;
    for(int i=0;i<n;i++){
        p[i] = freq[i];
    }
    obst(n);
    tree[1] = root[1][n];
    createTree(1, 1, n, keys);
    for(i=1;i<=n;i++){
        cout << tree[i] << endl;
    }
    //printf("Cost of Optimal BST is %d ", optimalSearchTree(keys, freq, n));

    return 0;
}
