#include<iostream>
using namespace std;
int main(){
	int num;
	int cnt = 0;
	while(cin >> num && num){
		cnt++;
		int sum = 0;
		bool flag = false;
		int ans;
		for(int i=1;i<=num;++i){
			sum = 0;
			for(int j=1;j<=i;++j){
				if(i%j == 0)
					sum += j;
			}
			if(sum == num){
				flag = true;
				ans = i;
			}
		}
		if(flag)
			cout << "Case " << cnt << ": " << ans << endl;
		else
			cout << "Case " << cnt << ": " << "-1" << endl;
	}
}
