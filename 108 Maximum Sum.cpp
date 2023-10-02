#include<iostream>
#include<climits>
using namespace std;
int main(){
	int N;
	int arr[102][102];
	while(cin >> N && N){
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				cin >> arr[i][j];
			}
		}
		int colSum[102][102] = {0};
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				colSum[i][j] = colSum[i-1][j] + arr[i][j];
			}
		}
		int sum = INT_MIN;
		for(int i=1;i<=N;++i){
			for(int j=i;j<=N;++j){
				int temp = 0;
				for(int k=1;k<=N;++k){
					temp += colSum[j][k] - colSum[i-1][k];
					if(temp > sum)
						sum = temp;
					if(temp < 0)
						temp = 0;
				}
			}
		}
		cout << sum << endl;
	}
}
