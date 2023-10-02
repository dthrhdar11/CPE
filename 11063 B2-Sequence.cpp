#include <iostream>
#include <set>
using namespace std;

int main()
{	
	int n,i,t,c=1;
	
	while(cin>>n)//块计计秖 
	{
		int b[n]={0};//计皚 
		set<int> d;//set柑ぃ狡计
				   //ㄓ璸衡ㄢ计㎝琌狡 
		d.clear();//睲 
		
		for(i=0;i<n;i++)//块计 
		{
			cin>>b[i];
		}
		
		for(i=0;i<n;i++)//耞计琌B2 
		{
			if(b[i]<1)//B2ぃΤ璽计┪0
			{
				break;
			}
			else if(b[i-1]>=b[i]&&i-1>0)//B2兜ゑ玡兜 
			{							//i-1狦0穦拜肈 
				break;
			}
			for(t=i;t<n;t++)//ㄢ计 
			{
				d.insert(b[i]+b[t]);//盢ㄢ计㎝set柑
									//setぃ穦狡 
			}
		}
		
		if(d.size()==(n+1)*n/2)//狦setΤぶ杠碞计獶B2 
		{					   //size碞琌眔set柑计秖 
			cout<<"Case #"<<c<<": It is a B2-Sequence.";
		}
		else
		{
			cout<<"Case #"<<c<<": It is not a B2-Sequence.";
		}
		
		cout<<endl<<endl;//璶传ㄢ︽ 
		c++;//挡传掸代戈 
	}
	return 0;
}
