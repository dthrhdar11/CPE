#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int sum,dif;
		cin >> sum >> dif;
		
		if((sum+dif)%2 != 0 || sum < dif){
			cout << "impossible" << endl;
			continue;
		}
		
		int a = 0;
		int b = 0;
		a = (sum+dif)/2;
		b = sum - a;
		if(a<b)
			swap(a,b);
		cout << a << ' ' << b << endl;
	}
}
