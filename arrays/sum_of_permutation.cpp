

#include <bits/stdc++.h>
using namespace std;
long long getSum(int [],int n);
main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];

		cout<<getSum(a,n)<<endl;
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method */

long long int fact(int n){
    if(n==1) return 1;
    return (n*fact(n-1));
}

long long int power(int x,int p){
    long long int ans=1;
    for(int i=1;i<=p;++i){
        ans=ans*10;
    }
    return ans;
}
long long getSum(int A[],int n)
{
    long long int sum_=0;
    long long int f=fact(n-1);
    long long int s=n*(n+1)/2;
    for(int p=0;p<n;++p){
        sum_=(sum_+(power(10,p)*((f*s)%1000000007))%1000000007)%1000000007;
    }
    return sum_;
}
