#include<iostream>
#include<queue>
using namespace std;
#define check(a) cout<<a<< endl;
#define msg(a,b) cout << a << " : " << b << endl;
int main(){
    queue<int> myQueue;
    int myInt;
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);
    myQueue.push(40);
    myQueue.push(50);
    myQueue.push(60);
    cout << "Queue Size: " << myQueue.size() << endl;
    cout << "Queue Front: " << myQueue.front() << endl;
    cout << "Queue Back: " << myQueue.back() << endl;
    myQueue.pop();
    cout <<"After pop Front: " <<  myQueue.front()<<endl;


    queue<pair<int, int> > qq;
    pair<int, int>p;
    qq.push(pair<int,int> (4,5));
    cout << qq.front().first << endl;
	return 0;
}

/*
Member function:
q.empty();  // return type
q.front();  // return type
q.front();  // return type
q.back();   // return type
q.push();   // return type
q.emplace();    // return type
q.pop();    // do type
q.swap(another queue of same type);   // do type. swaps all values with another queue


*/
