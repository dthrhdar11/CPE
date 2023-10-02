#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0;i<n;++i){
			cin >> a[i];
		}
		vector<int> b(n-1,0);
		for(int i=1;i<n;++i){
			for(int j=0;j<i;++j){
				if(a[i] >= a[j])
					b[i-1]++;
			}
		}
		int sum = 0;
		for(int i=0;i<b.size();++i){
			sum += b[i];
		}
		cout << sum << endl;
	}
} 
