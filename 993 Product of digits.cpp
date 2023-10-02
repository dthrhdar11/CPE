#include<iostream>
using namespace std;
bool ifprime(int x){
	if(x == 1)
		return false;
	for(int i=2;i*i<x;i++){
		if(x%i == 0)
			return false;		
	}
	return true;
}
int main(){
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		if(N == 1){
			cout << 1 << endl;
			continue;
		}
		if(ifprime(N)){
			cout << -1 << endl;
			continue;
		}
		int counter[10] = {0};
		int i = 9;
		while(N != 1 && i > 1){
			if(N%i == 0){
				counter[i]++;
				N /= i;
			}
			else{
				i--;
			}
		}
		if(N != 1){
			cout << -1 << endl;
			continue;
		}
		for(int i=1;i<=9;i++){
			if(counter[i] == 0)
				continue;
			for(int j=0;j<counter[i];j++){
				cout << i;
			}
		}
		cout << endl;
	}
}
