#include <string>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string exp;
	int test;
	int sum=0;
	int d,b;
	cin >> test;
	while(test--){
		b=0;
		cin >> exp;
		const int len = exp.size();
		d=0;
		sum+=exp.size();
		for(int i=0;i<len;i++){
		if(exp.substr(i,1)==">")
			d--;
		else
			d++;
		if(d==0)
			b=i+1;
		else if(d<0)
			break;
		}
		cout << b << endl;
	}
return 0;
}
