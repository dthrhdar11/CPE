#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		long long x,y;
		cin >> x >> y;
		long long ans;
		ans = (y-1+y-x)*x/2;
		cout << ans << endl;
	}
} 
