#include<iostream>
#include<vector>
using namespace std;
int main(){
	int num,div;
	while(cin >> num >> div){
		bool boring = false;
		vector<int> v;
		if(num == 0 || num == 1 || div == 0 || div == 1){
			cout << "Boring!" << endl;
			continue;
		}
		while(num != 1){
			v.push_back(num);
			if(num % div != 0){
				boring = true;
				break;
			}
			else{
				num /= div;
			}
		}
		v.push_back(num);
		if(!boring){
			for(int i=0;i<v.size();++i){
				if(i != 0){
					cout << " ";
				}
				cout << v[i];
			}
		}
		else{
			cout << "Boring!";
		}
		cout << endl;
	}
}
