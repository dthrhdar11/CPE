#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int S;
	int a[10]={5,1,3,5,10,7,4,9,2,8};
	cout << "Find that in array a[10],the minimum continuous subarray >= S(S>10)" << endl;
	for(int i=0;i<10;++i){
		cout << a[i] << ' ';
	}
	cout << endl;
	cout << "Enter an integer S" << endl;
	cin >> S;
	int first = 0,end = 0;//left and right pointer
	int sum = 0;//temporary result
	int ans = 200;//true result
	//Twopointers algorithm
	for(first=0;first<10;++first){// firstPointer increment everytime until reach the maximum
		while(sum < S && end < 10){ //if sum < S,then keep adding next one(endPointer indicates)
			sum += a[end];
			++end;
		}
		if(sum >= S){ //if sum >= S(match the requirement),then minus the least first one
			ans = min(sum,ans);
			sum -= a[first];
		}
		cout << ans << endl;
	}
	if(ans == 200)
		cout << "No such consequence" << endl;
	else
		cout << "The answer is " << ans << endl;
}
