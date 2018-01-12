#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
// custom code start

class LRUCache: public Cache{
    int arr[1001][2];
    int currentItems;
    int myCap;
    public:
    LRUCache(int cap){
        myCap = cap;
        currentItems =0;
        //arr = new int [cap];

        for(int i=0;i<1001;i++){
            arr[i][0] = 0;
        }

        /*
        cp = cap;
        mp = new map<int cap, Node *nd()>;
        */
    }
    void set(int a,int b){
        /*
        arr[currentItems][0] = a;
        arr[currentItems][1] = b;
        currentItems++;
        */
        arr[a-1][0] = b;
        //currentItems += 1;
    }
    int get(int a){
        if(arr[a-1][0] == 0){
            return -1;
            //cout << arr[a-1][0] << endl;
        }else if(arr[a-1]){
            return arr[a-1][0];
        }else{
            return -1;
            //cout << -1 << endl;
        }

    }

};

//custom code end

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}



