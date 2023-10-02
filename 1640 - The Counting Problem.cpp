#include<iostream>
#include<string>
using namespace std;

int pow10[10], cnt[10];
//f(n,d) => numbers from 0~n, d(the digits aka 0~9) appears ? times
int f(int n,int d){
	string s = to_string(n);
	int ans = 0;
	for(int i=1;i<s.length();i++){//calculate * ~ ***...(ex:n=487 calculate * ~ **)
		if(i == 1){
			ans++;
		}	
		else{
			ans += 9 * cnt[i-1];//算頭後面的*(ex:*** 這邊算後面兩個 **) 
			if(d > 0)
				ans += pow10[i-1];//算第一個*(ex:*** 這邊算最一個* 所以當d=0時,不用算) 
		}
	}
	//calculate the last(ex:n=487,calculate 1**~487)
	int pre = 0;
	for(int i=0;i<s.length();++i){
		int L = 0, R = s[i]-'0';
		if(i == 0 && s.length() > 1)//s[0]就是數字第一位,所以要設為1(當然,這個n要有至少兩位數) 
			L = 1;
		for(int digit = L; digit < R; digit++)
		{//(ex:n=487,第一輪算(1**,2**,3**),第二輪算(40*,41*,42*,...,47*),最後算(480,481,482,...,487)(最後一輪這裡若n=487,不會算487,所以輸入時會+1))
			ans += cnt[s.length()-1-i] + pre * pow10[s.length()-1-i];//(ex:1** 這邊算後面**的次數)
			if(digit == d)//(ex:1** d=1,這個1除了在後面的**會出現20次,還有前面的1會出現100次,這100次這裡給加上去) 
				ans += pow10[s.length()-i-1];
		}
		if(s[i]-'0' == d)//第二輪後,部分情況要額外增加次數(line 27會處理)(ex:n=487,d=4 第二輪開始算(40*,41*,42*,...,47*),這裡4就額外出現了8*10次) 
			pre++;
	}
	return ans;
}
int main(){
	//initialize pow10[],cnt[]
	pow10[0] = 1;
	for(int i=1;i<10;i++){
		pow10[i] = pow10[i-1] * 10;
		cnt[i] = pow10[i] * i / 10;
	}
	/*for(int i=0;i<9;i++){
		cout << pow10[i] << " " << cnt[i] << endl;
	}*/
	//initialization ends
	int a,b;
	while(cin >> a >> b && a && b){
		if(a > b)
			swap(a,b);
		for(int i=0;i<10;i++){
			if(i == 0)
				cout << f(b+1,i)-f(a,i);
			else
				cout << " " << f(b+1,i)-f(a,i);
		}
		cout << endl;
	}
}
