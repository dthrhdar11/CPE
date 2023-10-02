#include<iostream>
using namespace std;
//int is -2,147,483,648 to 2,147,483,647 (2^31)
int main()
{
	int t;
	cin >> t;
	int c = 0;
	while(t--){
		++c;
		int N;
		cin.ignore(4);
		cin >> N;
		long long m[N][N];
		bool ifsymmetric = true;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				cin >> m[i][j];
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;++j){
				if(m[i][j] < 0)
					ifsymmetric = false;
			}
		} 
		
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(m[i][j] != m[N-1-i][N-1-j]){
					ifsymmetric = false;
				}
			}
		}
		
		if(ifsymmetric)
			cout << "Test #" << c << ": Symmetric." << endl;
		else
			cout << "Test #" << c << ": Non-symmetric." << endl;
	}
 } 
