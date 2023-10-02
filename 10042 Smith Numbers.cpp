#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
vector<int> prime;
bool isprime(int x){
	if(x == 1)
		return false;
	if(x == 2 || x == 3)
		return true;
	for(int i=2;i*i<=x;i++){
		if(x % i == 0)
			return false;
	}
	return true;
}
void makeprimelist(){
	for(int i=2;i<=32000;i++){
		if(isprime(i))
			prime.push_back(i);
	}
}
int bitsum(int x){
	int sum = 0;
	while(x != 0){
		sum += x%10;
		x /= 10;
	}
	return sum;
}
int main(){
	makeprimelist();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=n+1;;i++){
			if(isprime(i))
				continue;
			int leftsum = bitsum(i), rightsum = 0;
			int temp = i;
			for(int j=0;j<prime.size();j++){
				if(temp == 1)
					break;
				if(isprime(temp)){
					rightsum += bitsum(temp);
					break;
				}
				if(temp % prime[j] == 0){
					rightsum += bitsum(prime[j]);
					temp /= prime[j];
					j--;
				}
			}
			
			if(leftsum == rightsum){
				cout << i << endl;
				break;
			}
		}
	}
}
