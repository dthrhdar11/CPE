#include<string>
#include<iostream>
using namespace std;
int main()
{
	for(;;){
		string n;
		cin >> n;
		if(n == "0")
			break;
		int a=0;
		int b=0;
		for(int i=0;i<n.length();++i){
			if(i%2 == 0)
				a += n[i]-'0';
			else
				b += n[i]-'0';
		}
		
		if((a-b)%11 == 0)
			cout << n << " is a multiple of 11." << endl;
		else
			cout << n << " is not a multiple of 11." << endl;
	}
}
