#define yy second
map<int,Node*>::iterator it;
class LRUCache:public Cache{
    public:
    LRUCache(){}
    LRUCache(int sz){cp=sz;head=tail=NULL;mp.clear();}
    void set(int a,int b){
        it=mp.find(a);
        if(it!=mp.end()){
            it->yy->value=b;
            return ;
        }
        if(cp==0){
            mp.erase(tail->key);
            tail=tail->prev;
            delete(tail->next);
            tail->next=NULL;

            Node* tp;
            tp=new Node(NULL,head,a,b);
            head->prev=tp;
            head=tp;
            mp[a]=tp;
            return ;
        }

        Node* tp;
        if(head!=NULL){
            tp=new Node(NULL,head,a,b);
            head->prev=tp;
        }else{
            tp=new Node(NULL,NULL,a,b);
            tail=tp;
        }
        head=tp;
        mp[a]=tp;
        cp--;
    }
    int get(int a){
        it=mp.find(a);
        if(it==mp.end())return -1;
        if(it->second==head)return head->value;

        it->second->prev->next=it->second->next;
        if(it->second->next==NULL){
            tail=it->second->prev;
            it->second->prev=NULL;
            it->second->next=head;
            head->prev=it->second;
            head=it->second;
        }else{
            it->second->next->prev=it->second->prev;
            it->second->prev=NULL;
            it->second->next=head;
            head->prev=it->second;
            head=it->second;
        }
        return head->value;
    }
};
