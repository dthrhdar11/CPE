#include<iostream>
using namespace std;
char board[105][105];
bool isok(int n,int i,int j){
	if(i < 0 || j < 0)
		return false;
	if(i >= n || j >= n)
		return false;
	return true;
}
int main(){
	int t;
	cin >> t;
	int cnt = 0;
	while(t--){
		int boardsize;
		cin >> boardsize;
		int posi,posj;
		for(int i=0;i<boardsize;i++){
			for(int j=0;j<boardsize;j++){
				cin >> board[i][j];
				if(board[i][j] == 'W'){
					posi = i;
					posj = j;
				}
			}
		}
		int dp[105][105] = {0};
		dp[posi][posj] = 1;
		for(int i = posi; i >= 0; i--){
			for(int j = 0; j < boardsize; j++){
				if(dp[i][j]){
					if(isok(boardsize,i-1,j-1)){
						if(board[i-1][j-1] == 'B' && isok(boardsize,i-2,j-2) && board[i-2][j-2] != 'B')
							dp[i-2][j-2] += dp[i][j] % 1000007;
						else if(board[i-1][j-1] != 'B')
							dp[i-1][j-1] += dp[i][j] % 1000007;
					}
					if(isok(boardsize,i-1,j+1)){
						if(board[i-1][j+1] == 'B' && isok(boardsize,i-2,j+2) && board[i-2][j+2] != 'B')
							dp[i-2][j+2] += dp[i][j] % 1000007;
						else if(board[i-1][j+1] != 'B')
							dp[i-1][j+1] += dp[i][j] % 1000007;
					}
				}
			}
		}
		int ans = 0;
		for(int i=0;i<boardsize;i++){
			ans += dp[0][i];
			ans %= 1000007;
		}
		cout << "Case " << cnt++ << ": " << ans << endl;
	}
}
