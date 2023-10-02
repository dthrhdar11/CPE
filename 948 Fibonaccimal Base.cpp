#include<iostream>
#include<vector>
using namespace std;
vector<int> fib;
void getfib(){
	fib.push_back(1);
	fib.push_back(2);
	int f3 = 3;
	for(int i=0;f3 <= 100000000;++i){
		f3 = fib[i] + fib[i+1];
		if(f3 <= 100000000)
			fib.push_back(f3);
	}
}
void getans(string &s,int x){
	if(x == 0){
		s = "0";
		return;
	}
	bool ifstart = false;
	for(int i=fib.size()-1;i>=0;i--){
		if(fib[i] <= x){
			ifstart = true;
			s += "1";
			x -= fib[i];
		}
		else{
			if(ifstart)
				s += "0";
		}
	}
}
int main()
{
	getfib();
	int t;
	cin >> t;
	while(t--){
		int n;
		string s = "";
		cin >> n;
		getans(s,n);
		cout << n << " = " << s << " (fib)" << endl;
	}
}
