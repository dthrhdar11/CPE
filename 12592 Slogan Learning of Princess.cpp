#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<string> first;
	vector<string> second;
	cin.ignore(1);
	while(N--){
		string s;
		getline(cin,s);
		first.push_back(s);
		getline(cin,s);
		second.push_back(s);
	}
	int Q;
	cin >> Q;
	cin.ignore(1);
	for(int i=0;i<Q;++i){
		string s;
		getline(cin,s);
		int pos = find(first.begin(),first.end(),s) - first.begin();
		cout << second[pos] << endl;
	}	
}
