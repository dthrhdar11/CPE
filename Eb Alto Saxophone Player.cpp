#include<iostream>
#include<string>
using namespace std;

//string for compare

string c = "0111001111";
string d = "0111001110";
string e = "0111001100";
string f = "0111001000";
string g = "0111000000";
string a = "0110000000";
string b = "0100000000";
string C = "0010000000";
string D = "1111001110";
string E = "1111001100";
string F = "1111001000";
string G = "1111000000";
string A = "1110000000";
string B = "1100000000";

//switch
string change(char n)
{
	switch(n){
				case 'c':
					return c;break;
				case 'd':
					return d;break;
				case 'e':
					return e;break;
				case 'f':
					return f;break;
				case 'g':
					return g;break;
				case 'a':
					return a;break;
				case 'b':
					return b;break;
				case 'C':
					return C;break;
				case 'D':
					return D;break;
				case 'E':
					return E;break;
				case 'F':
					return F;break;
				case 'G':
					return G;break;
				case 'A':
					return A;break;
				case 'B':
					return B;break;
				default:
					return "";break;
			}
}

int main()
{
	int cases;
	cin >> cases;
	cin.ignore();
	for(int i=0;i<cases;++i){
		int f1{0},f2{0},f3{0},f4{0},f5{0},f6{0},f7{0},f8{0},f9{0},f10{0};
		string notes = "";
		getline(cin,notes);//avoid empty input
			switch(notes[0]){
				case 'c':
					++f2;++f3;++f4;++f7;++f8;++f9;++f10;break;
				case 'd':
					++f2;++f3;++f4;++f7;++f8;++f9;break;
				case 'e':
					++f2;++f3;++f4;++f7;++f8;break;
				case 'f':
					++f2;++f3;++f4;++f7;break;
				case 'g':
					++f2;++f3;++f4;break;
				case 'a':
					++f2;++f3;break;
				case 'b':
					++f2;break;
				case 'C':
					++f3;break;
				case 'D':
					++f1;++f2;++f3;++f4;++f7;++f8;++f9;break;
				case 'E':
					++f1;++f2;++f3;++f4;++f7;++f8;break;
				case 'F':
					++f1;++f2;++f3;++f4;++f7;break;
				case 'G':
					++f1;++f2;++f3;++f4;break;
				case 'A':
					++f1;++f2;++f3;break;
				case 'B':
					++f1;++f2;break;
				default:
					;
			}
		
		for(int i=1;i<notes.length();++i){
			string temp1="",temp2="";
			temp1 = change(notes[i-1]);
			temp2 = change(notes[i]);
			for(int j=0;j<10;j++){
				if(temp1[j] == '0' && temp2[j] == '1'){
					switch(j){
						case 0:++f1;break;
						case 1:++f2;break;
						case 2:++f3;break;
						case 3:++f4;break;
						case 4:++f5;break;
						case 5:++f6;break;
						case 6:++f7;break;
						case 7:++f8;break;
						case 8:++f9;break;
						case 9:++f10;break;
						default:break;
					}
				}
			}
		}
		cout << f1 << ' ' << f2 << ' ' << f3 << ' ' << f4 << ' ' << f5 << ' '
			 << f6 << ' ' << f7 << ' ' << f8 << ' ' << f9 << ' ' << f10 << endl;
	}
}
