#include<iostream>
#include<vector>
using namespace std;

string findans(vector<string> m,vector<int> l,vector<int> h,int price)
{
	int cnt = 0;
	string ans;
	for(int i=0;i<l.size();++i){
		if(price >= l[i] && price <= h[i]){
			ans = m[i];
			++cnt;
		}
	}
	
	if(cnt == 1)
		return ans;
	else
		return "UNDETERMINED";
}

int main()
{
	int t;
	cin >> t;
	int lcnt = t; 
	while(t--){
		int d;//no. of database
		cin >> d;
		vector<string> maker;
		vector<int> low;
		vector<int> high;
		string m;
		int l;
		int h;
		for(int i=0;i<d;++i){
			cin >> m >> l >> h;
			maker.push_back(m);
			low.push_back(l);
			high.push_back(h);
		}
		int q;//no. of query
		int p;
		string ans;
		cin >> q;
		for(int i=0;i<q;++i){
			cin >> p;
			ans = findans(maker,low,high,p);
			cout << ans << endl;
		}
		if(lcnt>1)
			cout << "\n";
			
		--lcnt;
	}
}
