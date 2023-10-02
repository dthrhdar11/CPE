#include<bits/stdc++.h>
using namespace std;
int visit[50001] = {0};
int prime[50001];
int plist[1000001];
//int ans[1000001];
int makeprimenums(){
	int pos = 0;
	for(int i=2;i<=50000;i++){
		if(!visit[i])
			prime[pos++] = i;
		for(int j=i;j<=50000;j+=i){
			visit[j] = 1;
		}
	}
	return pos;
}
int main(){
	int L, U;
	int primecnt = makeprimenums();
	while(cin >> L >> U){
		vector<int> v;
		memset(plist,0,sizeof(plist));
		for(int i=0;i<primecnt;i++){
			int s = (L-1)/prime[i] + 1;//to find the first num that is the multiple of prime[i] in [L,U]
			if(s < 2)
				s = 2;//ex: L=1, s=1. However, prime[i](2)*s = 2 which is a prime. (Here means that we don't the prime to seem as composite(¦X¼Æ))
			for(unsigned int j = s*prime[i]; j <= U; j += prime[i]){//unsigned int is important!(since INT_MAX value is aviliable)
				plist[j-L] = 1;
			}
		}
		for(unsigned int i=L;i<=U;i++){
			if(i > 1 && !plist[i-L]){// 1 is not a prime
				v.push_back(i);
			}
		}
		int mindif = INT_MAX;
		int maxdif = 0;
		pair<int,int> minpair;
		pair<int,int> maxpair;
		if(v.size() < 2){
			cout << "There are no adjacent primes." << endl;
		}
		else{
			for(int i=0;i<v.size()-1;i++){
				int dif = v[i+1] - v[i];
				if(dif > maxdif){
					maxdif = dif;
					maxpair = {v[i],v[i+1]};
				}
				if(dif < mindif){
					mindif = dif;
					
					minpair = {v[i],v[i+1]};
				}
			}
			cout << minpair.first << "," << minpair.second << " are closest, ";
			cout << maxpair.first << "," << maxpair.second << " are most distant." << endl;
		}
		
	}
}
