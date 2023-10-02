#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin >> n && n){
		vector<double> v(n);
		int total = 0;
		for(int i=0;i<n;i++){
			cin >> v[i];
			v[i] *= 100;
			total += v[i];
		}
		int avg = total/n;
		int remain = total%n;
		double sum = 0;
		sort(v.begin(),v.end());
		for(int i=n-1;i>=n-remain;i--){
			sum += abs(v[i] - avg - 1);
		}
		for(int i=n-remain-1;i>=0;i--){
			sum += abs(v[i] - avg);
		}
		double ans = sum/200.0;
		cout << "$" << fixed << setprecision(2) << ans << endl;
	}
}
