#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,l,k;
	cin>>n>>l>>k;
	int m[l],t[l];
	int x;
	for(int i=0;i<l;i++)
	{
		cin>>x;
		m[i]=x;
		t[i]=x;
	}	
	int f[l];
	f[0] = max(1,m[0]-k);
	f[l-1] = min(m[l-1]+k,n);
	int ans=1;
	int low=1,high=n/l;
	int a = (low+high)/2;
//	cout<<low<<" "<<high<<" "<<a<<endl;
	while(low<=high)
	{
		for(int i=0;i<l-2;i++)
		{
			if((f[i] + a) < (m[i+1] - k))
			{
		//		cout<<"1 ";
				f[i+1] = m[i+1] - k;
			}
			else if((f[i]+a) <= m[i+1])
			{
		//		cout<<"2 ";
				f[i+1] = f[i]+a;
			}
			else if((f[i]+a) > (m[i+1] + k))
			{
		//		cout<<"3 ";
				high =a-1;
				a = (low+high)/2;	
				break;

			}
			else if((f[i]+a) >= m[i+1])
			{
//				cout<<"4 ";
				f[i+1] = f[i] + a;
			}
			if (i==l-3)
			{
				if ((f[l-1]-f[l-2]) >= a)
				{
					ans = a;
					low = a+1;
					for(int j=0;j<l;j++)
						t[j] = f[j];
				}
				else
					high = a-1;
				a = (low+high)/2;
			}
		}
//		cout<<low<<" "<<high<<" "<<a<<endl;
	}
	cout<<ans<<endl;
	for(int j=0;j<l;j++)
		cout<<t[j]<<" ";
	cout<<endl;

	return 0;
}
