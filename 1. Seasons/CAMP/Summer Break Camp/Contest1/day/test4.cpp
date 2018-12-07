#include<iostream>
using namespace std;
#define msg(a,b) cout << a << " : " << b << endl;
#define check(a) cout << a << endl;
bool gl;
class nod
{
public:
    nod *child[10];
    bool wordEnded;
    nod()
    {
        for(int i=0; i<10; i++)
        {
            child[i]= NULL;
        }
        wordEnded = false;
    }
};
void del(nod* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->child[i])
            del(cur->child[i]);
    delete (cur);
}
void push(nod *root, string s)
{
    nod *tmp = root;
    for(int i=0; s[i]; i++)
    {
        if(tmp->wordEnded == true)
        {
            gl = false;
            break;
        }
        if(tmp->child[s[i] -'0'] == NULL)
        {
            tmp->child[s[i] - '0'] = new nod();
        }
        tmp = tmp->child[s[i] - '0'];
    }
    tmp->wordEnded = true;
    tmp = root;
    /*
    for(int i=0;s[i];i++){
        tmp = tmp->child[s[i] - '0'];
        msg(s[i], tmp->wordEnded);
    }
    */
    return;
}
int main()
{
    int i, tc,n, flag,caseCounter = 1;
    string str;
    cin >> tc;
    while(tc--)
    {
        gl = true;
        nod *root;
        root = new nod();
        cin >> n;
        while(n--)
        {
            cin >> str;
            if(gl){
                push(root, str);
            }
        }
        if(gl)
        {
            cout << "Case "<< caseCounter++ << ": YES" << endl;
        }
        else
        {
            cout << "Case "<< caseCounter++ << ": NO" << endl;
        }
        del(root);
    }
    return 0;
}
