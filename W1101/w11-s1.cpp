#include <iostream>
#define MAXN 11000
using namespace std;

int count(int src,int digit)
{
	int ans=0;
	while(1)
	{
		if(src<10&&src>=0)
		{
			ans+=(src==digit);
			break;
		}
		ans+=((src%10)==digit);
		src/=10;
	}
	return ans;
}

int main()
{
	int arr[MAXN];
	int n,digit=0,ans=0;
	cout<<"请输入数据的个数[1..10000]"<<endl;
	cin>>n;
	cout<<"请输入"<<n<<"个正整数"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"请输入数码[0..9]"<<endl;
	cin>>digit;
	for(int i=0;i<n;i++)
	{
		ans+=count(arr[i],digit);
	}
	cout<<n<<"个数中含有"<<digit<<"的个数 : "<<ans<<endl;
	return 0;
}
