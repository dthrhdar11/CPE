#include<iostream>
#include<string>
#include<map>
using namespace std;
void findway(string& ans,string nowstr,char end,map<char,string> mp){
	if(nowstr[nowstr.length()-1] == end){
		ans = nowstr;
		return;
	}
	string next = mp[nowstr[nowstr.length()-1]];
	for(int i=0;i<next.length();i++){
		if(nowstr.find(next[i]) != string::npos){
			continue;
		}
		string nnstr = nowstr + next[i];
		findway(ans,nnstr,end,mp);
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int m,n;
		cin >> m >> n;
		map<char,string> mp;
		string a,b;
		for(int i=0;i<m;i++){
			cin >> a >> b;
			mp[a[0]] += b[0];
			mp[b[0]] += a[0];
		}
		/*for(auto p:mp){
			cout << p.first << " " << p.second << endl;
		}*/
		for(int i=0;i<n;i++){
			cin >> a >> b;
			string ans;
			string nowstr = "";
			nowstr += a[0];
			findway(ans,nowstr,b[0],mp);
			cout << ans << endl;
		}
		if(t)
			cout << endl;
	}
} 
