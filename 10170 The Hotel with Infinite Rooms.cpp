#include<iostream>
using namespace std;
int main()
{
	long long S,D;
	while(cin >> S >> D){
		long long sum = 0;
		int i;
		for(i=S;sum<D;i++){
			sum += i;
		}
		cout << i-1 << endl;
	}
}
