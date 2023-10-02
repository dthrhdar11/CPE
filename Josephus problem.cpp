#include<iostream>
//#include<cmath>
using namespace std;
int main()
{
	int ppl;
	cout << "How many people?";
	cin >> ppl;
	cout << endl;
	int x = ppl;
	int m = 1;
	while(x!=1){
		x /= 2;
		m *= 2;
	}
	cout << "No."<< (1+2*(ppl-m)) << " will survive." << endl;
 }  
