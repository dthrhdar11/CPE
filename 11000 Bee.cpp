#include<iostream>
#include<vector>
using namespace std;
int main(){
	int N;
	vector<long long> male;
	male.push_back(0);
	vector<long long> female;
	female.push_back(1);
	while(cin >> N){
		if(N == -1)
			break;
		if(N < male.size()){
			cout << male[N] << " " << female[N] + male[N] << endl;
		}
		else{
			for(int i=male.size()-1;i<=N;++i){
				male.push_back(male[i] + female[i]);
				female.push_back(male[i] + 1);
			}
			cout << male[N] << " " << female[N] + male[N] << endl;
		}
		
	}
} 
