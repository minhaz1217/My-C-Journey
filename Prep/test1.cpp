#include <bits/stdc++.h>

using namespace std;

int main() {
	map<string,int> mp;
	string q,s;
	int n,p;
	cin >> n >> p;
	while(n--){
		cin >> q >> s;
		if(q == "I"){
			string ss = "";
			for(int i=0;i<s.size();i++){
				ss.push_back(s[i]);
				if(mp.find(ss) == mp.end()){
					mp[ss] = 1;
				}else{
					mp[ss]++;
				}
			}
		}else if(q == "Q"){
			int counter = 0;
			string ss = "";
			for(int i=0;i<s.size();i++){
				ss.push_back(s[i]);
    			if(mp.find(ss) != mp.end()){
    				counter+=mp[ss];
    			}
		    }
			cout << counter << endl;

		}
	}
	return 0;
}
