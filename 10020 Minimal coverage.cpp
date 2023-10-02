#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int M;
		cin >> M;
		int L,R;
		vector<pair<int,int>> v;
		while(cin >> L >> R){
			if(L == 0 && R == 0)
				break;
			pair<int,int> p = {L,R};
			v.push_back(p);
		}
		sort(v.begin(),v.end());
		vector<pair<int,int>> ans;
		int nowL = 0;
		int i = 0;
		while(nowL < M){
			int maxR = 0,maxpos = -1;
			bool find = false;
			for(;i<v.size();i++){
				if(v[i].first <= nowL){
					find = true;
					if(v[i].second > maxR){
						maxR = v[i].second;
						maxpos = i;
					}
				}
				else{
					break;
				}
			}
			if(!find)
				break;
			else{
				ans.push_back(v[maxpos]);
				nowL = maxR;
			}
		}
		if(nowL >= M){
			cout << ans.size() << endl;
			for(auto p:ans){
				cout << p.first << " " << p.second << endl;
			}
		}
		else{
			cout << 0 << endl;
		}
		if(t)
			cout << endl;
	}
}
