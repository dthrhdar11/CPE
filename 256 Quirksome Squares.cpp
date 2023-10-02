#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string fillZeroToString(int len,int s){
	string str = to_string(s);
	for(int i=str.length();i<len;i++){
		str = "0" + str;
	}
	return str;
}
int main(){
	int a;
	
	while(cin >> a){

		for(int i=0;i*i<pow(10,a);i++){
			int temp = pow(10,a/2);
			int r = i*i%temp;
			int l = i*i/temp;
			if((r+l)*(r+l) == i*i){
				cout << fillZeroToString(a,i*i) << endl;
			}
		}
	}
}
