#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string inttostring(int x){
	stringstream ss;
	ss << x;
	return ss.str();
}

int main(){
	string s;
	for(;;){
		cin >> s;
		if(s == "0")
			break;
		if(s.length() == 1){
			cout << s << endl;
			continue;
		}
		while(s.length()>1){
			int g = 0;
			for(int i=0;i<s.length();++i){
				g += s[i]-'0';
			}
			s = inttostring(g);
		}
		cout << s << endl;
	}
}
