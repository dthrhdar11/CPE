#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--){
		int m,n; //m for no. of sequences, n for length
		cin >> m >> n;
		string DNA[m];
		string ans;
		int hamdis = 0;
		for(int i=0;i<m;++i){
			cin >> DNA[i];
		}
		//count the no. of alphebet
		int acnt = 0;
		int ccnt = 0;
		int gcnt = 0;
		int tcnt = 0;
		int max = 0;
		for(int i=0;i<n;++i){
			acnt = 0;
			ccnt = 0;
			gcnt = 0;
			tcnt = 0;
			max = 0;
			string add;
			for(int j=0;j<m;++j){
				if(DNA[j][i] == 'A')
					acnt++;
				if(DNA[j][i] == 'C')
					ccnt++;
				if(DNA[j][i] == 'G')
					gcnt++;
				if(DNA[j][i] == 'T')
					tcnt++;
			}
			//which has the most
			max = tcnt;
			add = 'T';
			if(gcnt >= max){
				max = gcnt;
				add = 'G';
			}
			if(ccnt >= max){
				max = ccnt;
				add = 'C';
			}
			if(acnt >= max){
				max = acnt;
				add = 'A';
			}
			ans += add;
		}
		cout << ans << endl;
		//caculate total hamming distance
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				if(ans[j] != DNA[i][j])
					++hamdis;
			}
		}
		cout << hamdis << endl;
	}
 } 
