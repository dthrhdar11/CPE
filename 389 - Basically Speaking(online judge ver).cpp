#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
//A = 65 F = 70
int main()
{
	string s;
	while(cin >> s){
		int oldbase,newbase;
		cin >> oldbase >> newbase;
		int In10Value = 0;
		string NewValue = "";//answer
		int digitValue = 1;
		//convert to decimal(base10)
		for(int i=s.length()-1;i>=0;--i){
			if(s[i] >= 'A' && s[i] <= 'F'){
				In10Value += (s[i]-55)*digitValue;
			}
			else{
				In10Value += (s[i]-'0')*digitValue;	
			}
			
			digitValue *= oldbase;
		}
		//convert to newbase
		while(In10Value!=0){
			char x;
			int num = (In10Value%newbase);
			if(num >= 10 && num <= 15){
				x = 'A' + (num%10);
			}
			else{
				x = '0' + num;
			}
			NewValue = x + NewValue;
			In10Value /= newbase;
		}
		if(NewValue == ""){ 
			cout << "      0" << endl;
			continue;
		} 
		//print result
		if(NewValue.length() <= 7){
			for(int i=NewValue.length();i<7;++i){
				cout << ' ';
			}
			cout << NewValue << endl;
		}
		else{
			cout << "  ERROR" << endl;
		}

	}
 } 
