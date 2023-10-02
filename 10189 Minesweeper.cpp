#include<iostream>
using namespace std;
int main()
{
	int a,b;
	int fcnt = 0;
	while(cin >> a >> b && a != 0 && b != 0){
		++fcnt;
		char field[a][b];
		
		//fill in 
		for(int i=0;i<a;++i){
			for(int j=0;j<b;++j){
				cin >> field[i][j];
				if(field[i][j] == '.')
					field[i][j] = '0';
			} 
		}
		//get answer
		for(int i=0;i<a;++i){
			for(int j=0;j<b;++j){
				if(field[i][j] != '*'){
					if(field[i-1][j-1] == '*' && i>=1 && j>=1)
						++field[i][j];
					if(field[i-1][j] == '*' && i>=1)
						++field[i][j];
					if(field[i-1][j+1] == '*' && i>=1 && j+1<b)
						++field[i][j];
					if(field[i][j-1] == '*' && j>=1)
						++field[i][j];
					if(field[i][j+1] == '*' && j+1<b)
						++field[i][j];
					if(field[i+1][j-1] == '*' && i+1<a && j>=1)
						++field[i][j];
					if(field[i+1][j] == '*' && i+1<a)
						++field[i][j];
					if(field[i+1][j+1] == '*' && i+1<a && j+1<b)
						++field[i][j];
				}
			}
		}
		//print
		if(fcnt > 1)
			cout << endl;
		printf("Field #%d:\n",fcnt);
		for(int i=0;i<a;++i){
			for(int j=0;j<b;++j){
				cout << field[i][j];
			}
			if(i-1 != a)
				cout << endl;
		}
	}
	
 } 
