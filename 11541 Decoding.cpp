#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	cin.ignore(1);
	int cnt = 0;
	while(t--){
		++cnt;
		int x;
		char c;
		string ans = "";
		c = getchar();
		while(c != '\n'){
			scanf("%d",&x);
			for(int i=0;i<x;++i){
				ans += c;
			}
			c = getchar();
		}
		cout << "Case " << cnt << ": " << ans << endl;
	} 
}
