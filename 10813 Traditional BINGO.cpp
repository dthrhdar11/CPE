#include<iostream>
using namespace std;

bool ifbingo(bool b[5][5]){
	for(int i=0;i<5;++i){//row bingo
		if(b[i][0] && b[i][1] && b[i][2] && b[i][3] && b[i][4])
			return true;
	}
	for(int i=0;i<5;++i){//colume bingo
		if(b[0][i] && b[1][i] && b[2][i] && b[3][i] && b[4][i])
			return true;
	}
	if(b[0][0] && b[1][1] && b[2][2] && b[3][3] && b[4][4])
		return true;
	if(b[0][4] && b[1][3] && b[2][2] && b[3][1] && b[4][0])
		return true;
		
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		int cardnum[5][5];
		cardnum[2][2] = 0;
		bool bingocard[5][5] = {false};
		bingocard[2][2] = true;
		//fill bingo card number
		for(int i=0;i<5;++i){
			for(int j=0;j<5;++j){
				if(i==2 && j==2)
					continue;
				cin >> cardnum[i][j];
			}
		}
		
		//circle bingo card
		int n;
		int whenbingo = 75;
		bool firstbingo = false;
		for(int i=1;i<=75;++i){
			cin >> n;
			for(int i=0;i<5;++i){
				for(int j=0;j<5;++j){
					if(cardnum[i][j] == n){
						bingocard[i][j] = true;
					}
				}
			}
			if(ifbingo(bingocard) && !firstbingo){
				whenbingo = i;
				firstbingo = true;
			}
		}
		cout << "BINGO after " << whenbingo << " numbers announced" << endl;
	}
}
