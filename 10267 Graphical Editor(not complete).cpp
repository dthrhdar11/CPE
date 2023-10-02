//uva10267
#include <bits/stdc++.h>
using namespace std; 

class Graph{
	public:
		char G[256][256];  // 1 <= M,N <= 250
		int M,N;
		
		Graph(){
			for (int i = 0; i < 256; ++i)
				for (int j = 0; j < 256; ++j)
					G[i][j] = 'O';
		}
		
		void setPixel(int x, int y, int w, int h, char C){
			for (int i = y; i < y+h; ++i)
				for (int j = x; j < x+w; ++j)
					G[i][j] = C;
		}
		
		void output(){
			for (int i = 1; i <= N; ++i){
				for (int j = 1; j <= M; ++j)
					cout << G[i][j];
				cout << endl;
			}
		}
};

void DFS(Graph& graph, int x, int y, char curPixel, char C){
	if (curPixel == C) return;
	graph.G[y][x] = C;
	
	if (x+1 <= graph.M && graph.G[y][x+1] == curPixel) DFS(graph,x+1,y,curPixel,C);
	if (x-1 >= 1       && graph.G[y][x-1] == curPixel) DFS(graph,x-1,y,curPixel,C);
	if (y+1 <= graph.N && graph.G[y+1][x] == curPixel) DFS(graph,x,y+1,curPixel,C);
	if (y-1 >= 1       && graph.G[y-1][x] == curPixel) DFS(graph,x,y-1,curPixel,C);
}

int main(){
	Graph graph;
	char cmd, C;
	int M, N, X1, Y1, X2, Y2; // X is column, Y is row
	string fileName, ignore;
	
	while ((cin >> cmd) && cmd != 'X'){
		switch (cmd){
			case 'I':
				cin >> M >> N; // M is column, N is row
				graph.M = M;
				graph.N = N;
			case 'C':
				graph.setPixel(1, 1, graph.M, graph.N, 'O');
				break;
			case 'L':
				cin >> X1 >> Y1 >> C;
				graph.setPixel(X1, Y1, 1, 1, C);
				break;
			case 'V':
				cin >> X1 >> Y1 >> Y2 >> C;
				graph.setPixel(X1, min(Y1,Y2), 1, abs(Y1-Y2)+1, C);
				break;
			case 'H':
				cin >> X1 >> X2 >> Y1 >> C;
				graph.setPixel(min(X1,X2), Y1, abs(X1-X2)+1, 1, C);
				break;
			case 'K':
				cin >> X1 >> Y1 >> X2 >> Y2 >> C;
//				leftX = min(X1,X2);
//				upY = min(Y1,Y2);
//				graph.setPixel(leftX,upY,abs(X1-X2)+1,abs(Y1-Y2)+1,C);
				graph.setPixel(X1, Y1, X2-X1+1, Y2-Y1+1, C);
				break;
			case 'F':
				// use DFS to modify the pixel
				cin >> X1 >> Y1 >> C;
				DFS(graph, X1, Y1, graph.G[Y1][X1], C);
				break;
			case 'S':
				cin >> fileName;
				cout << fileName << endl;
				graph.output();
				break;
			default:
				getline(cin,ignore);
				break;
		}
	}
}
