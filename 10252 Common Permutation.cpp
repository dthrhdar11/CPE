#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string a,b;
	while(getline(cin,a) && getline(cin,b)){
		vector<int> s1(26,0);
		vector<int> s2(26,0);
		for(int i=0;i<a.length();++i){
			s1[a[i]-'a']++;
		}
		
		for(int i=0;i<b.length();++i){
			s2[b[i]-'a']++;
		}
		
		for(int i=0;i<26;++i){
			if(s1[i]>0 && s2[i]>0){
				int t = min(s1[i],s2[i]);
				for(int j=0;j<t;++j){
					cout << char('a'+i);
				}
			}
		}
		
		cout << endl;
	}
 } 
