#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int S;
		cin >> S;
		double p;
		cin >> p;
		double np = 1-p;
		int I;
		cin >> I;
		
		if(p == 0){
			cout << "0.0000" << endl;
			continue;
		}
		double top = p*pow(np,I-1);
		double bot = (1-pow(np,S));
		cout << fixed << showpoint << setprecision(4) << top/bot << endl;
	}
}
