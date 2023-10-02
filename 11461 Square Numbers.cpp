#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin >> a >> b){
		int cnt = 0;
		if(a==0 && b==0)
			break;
			
		for(int i=1;i*i<=b;++i){
			if(i*i >= a && i*i <= b)
				cnt++;
		}
		cout << cnt << endl;
	}
}
