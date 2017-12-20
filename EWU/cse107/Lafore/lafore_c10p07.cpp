#include<iostream>
using namespace std;
#define check(a) cout<<a<< endl;
class Person{
protected:
    string name;
public:
    void setName(){
        cout << "Enter name: ";
        cin >> name;
    }
    void printName(){
        cout << name << endl;
    }
    string getName(){
        return name;
    }
};

int main(){
    void bsort(Person **, int);
    Person *persPtr[100];
    int n = 0;
    char choice;
    do{
        persPtr[n] = new Person;
        persPtr[n]->setName();
        n++;
        cout << "Enter another(y/n)?: ";
        cin >> choice;
    }while(choice == 'y');
    cout << endl << "Unsorted List: \n";
    for(int j=0;j<n;j++){
        persPtr[j] -> printName();
    }
    bsort(persPtr, n);
    cout << endl << "Sorted List: " << endl;
    for(int j=0;j<n;j++){
        persPtr[j] -> printName();
    }
    cout << endl;
	return 0;
}

void bsort(Person ** pp, int n){
    void order(Person **, Person **);
    int j,k;
    for(j=0;j<n-1;j++){
        for(k=j+1;k<n;k++){
            order(pp+j, pp+k);
        }
    }
}
void order(Person **pp1, Person ** pp2){
    if((*pp1)->getName() > (*pp2)->getName()){
        Person *tempptr = *pp1;
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
}
