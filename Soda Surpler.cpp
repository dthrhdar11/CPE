#include<iostream>
using namespace std;
int main()
{
	int times;
	cin >> times;
	for(int i=0;i<times;i++){
		int e,f,c;
		cin >> e >> f >> c;
		int left = e+f;
		int temp = 0;
		int extra = 0;
		while(left>=c){
			temp = left / c;
			extra += temp;
			left = temp + (left - temp*c);
		}
		cout << extra << endl;
	}
}
