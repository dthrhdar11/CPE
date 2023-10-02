#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
set<string> ans;
void dfs(string str,string target,int now,int max){
	if(now == max){
		ans.emplace(target);
		//cout << "ans:" << target << endl;
		return;
	}
	for(int i=0;i<str.size();++i){
		string s = str;
		for(int j=0;j<=i;++j){
			s.erase(s.begin());
		}
		//cout << s << endl;
		dfs(s,target+str[i],now+1,max);
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		ans.clear();
		string s;
		cin >> s; 
		if(s.length()<3){
			cout << "0" << endl;
			continue;
		}
		else{
			dfs(s,"",0,3);
			cout << ans.size() << endl;
		}
		/*for(const string &p:ans){
			cout << p << ' ';
		}*/
	}
}
