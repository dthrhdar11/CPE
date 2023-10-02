#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	while(cin >> s){
		int cntletter = 0;
		int cnthyphen = 0;
		for(int i=0;i<s.length();++i){
			switch(s[i]){
				case 'A':case 'B':case 'C':
					cout << '2';
					++cntletter;
					break;
				case 'D':case 'E':case 'F':
					cout << '3';
					++cntletter;
					break;
				case 'G':case 'H':case 'I':
					cout << '4';
					++cntletter;
					break;
				case 'J':case 'K':case 'L':
					cout << '5';
					++cntletter;
					break;
				case 'M':case 'N':case 'O':
					cout << '6';
					++cntletter;
					break;
				case 'P':case 'Q':case 'R':case 'S':
					cout << '7';
					++cntletter;
					break;
				case 'T':case 'U':case 'V':
					cout << '8';
					++cntletter;
					break;
				case 'W':case 'X':case 'Y':case 'Z':
					cout << '9';
					++cntletter;
					break;
				case '-':
					cout << '-';
					++cnthyphen;
					break;
				default:
					cout << s[i];
			}
		}
		cout << ' ' << cntletter << ' ' << cnthyphen << endl;
	}
} 
