#include<bits/stdc++.h>
using namespace std;
bool between(int a,int b,int x){
	if(a > b)
		swap(a,b);
	return x > a && x < b;
}
int main(){
	int K,Q,Qnext;
	while(cin >> K >> Q >> Qnext){
		if(K == Q){
			cout << "Illegal state" << endl;
			continue;
		}
		else if(Q == Qnext || K == Qnext){
			cout << "Illegal move" << endl;
			continue;
		}
		else if((Qnext % 8 != Q%8) && (Q/8 != Qnext/8)){//Q移動不合理 
			cout << "Illegal move" << endl;
			continue;
		}
		else if( ((K%8 == Q%8 && Q%8 == Qnext%8) || (Q/8 == K/8 && K/8 == Qnext/8)) && between(Qnext,Q,K)){//被K擋住(三點共線且K於Q,Qnext中間)
			cout << "Illegal move" << endl;
			continue;
		}
		else if((K == 0 && Qnext == 9) || (K == 7 && Qnext == 14) || (K == 56 && Qnext == 49) || (K == 63 && Qnext == 54) ){
			cout << "Stop" << endl;
			continue;
		}
		else if((K+8 == Qnext) || (K-8 == Qnext) || (K%8 != 0 && K-1 == Qnext)|| (K%8 != 7 && K+1 == Qnext)){
			cout << "Move not allowed" << endl;
			continue;
		}
		else{
			cout << "Continue" << endl;
			continue;
		}
	}
}
