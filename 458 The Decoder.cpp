#include<iostream>
#include<string>
using namespace std;
int main()
{
	//-7 relation
	string s;
	while(cin >> s){
		for(int i=0;i<s.length();++i){
			s[i] = s[i] - 7;
			cout << s[i];
		}
		cout << endl;
	}
}
