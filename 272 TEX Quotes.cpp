#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	int n = 1;
	while(getline(cin,s)){
		for(int i=0;i<s.length();++i){
			if(s[i] == '"'){
				if(n%2 == 1)
					cout << "``";
				else
					cout << "''";
				n++;
			}
			else
				cout << s[i];
		}
		cout << endl;
	}
} 
