#include <iostream>
using namespace std;

int main()
{
	int fib[39],i,n,in1;
	
	fib[0]=1;
	fib[1]=2;
	for(i=2;i<39;i++)//���ͶO��ƦC 
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	
	cin>>n;//��J����ƶq 
	while(n--) 
	{
		cin>>in1;//��J����
		cout<<in1<<" = ";//�Ӯ榡��X 
		
		int flag=0;
		
		for(i=38;i>=0;i--)//�N��J���Ʀr��h�O��ƦC���� 
		{				  //�p�G�����N��X1 
			if(in1-fib[i]>=0)
			{
				cout<<"1";
				in1=in1-fib[i];
				flag=1;//���Ĥ@��1����~�i�H��X0 
			}
			else if(flag==1)
			{
				cout<<"0";
			}
		}
		cout<<" (fib)"<<endl;//��X���� 
	}
	return 0;
}
