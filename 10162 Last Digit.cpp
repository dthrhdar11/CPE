#include<iostream>
#include<string>
using namespace std;
int main(){
	int arr[10] = {0,7,4,1,8,5,2,9,6,3};//every 10 num is total 47
	int even[10] = {0,1,4,7,6,5,6,3,6,9};//ex:(1~10,21~30...)
	int odd[10] = {0,1,6,3,6,5,6,7,4,9};//ex:(11~20,31~40...)
	string s;
	while(cin >> s){
		if(s == "0")
			break;
		string last = (s.length() < 2) ? s : s.substr(s.length()-2,2);
		int n = stoi(last);
		int ans = 0;
		ans = arr[n/10];
		for(int i=0;i<=n%10;i++){
			if((n/10)%2 == 0)
				ans += even[i];
			else
				ans += odd[i];
		}
		cout << ans%10 << endl;
	}
} 
