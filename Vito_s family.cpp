#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;
int main()
{
	int testcases;
	int arr[500];
	int j=0;
	cin >> testcases;//how many test cases
	for(int i=0;i < testcases;++i){
		int cases;
		cin >> cases;
		for(j=0;j < cases;++j){
			int num;
			cin >> num;
			arr[j] = num;
		}
		sort(arr,arr+cases);
		int middle = cases/2;
		int result = 0;
		for(int i=0;i<cases;i++){
			result += abs(arr[i]-arr[middle]);
		}
		cout << result << endl;
	}
 }
