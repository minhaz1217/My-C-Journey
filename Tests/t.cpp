#include<bits/stdc++.h>
using namespace std;

int main(){
	int a;
	for(;;){
		cin >> a;
		if(cin.eof()){
			cout << "Eof detected." << endl;
			cout << cin.eof() << endl;
			break;
		}
		cout << a << endl;
	}
	return 0;
}

