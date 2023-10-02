#include<iostream>
#include<string>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string M;
		cin >> M;
		int dec = stoi(M), hexdec = 0;
		for(int i=0;i<M.length();i++){
			hexdec = hexdec * 16 + (M[i]-'0');
		}
		int b1 = 0,b2 = 0;
		while(dec != 0){
			b1 += dec%2;
			dec /= 2;
		}
		while(hexdec != 0){
			b2 += hexdec%2;
			hexdec /= 2;
		}
		cout << b1 << " " << b2 << endl;
	} 
}
