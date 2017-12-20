#include<iostream>
using namespace std;
template < class type>
class Stack{
private:
    type st[50];
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(type a){
        st[++top] = a;
    }
    type pop(){
        return st[top--];
    }
};
int main(){
    Stack<float> s1;
    s1.push(11.112F);
    s1.push(123.22F);
    s1.push(12112.323F);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
	return 0;
}
