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
			ans += 9 * cnt[i-1];//���Y�᭱��*(ex:*** �o���᭱��� **) 
			if(d > 0)
				ans += pow10[i-1];//��Ĥ@��*(ex:*** �o���̤@��* �ҥH��d=0��,���κ�) 
		}
	}
	//calculate the last(ex:n=487,calculate 1**~487)
	int pre = 0;
	for(int i=0;i<s.length();++i){
		int L = 0, R = s[i]-'0';
		if(i == 0 && s.length() > 1)//s[0]�N�O�Ʀr�Ĥ@��,�ҥH�n�]��1(��M,�o��n�n���ܤ֨���) 
			L = 1;
		for(int digit = L; digit < R; digit++)
		{//(ex:n=487,�Ĥ@����(1**,2**,3**),�ĤG����(40*,41*,42*,...,47*),�̫��(480,481,482,...,487)(�̫�@���o�̭Yn=487,���|��487,�ҥH��J�ɷ|+1))
			ans += cnt[s.length()-1-i] + pre * pow10[s.length()-1-i];//(ex:1** �o���᭱**������)
			if(digit == d)//(ex:1** d=1,�o��1���F�b�᭱��**�|�X�{20��,�٦��e����1�|�X�{100��,�o100���o�̵��[�W�h) 
				ans += pow10[s.length()-i-1];
		}
		if(s[i]-'0' == d)//�ĤG����,�������p�n�B�~�W�[����(line 27�|�B�z)(ex:n=487,d=4 �ĤG���}�l��(40*,41*,42*,...,47*),�o��4�N�B�~�X�{�F8*10��) 
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
