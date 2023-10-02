#include<iostream>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;
int pow10(int n){
	int x = 1;
	for(int i=0;i<n;i++){
		x *= 10;
	}
	return x;
}
int main(){
	string s;
	while(cin >> s){
		if(s == "0")
			break;
		string real = s.substr(2,s.length()-5);
		int minup = INT_MAX, mindown = INT_MAX;
		for(int i=real.length()-1;i>=0;i--){
			//string cyclestr = real.substr(i,real.length()-i+1);
			string notcyclestr = real.substr(0,i);
			int notcycle = (notcyclestr.empty()) ? 0 : stoi(notcyclestr);
			int up = stoi(real) - notcycle;
			int down = pow10(real.length()) - pow10(notcyclestr.length());
			int GCD = __gcd(up,down);
			up /= GCD;
			down /= GCD;
			if(down < mindown){
				mindown = down;
				minup = up;
			}
		}
		cout << minup << "/" << mindown << endl;
	}
}
