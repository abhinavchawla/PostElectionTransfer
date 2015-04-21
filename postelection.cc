#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,l,k;
	cin>>n>>l>>k;
	int m[l];
	for(int i=0;i<l;i++)
		cin>>m[i];
	int f[l],t[l];
	f[0]=max(1,m[0]-k);
	f[l-1] = min(n,m[l-1]+k);
	int ans=0;
	for(int a=1;a<n;a++)
	{
		for(int i=0;i<l-2;i++)
		{
			if((f[i] + a) < (m[i+1] - k))
			{
//				cout<<"1 ";
				f[i+1] = m[i+1] - k;
			}
			else if((f[i]+a) <= m[i+1])
			{
//				cout<<"2 ";
				f[i+1] = min(f[i] + a,n);
			}
			else if((f[i]+a) > (m[i+1] + k))
			{
//				cout<<"3 ";
				break;
			}
			else if((f[i]+a) >= m[i+1])
			{
//				cout<<"4 ";
				f[i+1] = min(f[i] + a,n);
			}
			if (i==l-3 && ((f[l-1]-f[l-2]) >= a))
			{
				ans = a;
				for(int j=0;j<l;j++)
					t[j] = f[j];
			}
		}
	}
	cout<<ans<<endl;
	for(int j=0;j<l;j++)
		cout<<t[j]<<" ";
	cout<<endl;
	return 0;
}
