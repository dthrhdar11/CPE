#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		vector<int> days(N+1,0);
		int P;
		cin >> P;
		while(P--){
			int h;
			cin >> h;
			int x = h;
			while(x<=N){
				days[x] = 1;
				x += h;
			}
		}
		int ans = 0;
		for(int i=1;i<=N;++i){
			if(i%7 == 6 || i%7 == 0)
				continue;
			if(days[i])
				++ans;
		}
		cout << ans << endl;
	}
 } 
