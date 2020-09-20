/*
Minhazul Hayat Khan
Website: www.minhazul.com
EWU, Bangladesh
Problem Name:
Problem Link:
Date : 04 / 07 / 2020
Comment:
*/
#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
class Node{
    protected:
        string tag;
        Node(string tag):tag(tag){};
    public:
        virtual ~Node(){};
        virtual string InnerHTML(){};
        virtual string GetHTML(){};
};

class Leaf : public Node{
    private:
        string value;
    public:
        Leaf(string tag,string value):Node(tag), value(value){}
        string  InnerHTML() {
            return value;
        }
        string GetHTML() {
            stringstream ss;
            ss << "\t<"<<tag <<">" << value <<"</"<<tag <<">"<< endl;
            return ss.str();
        }
};
class Container : public Node{
    private:
        vector<Node*> nodes;
    public:
        Container(string tag):Node(tag){}
        Container(string tag, vector<Node*> nodes):Node(tag), nodes(nodes){}
        string  InnerHTML() {
            stringstream ss;
            for(int i=0;i<nodes.size();i++){
                ss << nodes[i]->GetHTML();
            }
            return ss.str();
        }
        string GetHTML() {
            stringstream ss;
            ss << "<"<<tag <<">" << endl;
            ss << "" << InnerHTML();
            ss << "</"<<tag <<">"<< endl;
            return ss.str();
        }
        void AddNode(Node *node){
            nodes.push_back(node);
        }
        void RemoveNode(Node *node){
            for(int i=0;i<nodes.size();i++){
                if(nodes[i] == node){
                    nodes.erase(nodes.begin()+i);
                    break;
                }
            }
        }
};
void toast(string msg){
    cout << "----------"<<msg<<"----------" << endl;
}
int main(){
    Leaf *span = new Leaf("span", "Hello World");
    toast("Primary setup for leaf");
    toast("InnerHTML");
    cout << span->GetHTML() << endl;
    toast("GetHTML");
    cout << span->GetHTML() << endl;
    toast("Primary Setup for Leaf ended");
    vector<Node*> lis;
    lis.push_back(new Leaf("li", "one"));
    lis.push_back(new Leaf("li", "two"));
    lis.push_back(new Leaf("li", "three"));
    Container *ul = new Container("ul", lis);

    toast("Primary setup for Container");
    toast("InnerHTML");
    cout << ul->InnerHTML() << endl;
    toast("GetHTML");
    cout << ul->GetHTML() << endl;
    toast("Primary Setup for Container ended");
    Node *newLi = new Leaf("li", "four");


    ul->AddNode(newLi);
    toast("After adding additional node");
    cout << ul->GetHTML() << endl;

    ul->RemoveNode(newLi);
    toast("After removing additional node");
    cout << ul->GetHTML() << endl;


    toast("Output");
    Container *div = new Container("div");
    div->AddNode(new Leaf("span", "Heading"));
    div->AddNode(new Leaf("p", "Lorem ipsum dolor ismet…"));
    div->AddNode(ul);
    cout << div->GetHTML() << endl;
    return 0;
}
