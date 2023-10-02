#include<iostream>
#include<map>
using namespace std;
int main(){
	int N;
	cin >> N;
	map<string,string> mp;
	cin.ignore(1);
	while(N--){
		string s1;
		string s2;
		getline(cin,s1);
		getline(cin,s2);
		mp[s1] = s2;
	}
	int Q;
	cin >> Q;
	cin.ignore(1);
	for(int i=0;i<Q;++i){
		string s;
		getline(cin,s);
		cout << mp[s] << endl;;
	}	
}
