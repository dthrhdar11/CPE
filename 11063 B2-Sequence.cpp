#include <iostream>
#include <set>
using namespace std;

int main()
{	
	int n,i,t,c=1;
	
	while(cin>>n)//��J�ƦC�ƶq 
	{
		int b[n]={0};//��ƦC���}�C 
		set<int> d;//set�̭�����񭫽ƪ��Ʀr
				   //�H���ӭp���ƪ��M�O�_���� 
		d.clear();//�M�� 
		
		for(i=0;i<n;i++)//��J�ƦC 
		{
			cin>>b[i];
		}
		
		for(i=0;i<n;i++)//�P�_�ƦC�O�_��B2 
		{
			if(b[i]<1)//B2���঳�t�Ʃ�0
			{
				break;
			}
			else if(b[i-1]>=b[i]&&i-1>0)//B2�ᶵ��e���j 
			{							//i-1�p�G�p��0�i��|�X���D 
				break;
			}
			for(t=i;t<n;t++)//��Ƭۥ[ 
			{
				d.insert(b[i]+b[t]);//�N��ƩM��Jset�̭�
									//set���|���Ʃ� 
			}
		}
		
		if(d.size()==(n+1)*n/2)//�p�Gset���֪��ܴN�N���ƦC�DB2 
		{					   //size�N�O���oset�̭��񪺼ƶq 
			cout<<"Case #"<<c<<": It is a B2-Sequence.";
		}
		else
		{
			cout<<"Case #"<<c<<": It is not a B2-Sequence.";
		}
		
		cout<<endl<<endl;//�n����� 
		c++;//�������U�@������ 
	}
	return 0;
}
