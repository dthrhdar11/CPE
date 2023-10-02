#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	vector<string> country;
	set<string> s;
	string c;
	string name;//useless anyway
	for(int i=0;i<t;++i){
		cin >> c;
		getline(cin,name);
		country.push_back(c);
		s.insert(c);
	}
	for(const string &p:s){
		int cnt = 0;
		for(int i=0;i<country.size();++i){
			if(p == country[i])
				cnt++;
		}
		cout << p << " " << cnt << endl;
	}
}
