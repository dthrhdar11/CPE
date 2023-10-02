#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
//important
int gcd(int a,int b){
	if(a<b)
		swap(a,b);
	while(b!=0){
		a = a%b;
		swap(a,b);
	}
	return a;
}
int main()
{
	int N;
	while(cin >> N && N){
	int G=0;
	for(int i=1;i<N;i++){ 
		for(int j=i+1;j<=N;j++){
			G += gcd(i,j);
 		}
	}
	cout << G << endl;
}
}
