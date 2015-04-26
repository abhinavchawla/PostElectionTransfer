/*a) Author(s): Abhinav Chawla, Apoorv Vikram Singh, Siddartha Sekhar Padhi
  b) Email Id: Abhinav.Chawla@iiitb.org, ApoorvVikram.Singh@iiitb.org, SiddarthaSekhar.Padhi@iiitb.org
  c) Version: 2.3(Version 1 consisted of Linear Search)
  d) Date: 24/4/2015
  e) Description: The code here helps in  achieving its goal of transferring station masters to different stations by some distance so as to                   maximize the minimum distance between any pair within the restrictions of the contract.
  f) Constraints: L<10^5
  g) Order = O(L(lg(N/L)))
*/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,l,k;
	cin>>n>>l>>k; //taking input

      /*  1. n is the total number of stations. 
	  2. l is the number of stations which have station masters. 
	  3. k is the maximum number of stations by which a station master can move. */   

	int m[l],t[l];

      /* m[i] is the position of the ith station master originally.
	 t[i] will hold the position of the ith station master finally. */

	int x;
	for(int i=0;i<l;i++)
	{
		cin>>x; //taking input
		m[i]=x;
		t[i]=x;
	}	

	int f[l]; // A temporary array required during search of the optimal solution
	f[0] = max(1,m[0]-k); //Shifting the left most station master to as left possible
	f[l-1] = min(m[l-1]+k,n); //Shifting the right most station master to as right possible
	int ans=1;
	int low=1,high=(n/(l-1)); 
	int a = (low+high)/2; 

      /*  1. ans is the final answer
	  2. low and high are the values for the binary search. Initial low is 1 while initial high is n/l-1 because that is the maximum 
	     difference we can ever have.
	  3. a is the mid value of low and high.
		
	  We are choosing an a which could be an answer to our solution. It changes after every iteration. */
      /* A Dynamic Programming Solution is as follows. */
	while(low<=high) 
	{
		for(int i=0;i<l-2;i++)
		{
			if((f[i] + a) < (m[i+1] - k))    //This case is very far from earlier master so we get the master back. 
						       //This will help in future as it gives much more stations to cover for further masters
			{
				f[i+1] = m[i+1] - k;
			}
			else if((f[i]+a) <= m[i+1])      //This case will send the station master by a distance of 'a' forward.
			{
				f[i+1] = f[i]+a;
			}
			else if((f[i]+a) > (m[i+1] + k)) //This case means that it can't go anywhere to get 'a' as minimum distance. 
							 //Hence we decrease a and break.
			{
				high =a-1;
				a = (low+high)/2;	
				break; 

			}
			else if((f[i]+a) >= m[i+1]) //This case is similar to second case, deriving from the third case.
			{
				f[i+1] = f[i] + a;
			}
			if (i==l-3)               //This if condition will arise when we have completed everything and we realise that 'a' is 						       //the correct solution. Though we can obviously go further and hence we increase 'a' and 
						  //start again.
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
	}
		
	cout<<ans<<endl;
	for(int j=0;j<l;j++)
		cout<<t[j]<<" "; //printing answer
	cout<<endl;

	return 0;
}
