#include<iostream>
#include<string>
using namespace std;
int main(){
	string s, str = "";
	while(getline(cin,s)){
		str += s;
		if(s[s.length()-1] != '#')
			continue;
		int count = 0;
		for(int i=0;i<str.length()-1;i++){
			if(str[i] == '1' && count == 0)
				count = 1;
			else{
				count = (count*2 + (str[i] - '0')) % 131071;
			}
		}
		if(count%131071 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		str.clear();
	}
}
