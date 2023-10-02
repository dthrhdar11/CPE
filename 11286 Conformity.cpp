#include<iostream>
#include<map>
#include<vector>
#include<algorithm> 
using namespace std;
int main(){
	int N;
	while(cin >> N && N){
		map<int,int> mp;
		int maxnum = 0, total = 0;
		map<string,int> course;
		while(N--){
			string s, line = "";
			vector<string> classNum;
			for(int i=0;i<5;i++){
				cin >> s;
				classNum.push_back(s);
			}
			sort(classNum.begin(),classNum.end());
			for(int i=0;i<5;i++){
				line += classNum[i];
			}
			++course[line];
		}
		for(auto it=course.begin();it!=course.end();++it){
			maxnum = max(maxnum,it->second);
		}
		for(auto it=course.begin();it!=course.end();++it){
			if(it->second == maxnum)
				total += maxnum;
		}
		cout << total << endl;
	}
}
