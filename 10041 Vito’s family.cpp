#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;
int addr[MAX];
bool cmp(int a,int b){
   return (a < b);    
}
int main(){
  int n,m,mid,result;
  cin >> n;
  for(int i=0;i<n;i++){
    result=0;
    cin>>m;
    for(int j=0;j<m;j++){
      cin >> addr[j];        
    }
    sort(addr,addr+m,cmp);
    mid=addr[m/2];
    for(int j=0;j<m;j++){
      result+=abs(addr[j]-mid);        
    }
    cout << result <<endl; 
  }
} //system("pause");  

