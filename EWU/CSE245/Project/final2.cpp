#include <bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;


#define MX 1000
#define INFINITY 999999

struct tree
{
    int key;
    struct tree *left, *right;
};
int e[MX][MX] = {0};
int w[MX][MX] = {0};
int root[MX][MX] = {0};
int q[MX];
int p[MX];
int keys[MX];
tree *obst;
void OBSTwithDecoys(int n)
{
    int i,j,k,l,r,temp;

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

    //Construct weight matrix W
    for(i = 1; i <= n+1; i++)
    {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
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
    cout << "The cost matrix: " << endl;
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n;j++){
            printf("%3d ", e[i][j]);
            //cout << cost[i][j];
        }
        cout << endl;
    }
    cout << "The root matrix: " << endl;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            printf("%3d ", root[i][j]);
            //cout << cost[i][j];
        }
        cout << endl;
    }

}
void OBSTwithoutDecoys(int n){

    int i,j,k,l,r,temp;
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
    cout << "The cost matrix: " << endl;
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n;j++){
            printf("%3d ", e[i][j]);
            //cout << cost[i][j];
        }
        cout << endl;
    }
    cout << "The root matrix: " << endl;
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            printf("%3d ", root[i][j]);
            //cout << cost[i][j];
        }
        cout << endl;
    }
}
//Construct the optimal binary search tree
tree *buildTree(int i, int j)
{
    cout << i << " : " << j << endl;
    tree *curr;
    if(i == j){
        curr = NULL;
    }else if(j<=0){
        return NULL;
    }else{
        curr = new tree;
        curr->key = keys[root[i][j]];
        curr->left = buildTree(i, root[i][j] - 1);
        curr->right = buildTree(root[i][j], j);
    }
    if(curr != NULL) cout << curr->key << endl;
    return curr;
}
//Display the optimal binary search tree
void displayTree(tree *obst, int lr)
{
    int i;
    if(obst != NULL){
        printf("%d -> %d\n",lr,  obst->key);
        displayTree(obst->right, 2);
        displayTree(obst->left, 1);

    }
}
void DISPLAY(tree *ROOT, int nivel)
{
    int i;
    if(ROOT != 0)
    {
        DISPLAY(ROOT->right, nivel+1);
        for(i = 0; i <= nivel; i++)
            printf(" ");
        printf("%d\n", ROOT->key);
        DISPLAY(ROOT->left, nivel + 1);

    }
}

int main()
{
    int i, k, numberOfKeys, choice1;

    while(1){
        cout << "\nEnter the number of keys: ";
        cin >> numberOfKeys;
        cout << "\nSelect Option: " << endl;
        cout << "1. Build OBST with decoys(wrong searches)." << endl;
        cout << "2. Build OBST without decoys(wrong searches)." << endl;
        cout << "3. Exit." << endl;
        cin >> choice1;
        if(choice1 == 1){
            for(i = 1; i <= numberOfKeys; i++)
            {
                printf("Enter Key[%d]= ",i);
                cin >> keys[i];
                printf("Enter frequency for %d = ", keys[i]);
                cin >> p[i];
            }
            for(i = 0; i <= numberOfKeys; i++){
                printf("Enter Dummy Key[%d] = ", i);
                cin >> q[i];
            }
            OBSTwithDecoys(numberOfKeys);
            obst = buildTree(1,numberOfKeys);
            DISPLAY(obst, 0);
        }else if(choice1 == 2){
            for(i = 1; i <= numberOfKeys; i++)
            {
                printf("Enter Key[%d]= ",i);
                cin >> keys[i];
                printf("Enter frequency for %d = ", keys[i]);
                cin >> p[i];
            }
            OBSTwithoutDecoys(numberOfKeys);
            obst = buildTree(1,numberOfKeys);
            //DISPLAY(obst, 0);
        }else if(choice1 ==3){
            exit(0);
        }else{
            cout << "Please enter a valid number" << endl;
            continue;
        }
    }
    system("PAUSE");
}
