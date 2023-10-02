#include<iostream>
#include<string>
#include<vector>
using namespace std;
int mapx;
int mapy;
class robot{
public:
	int posx;
	int posy;
	int dir;
	robot(int x,int y,char d){
		posx = x;
		posy = y;
		switch(d){
			case 'N':
				dir = 1;break;
			case 'E':
				dir = 2;break;
			case 'S':
				dir = 3;break;
			case 'W':
				dir = 4;break;	
		} 
	}
	void moveForward(){
		if(dir == 1)
			++posy;
		else if(dir == 2)
			++posx;
		else if(dir == 3)
			--posy;
		else if(dir == 4)
			--posx;
	}
	char getdir(){
		if(dir == 1)
			return 'N';
		else if(dir == 2)
			return 'E';
		else if(dir == 3)
			return 'S';
		else if(dir == 4)
			return 'W';
	}
	void printpos(){
		cout << posx << " " << posy << " " << getdir() << endl;
	}
	bool lostCheck(){
		if(posx > mapx || posx < 0)
			return true;
		else if(posy > mapy || posy < 0)
			return true;
		else
			return false;
	}
};
int main(){
	cin >> mapx >> mapy;
	vector< vector<bool> > lostmap;
	lostmap.resize(mapx+1);
	for(int i=0;i<mapx+1;++i){
		lostmap[i].resize(mapy+1);
		for(int j=0;j<mapy+1;++j){
			lostmap[i][j] = false;
		}
	}
	int x,y;
	char dir;
	while(cin >> x >> y >> dir){
		robot rb(x,y,dir);
		string cmd;
		cin.ignore(1);
		getline(cin,cmd);
		int tempx,tempy;
		for(int i=0;i<cmd.length();++i){
			tempx = rb.posx;
			tempy = rb.posy;
			if(cmd[i] == 'R'){
				++rb.dir;
				if(rb.dir > 4)
					rb.dir -= 4;
			}
			else if(cmd[i] == 'L'){
				--rb.dir;
				if(rb.dir <= 0)
					rb.dir += 4;
			}
			else if(cmd[i] == 'F'){
				rb.moveForward();
				//rb.printpos();
				if(rb.lostCheck()){
					if(!lostmap[tempx][tempy]){
						lostmap[tempx][tempy] = true;
						cout << tempx << " " << tempy << " " << rb.getdir() << " LOST" << endl;
						break;
					}
					else{
						rb.posx = tempx;
						rb.posy = tempy;
					}
				}
			}
		}
		if(!rb.lostCheck())
			rb.printpos();
	}
} 
