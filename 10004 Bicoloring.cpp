//bfs
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int nodes[205][205];
bool bfs(vector<int>& color){
	for(int i=0;i<color.size();i++){
		if(color[i] == 0)
			continue;
		for(int j=0;j<color.size();j++){
			if(nodes[i][j]){
				if(color[j] == 0){
					color[j] = (color[i] == 1) ? 2 : 1;
				}
				else if(color[j] == color[i]){
					return false;
				}
			}
		}
	}
	return true;
}
int main(){
	int node, edge;
	while(cin >> node >> edge && node){
		vector<int> color(node,0);
		color[0] = 1;
		memset(nodes,0,sizeof(nodes));
		int x,y;
		for(int i=0;i<edge;i++){
			cin >> x >> y;
			nodes[x][y] = 1;
			nodes[y][x] = 1;
		}
		bool ans = bfs(color);
		if(ans)
			cout << "BICOLORABLE." << endl;
		else
			cout << "NOT BICOLORABLE." << endl;
	}
}
