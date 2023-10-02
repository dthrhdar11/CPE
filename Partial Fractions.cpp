#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int r,p,q;
		cin >> r >> p >> q;
		//first step:find the x value on x line
		float tempx = r/q;
		//second step:transfer x to an integer
		int x = (int)tempx;
		int result = INT_MAX;
		//step 3-1:consider the the x >= 1 or x <= -1
		if(x<0){
			for(int i=x;i<=0;i++){
				if((r-i*q) % p == 0){
					int y = (r-i*q)/p;
					int temp = abs(i) + abs(y);
					if(temp < result)
						result = temp;
				}
			}
		}
		else{
			for(int i=x;i>=0;i--){
				if((r-i*q) % p == 0){
					int y = (r-i*q)/p;
					result = abs(i) + abs(y);
				}
			}
		}
		//step 3-2: consider no result(result = INT_MAX)
		if(result == INT_MAX){
			for(int i=1;i<=INT_MAX;i++){
				if((r-i*q) % p == 0){
					int y = (r-i*q)/p;
					int temp = abs(i) + abs(y);
					if(temp < result)
						result = temp;
					break;
				}
			}
			for(int i=-1;i>=INT_MIN;i--){
				if((r-i*q) % p == 0){
					int y = (r-i*q)/p;
					int temp = abs(i) + abs(y);
					if(temp < result)
						result = temp;
					break;
				}
			}
		}
		cout << result << endl;
	} 
 } 
