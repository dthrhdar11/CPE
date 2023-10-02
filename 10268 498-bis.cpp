#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;
 

 
int main() {
		int x;
    while (cin >> x){
    	vector <int> v;
    	string s;
        cin.ignore(1);
        getline(cin, s);
        //cout << "s: " << s << "\n";
        stringstream ss(s);
        while (ss >> s){
            v.push_back(stoi(s));
        }
        v.pop_back();
        reverse(v.begin(), v.end());
        long long mul = 1;
        int ans = 0;
        for (int i = 0; i < v.size(); i++){
            //cout << "i: " << i << " " << v[i] << " " << ans << " " << mul << "\n";
            ans += v[i]*(i+1)*mul;
            mul *= x;
        }
        cout << ans << endl;
    }
}
