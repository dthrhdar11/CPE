#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	string s;
	cin.ignore(1);
	vector<int> a(26,0);
	for(int j=0;j<t;++j){
		getline(cin,s);
		for(int i=0;i<s.length();++i){
			if(s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
				
			if(s[i] >= 'A' && s[i] <= 'Z')
				++a[s[i]- 'A'];
		}
	}
	//find max
	int max = 0;
	for(int i=0;i<26;++i){
		if(a[i] > max)
			max = a[i];
	}
	
	for(int i=max;i>0;--i){
		for(int j=0;j<26;++j){
			if(a[j] == i){
				char c = 'A'+j;
				cout << c << " " << i << endl;
			}
		}
	}
}
