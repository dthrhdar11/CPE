#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
using namespace std;
int cmp(pair<int,int> a,pair<int,int> b){
	if(a.second == b.second){
		return a.first > b.first;
	}
	else{
		return a.second < b.second;
	}
}
int main(){
	string s;
	int cnt = 0;
	while(getline(cin,s)){
		if(cnt > 0)
			cout << endl;
		cnt++;
		vector< pair<int,int> > v;
		map<int,int> mp;
		for(int i=0;i<s.length();i++){
			int ASCval = (int)s[i];
			mp[ASCval]++;
		}
		for(auto p:mp){
			v.push_back({p.first,p.second});
		}
		sort(v.begin(),v.end(),cmp);
		for(auto p:v){
			cout << p.first << " " << p.second << endl;
		}
	}
}
