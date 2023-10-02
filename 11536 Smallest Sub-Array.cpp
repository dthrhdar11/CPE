#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
	int T;
	cin >> T;
	int cnt = 0;
	while(T--){
		cnt++;
		int N,M,K;
		cin >> N >> M >> K;
		int minlen = INT_MAX;
		bool flag = true;
		vector<int> v{1,2,3};
		for(int i=2;i<N-1;++i){
			v.push_back((v[i-2]+v[i-1]+v[i])%M+1);
		}
		vector<bool> check(K+1,false);
		int counter = 0;
		for(int i=0;i<v.size();++i){
			if(v[i] <= K && !check[v[i]]){
				check[v[i]] = true;
				counter++;
			}
			if(counter == K){
				minlen = i;
				break;
			}	
		}
		for(int i=1;i<check.size();++i){
			if(!check[i]){
				flag = false;
				break;
			}
		}
		//two pointer
		if(flag){
			int start = 0, end = minlen;
			while(start < v.size()){
				int temp = v[start];
				if(temp > K){
					start++;
					continue;
				}
				while(v[end] != temp && end < v.size()){
					end++;
				}
				if(v[end] == temp){
					minlen = min(minlen,end-start+1);
				}
				start++;
			}
		}
		
		cout << "Case " << cnt << ": ";
		if(flag)
			cout << minlen << endl;
		else
			cout << "sequence nai" << endl;
	}
} 
