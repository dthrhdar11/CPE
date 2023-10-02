#include<bits/stdc++.h>
using namespace std;
#define INF 9.9e9 
int main(){
	int n;
	double x1, y1, x2, y2, x3, y3, x4, y4;
	cin >> n;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	while(n--){
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		double rec1, rec2, c1, c2;
		if(x1!=x2){
			rec1 = (y2 - y1) / (x2 - x1);//斜率1
			c1 = y1 - rec1*x1;//ax+by+c=0的c 
		}else{
			rec1 = INF;
			//c1 = INF;
			c1 = x1;//這種情況是 x=?的垂直線 就用c去記?吧 
		}
		if(x3!=x4){
			rec2 = (y4 - y3) / (x4 - x3); //斜率2
			c2 = y3 - rec2*x3; 
		}else{
			rec2 = INF;
			//c2 = INF;
			c2 = x3;
		}
		if(rec1 == rec2) {
			if(c1 == c2){
				cout << "LINE" << endl;
			}else{
				cout << "NONE" << endl; 
			}
		}else{
			double px, py;
			if((x1==x2)&&(y3==y4)){
				px = x1;
				py = y3;
			}else if((x3==x4)&&(y1==y2)){
				px = x3;
				py = y1;
			}else{
				px = (c2 - c1) / (rec1 - rec2);
				py = rec1*px + c1; 
			}
			cout << "POINT " << fixed << setprecision(2) << px << " " << py << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
} 
