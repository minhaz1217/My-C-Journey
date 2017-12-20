#include<bits/stdc++.h>
using namespace std;

#define MAX_NODE 50
struct node{
    int vertex;
    int weight;
    node *next;
};

struct fringe_node{
    int vertex;
    fringe_node *next;
};

node *adj[MAX_NODE]; //For storing Adjacency list of nodes.
int totNodes; //No. of Nodes in Graph.
const int UNSEEN=1,FRINGE=2,INTREE=3; //status of node.

int status[MAX_NODE];//status arr for maintaing status.
fringe_node *fringe_list;//singly link list
void createGraph(){
    node *newl,*last;
    int neighbours;
    cout<<"\n\n---Graph Creation---\n\n";
    cout<<"Enter total nodes in graph : ";
    cin>>totNodes;
    for(int i=1;i<=totNodes;i++){
        last=NULL;
        cout<<"Total Neighbours of "<<i<<" : ";
        cin>>neighbours;
        for(int j=1;j<=neighbours;j++){
            newl=new node;
            cout<<"Neighbour #"<<j<<" : ";
            cin>>newl->vertex;
            cout<<"Weight    #"<<j<<" : ";
            cin>>newl->weight;
            newl->next=NULL;
            if(adj[i]==NULL)
                adj[i]=last=newl;
            else{
                last->next = newl;
                last = newl;
            }
        }
    }
}

//Insert node in a fring_list at Begining.
void Insert_Beg(int item){
      fringe_node *newl;
      newl = new fringe_node;
      newl->vertex = item;
      newl->next = NULL;
      newl->next = fringe_list;
      fringe_list = newl;
}

//Delete element at pos position from fringe_list.
void del(int pos){
   //to points to previous node from where//to insert
   int i;
   fringe_node *tmp,*delnode;
   for(i=1,tmp=fringe_list; i < (pos-1); tmp=tmp->next,i++);

   delnode = tmp->next;
   tmp->next = tmp->next->next;
   delete(delnode);
}

void print_path(int s,int d,int parent[]){
    if(d==s)
       cout<<"    "<<s;
    else{
       print_path(s,parent[d],parent);
       cout<<"-->"<<d;
    }
}

void shortestPath(){
    int i,x,parent[MAX_NODE],edge_count,w,wt,v;
    int min_dist,y,dist[MAX_NODE],stuck;
    int source,destination;
    node *ptr1;
    fringe_node *ptr2;

    cout<<"Enter Source Node : ";
    cin>>source;
    cout<<"Enter Destination Node : ";
    cin>>destination;

    fringe_list=NULL;
    for(i=1;i<=totNodes;i++){
        status[i]=UNSEEN;
        parent[i]=0;
    }

    status[source]=INTREE;
    dist[source]=0;
    x=source;
    stuck=0;
    while( (x != destination) && (!stuck))
    {
        ptr1=adj[x];
        while(ptr1!=NULL){
            y=ptr1->vertex;
            wt=ptr1->weight;
            if((status[y]==FRINGE) && (dist[x]+wt < dist[y]))
            {
                parent[y]=x;
                dist[y] = dist[y] + wt;
            }
            else if(status[y]==UNSEEN){
                status[y]=FRINGE;
                parent[y]=x;
                dist[y] = dist[y] + wt;
                Insert_Beg(y);
            }
            ptr1=ptr1->next;
        }
        if(fringe_list==NULL)
            stuck=1;
        else{
            x=fringe_list->vertex;
            min_dist=dist[x];
            ptr2=fringe_list->next;
            while(ptr2!=NULL){
                w=ptr2->vertex;
                if(dist[w] < min_dist)
                {
                    x=w;
                    min_dist=dist[w];
                }
                ptr2=ptr2->next;
            }
            del(x);
            status[x]=INTREE;
        }
    }
    if(parent[destination]==0)
        cout<<"No path from "<<source<<" to "<<destination;
    else
    {
        cout<<"\n\nShortest Path\n";
        print_path(source,destination,parent);
    }
}


int main(){
    //clrscr();
    cout<<"*****Minimum Spaning Tree (MST)*****\n";
    createGraph();
    cout<<"\n===Minimum Spaning Tree===\n";
    shortestPath();
    //getch();
    return 0;
}
