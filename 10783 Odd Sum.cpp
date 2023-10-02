#include<iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int c = 0;
	while(t--){
		++c; 
		int a,b;
		cin >> a >> b;
		int sum = 0;
		for(int i=a;i<=b;++i){
			if(i%2 == 1)
				sum += i;
		} 
		printf("Case %d: %d\n",c,sum);
	} 
}
