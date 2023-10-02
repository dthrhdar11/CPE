#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	int cnt = 0;
	while(t--){
		cnt++;
		char c;
		int N;
		cin >> c >> c >> N;	
		vector<long long> v(N*N);
		bool flag = true;
		for(int i=0;i<v.size();i++){
			cin >> v[i];
		}
		for(int i=0;i<v.size();i++){
			if(v[i] < 0){
				flag = false;
				break;
			}
			if(v[i] != v[v.size()-1-i])
				flag = false;
		}
		if(flag){
			cout << "Test #" << cnt << ": Symmetric." << endl;
		}
		else{£~ 
			cout << "Test #" << cnt << ": Non-symmetric." << endl;
		}
	}
}
