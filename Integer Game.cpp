#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int cases;
	cin >> cases;
	string s;
	for(int i=1;i<=cases;++i){
		cin >> s;
		int sum = 0;
		int cnt = 0;
		vector<int> num;
		
		for(int j=0;j<s.size();++j){
			num.push_back(s[j]-'0');
			sum += s[j]-'0';
		}
		
		for(int j=0;j<num.size();++j){
			if(num[j]%3 == 0)
				++cnt;
		}
		
		if(sum%3==0){
			if(cnt%2 == 0)
				cout << "Case " << i << ": T" << endl;
			else
				cout << "Case " << i << ": S" << endl;
		}
		else{
			for(int j=0;j<num.size();++j){
				if((sum-num[j])%3 == 0){
					if(cnt%2 == 0)
						cout << "Case " << i << ": S" << endl;
					else
						cout << "Case " << i << ": T" << endl;
					break;
				}
				else if(j == num.size()-1){
					cout << "Case " << i << ": T" << endl;
					break;
				}
			}
		}
	} 
}
