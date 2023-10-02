#include<iostream>
#include<string>
using namespace std;
string CharToBitString(char c){
	if(c >= 'A' && c <= 'Z'){
		int value = c - 'A';
		string s = "";
		for(int i=0;i<6;i++){
			int R = value % 2;
			s = to_string(R) + s;
			value /= 2;
		}
		return s;
	}
	else if(c >= 'a' && c <= 'z'){
		int value = c - 'a' + 26;
		string s = "";
		for(int i=0;i<6;i++){
			int R = value % 2;
			s = to_string(R) + s;
			value /= 2;
		}
		return s;
	}
	else if(c >= '0' && c <= '9'){
		int value = c - '0' + 52;
		string s = "";
		for(int i=0;i<6;i++){
			int R = value % 2;
			s = to_string(R) + s;
			value /= 2;
		}
		return s;
	}
	else if(c == '+'){
		return "111110";
	}
	else if(c == '/'){
		return "111111";
	}
	else if(c == '='){
		return "000000";
	}
}
int bitstreamToval(string bitstream){
	int ASCIIval = 0;
	for(int i=0;i<bitstream.length();i++){
		ASCIIval = ASCIIval*2 + (bitstream[i] - '0'); 
	}
	return ASCIIval;
}
int main(){
	while(1){
		string bitstr = "";
		char c;
		while(cin >> c){
			if(c == '#')
				break;
			bitstr += CharToBitString(c);
		}
		if(bitstr.empty())
			break;
		for(int i=0;i<bitstr.length();i+=8){
			string bitstream = bitstr.substr(i,8);
			int val = bitstreamToval(bitstream);
			if(val == 0)
				continue;
			else
				cout << char(val);
		}
		cout << '#';
	}
	cout << endl;
}
