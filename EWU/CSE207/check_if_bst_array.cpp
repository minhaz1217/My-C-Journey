#include<bits/stdc++.h>
using namespace std;
int main(){
    int height, nodes,n;
    cout << "What is the height of the tree: ";
    cin >> height;
    nodes = pow(2,height+1) -1;
    cout << nodes << endl;
    int arr[nodes+1], i;

    for(i=1;i<=nodes;i++){
        cin >> arr[i];
    }
    int flag = 1;
    for(i=1;i<=height+1;i++){
        if(   !(arr[i]<= arr[2*i+1] && arr[i] > arr[2*i])){
           //cout << "Not bst" << endl;
            flag =0;
            break;
        }
    }
    if(flag == 0){
        cout << "NOT BST" << endl;
    }else{
        cout << "BST" << endl;
    }




    /*
    cout << "Enter 0: ";
    cin >> n;
    head = NULL;
    head = createTree(head, n);

    for(i=1;i<nodes;i++){
        cout << "Enter " << i << " :";
        cin >> n;
        createTree(head, n);
    }
    cout << "PREFIX" << endl;
    prefix(head);
    checkIfBST(head);
    */
    return 0;
}
