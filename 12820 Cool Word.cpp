#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main()
{
	int c = 0;
	int t;
	while(cin >> t){
		++c;
		string s;
		int cnt = 0;//count cool word
		for(int i=0;i<t;++i){
			bool ifcool = true;
			vector<int> f(26,0);
			set<int> check;
			cin >> s;
			for(int j=0;j<s.length();++j){
				f[s[j]-'a']++;
			}
			for(int i=0;i<26;++i){
				if(f[i] == 0)
					continue;
				if(check.count(f[i]) == 1)
					ifcool = false;
				else
					check.insert(f[i]);
			}
			if(check.size() <= 1)
				ifcool = false;
			if(ifcool)
				cnt++;
		}
		cout << "Case " << c << ": " << cnt << endl;
	}
} 
