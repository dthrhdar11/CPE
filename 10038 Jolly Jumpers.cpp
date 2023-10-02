#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int main()
{
	int n;
	while(cin >> n){
		vector<bool> check(n-1,false);
		bool ifjolly = true;
		vector<int> v;
		int a;
		for(int i=0;i<n;++i){
			cin >> a;
			v.push_back(a);
		}
		
		for(int i=0;i<v.size()-1;++i){
			int temp = abs(v[i]-v[i+1]);
			if(temp >= 1 && temp <= (n-1)){
				check[temp] = true;
			}
		}
		
		for(int i=1;i<=check.size();++i){
			if(check[i] == false)
				ifjolly = false;
		}
		
		if(ifjolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}
} 
