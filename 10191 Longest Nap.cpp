#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
//be aware when using for(const int &p:v),p here stand for v[p]
using namespace std;
int main()
{
	int day = 0;
	int t;
	while(cin >> t){
		day++;
		string s;
		vector<int> v(480,0);//for 10:00~18:00 
		int h1,m1,h2,m2;
		int startp=0;
		for(int i=0;i<t;++i){
			cin >> h1;
			cin.ignore(1);
			cin >> m1;
			cin >> h2;
			cin.ignore(1);
			cin >> m2;	
			getline(cin,s);
			for(int i=(h1-10)*60+m1;i<(h2-10)*60+m2;++i){
				v[i] = 1;
			}
		}
		
		//get answer
		int cntmin = 0;
		int pos = startp;
		while(pos<480){
			int temp = 0;
		for(;pos<480;++pos){
			if(v[pos] == 0){
				break;
			}
		}
		for(;pos<480;++pos){
			if(v[pos] == 0)
				temp++;
			else
				break;
		}
		if(temp > cntmin){
			cntmin = temp;
			startp = pos-temp;
		}
	}
		//print answer
		int h = 10+(startp/60);
		int m = startp%60;
		int lasth = cntmin/60;
		int lastm = cntmin%60;
		cout <<"Day #" << day <<": the longest nap starts at " << h << ":"; 
		cout << setw(2) << setfill('0') << m << " and will last for ";
		if(lasth > 0)
			printf("%d hours and ",lasth);
		cout << lastm << " minutes." << endl;
	}
 } 
