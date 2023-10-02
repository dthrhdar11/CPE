#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	int t;
	cin >> t;
	int cnt = 0;
	while(t--){
		cnt++;
		string a,b;
		cin >> a >> b;
		int x = 0,y = 0;
		for(int i=0;i<a.length();i++){
			x = x*2 + (a[i]-'0');
		}
		for(int i=0;i<b.length();i++){
			y = y*2 + (b[i]-'0');
		}
		if(__gcd(x,y) == 1){
			cout << "Pair #" << cnt << ": Love is not all you need!" << endl;
		}
		else{
			cout << "Pair #" << cnt << ": All you need is love!" << endl;
		}
	}
}
