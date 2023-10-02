#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
void pushCharToString(string& s,char c,int nowlen){
	for(int i=s.length();i<nowlen;++i){
		s.push_back(' ');
	}
	s.push_back(c);
}
int main(){
	int N;
	int cnt = 0;
	cin >> N;
	while(N--){
		cnt++;
		string s;
		cin >> s;
		int height = 0;
		int maxh = 0;
		int minh = 0;
		vector<string> v(51);
		for(int i=0;i<s.length();++i){
			if(s[i] == 'R'){
				height++;
			}
			else if(s[i] == 'F'){
				height--;
			}
			minh = min(minh,height);
			maxh = max(height,maxh);
		}
		height = abs(minh);
		maxh = abs(minh) + maxh;
		for(int i=0;i<s.length();++i){
			if(s[i] == 'R'){
				pushCharToString(v[height],'/',i);
				height++;
			}
			else if(s[i] == 'F'){
				height--;
				pushCharToString(v[height],'\\',i);
			}
			else if(s[i] == 'C'){
				pushCharToString(v[height],'_',i);
			}
			
		}
		
		
		cout << "Case #" << cnt << ":" << endl;
		for(int i=maxh;i>=0;--i){
			if(v[i].length() == 0)
				continue;
			cout << "| " << v[i] << endl;
		}
		cout << "+";
		for(int i=0;i<s.length()+2;++i){
			cout << "-";
		}
		cout << endl << endl;
	}
}
