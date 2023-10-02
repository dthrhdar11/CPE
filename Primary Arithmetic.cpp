#include<iostream>
using namespace std;
int main()
{
	int a=1,b=1;
	while(cin >> a >> b){
		if(a == 0 && b == 0)
		break;
		int count = 0;
		int carry = 0;
		int x = a;
		int y = b;
		while(x != 0 || y != 0){
			int x1 = x%10;
			int y1 = y%10;
			if(x1+y1+carry>9){
				++count;
				carry = 1;
			}
			else
				carry = 0;
			x /= 10;
			y /= 10;	
		}
		if(count == 0) 
		cout << "No carry operation." << endl;
		else if (count == 1)
			cout << "1 carry operation." << endl;
		else
			cout << count << " carry operations." << endl;
	}
}
