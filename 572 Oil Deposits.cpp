#include<iostream>
#include<string>
using namespace std;
string arr[105][105];
void dfs(int deposit,int i,int j){
	if(arr[i][j] == "@"){
		arr[i][j] = to_string(deposit);
		
		dfs(deposit,i-1,j-1);
		dfs(deposit,i-1,j);
		dfs(deposit,i-1,j+1);
		dfs(deposit,i,j-1);
		dfs(deposit,i,j+1);
		dfs(deposit,i+1,j-1);
		dfs(deposit,i+1,j);
		dfs(deposit,i+1,j+1);
	}
	else{
		arr[i][j] = to_string(deposit);
	}
}
int main(){
	int m,n;
	while(cin >> m >> n && m && n){
		for(int i=1;i<=m;i++){
			string s;
			cin >> s;
			for(int j=1;j<=n;j++){
				arr[i][j] = s[j-1];
			}
		}
		/*for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cout << arr[i][j];
			}
			cout << endl;
		}*/
		int deposit = 0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(arr[i][j] == "@"){
					dfs(deposit,i,j);
					deposit++;
				}
			}
		}
		/*for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cout << arr[i][j];
			}
			cout << endl;
		}*/
		cout << deposit << endl;
	}
}
