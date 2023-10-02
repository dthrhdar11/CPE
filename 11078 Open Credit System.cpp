#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
	int N;
	cin >> N;
	while(N--){
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i=0;i<n;++i){
			cin >> v[i];
		}
		int maxnumber = v[0];
		int maxamount = v[0] - v[1];
		for(int i=1;i<n;++i){
			if(v[i] > maxnumber)//這個要先,因為要先算(前一個-當前) 
				maxnumber = v[i];
			if(maxnumber-v[i] > maxamount)
				maxamount = maxnumber-v[i];
		}
		cout << maxamount << endl;
	}
}
