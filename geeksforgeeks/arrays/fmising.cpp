#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;

	while(t--){
	    int n;
	    cin>>n;

	    unsigned long long int nsum=n*(n+1)/2;
	    unsigned long long int n2sum=n*(n+1)*(2*n+1)/6;


	   unsigned long long int a2sum=0,asum=0;



	    for(int i=0;i<n;++i){
	        int num;
	         cin>>num;

	         asum+=num;
	         a2sum+=num*num;
	    }

	   if(asum>=nsum){
	       	    unsigned long long int xminusy=asum-nsum;

	    unsigned long long int x2minusy2=a2sum-n2sum;

	    unsigned long long int xplusy=x2minusy2/xminusy;

	   //cout<<"1"<<xminusy<<" "<<x2minusy2<<" "<<nsum<<" "<<n2sum<<" "<<asum<<" "<<a2sum<<endl;

        unsigned long long int x=(xminusy+xplusy)/2;
        unsigned long long int y=(x-xminusy);

	    cout<<x<<" "<<y<<endl;
	   }
	   else{
	    unsigned long long int yminusx=nsum-asum;

	    unsigned long long int y2minusx2=n2sum-a2sum;

	    unsigned long long int yplusx=y2minusx2/yminusx;


        unsigned long long int y=(yminusx+yplusx)/2;
        unsigned long long int x=(y-yminusx);

	   // cout<<"2"<<yminusx<<" "<<y2minusx2<<" "<<nsum<<" "<<n2sum<<" "<<asum<<" "<<a2sum<<endl;

	    cout<<x<<" "<<y<<endl;
	   }

	}
	return 0;
}
