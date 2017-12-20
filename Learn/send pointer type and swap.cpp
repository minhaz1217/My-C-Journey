#include<bits/stdc++.h>
using namespace std;
#define check(a) cout << a << endl;
#define msg(a,b) cout << a << " : " << b << endl;
struct Node{
    int data;
    Node *next;
};
void checking(Node **d){
    cout << &*d << endl;
    curr = new Node;
    curr ->data = 10;
    *&*d = curr;
    cout << &*d << endl;
}

int main(){
    Node *d;
    checking(&d);

    return 0;
}
