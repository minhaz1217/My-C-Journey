# include <iostream>
# include <fstream>
using namespace std;
int main(){
    ifstream in("text.txt");

    if(!in){
        cout << "Can't open file" << endl;
        cout << in << endl;
    }else{
        while(in){
            char ch;
            in.get(ch);
            if(in){
                cout << ch << endl;
                cout << "in: " << in.rdbuf()<< endl;
            }
        }
        in.close();
    }
}
