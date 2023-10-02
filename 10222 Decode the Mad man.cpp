#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s = "qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	string t;
	getline(cin,t);
	for(int i=0;i<t.length();++i){
		if(t[i] >= 'A' && t[i] <= 'Z')
			t[i] += 32;
	}
	for(int i=0;i<t.length();++i){
		if(t[i] == ' '){
			cout << ' ';
			continue;
		}
		for(int j=0;j<s.length();++j){
			if(t[i] == s[j]){
				cout << s[j-2];
			}
		}
	}
	cout << endl;
}
