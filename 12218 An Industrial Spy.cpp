#include<iostream>
#include<sstream>
#include<set>
#include<string>
#include<vector>
#define N 10000000
using namespace std;

vector<bool> p(N,true);
set<int> result;

void dfs(string str, string target, int now, int Max)//depth first search
{
	if (now == Max)
	{
		stringstream ss(target);
		int tmp;
		ss >> tmp;
		result.emplace(tmp);
		return;
	}
	for (size_t i = 0; i < str.size(); ++i)
	{
		string s = str;
		s.erase(s.begin() + i);
		dfs(s, target + str[i], now + 1, Max);
	}
}
int main()
{
	for(int i=2;i*i<=N;++i){
		for(int j=2*i;j<N;j+=i){
			p[j] = false;
		}
	}
	p[0] = p[1] = false;
	int n;
	cin >> n;
	while(n--){
		string str;
		cin >> str;
		result.clear();
		int cnt = 0;
		// use dfs to find all permutation of str
		for (size_t i = 1; i <= str.size(); ++i){ 
			dfs(str, "", 0, i);
		} 
		for (const int &i : result){
			if (p[i])
				++cnt;
		}
		cout << cnt << endl;
	}
}
