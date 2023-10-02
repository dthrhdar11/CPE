#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	vector<string> v;
	string s;
	int maxlen = 0;
	while(getline(cin,s)){
		if(s.length() > maxlen)
			maxlen = s.length();
		v.push_back(s);
	}
	for(int i=0;i<maxlen;i++){
		for(int j=v.size()-1;j>=0;--j){
			if(i >= v[j].length())
				cout << ' ';
			else
				cout << v[j][i];
		}
		cout << endl;
	}
}
