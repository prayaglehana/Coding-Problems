#include<bits/stdc++.h>
using namespace std;

void showAr(int *a,int &n){
    cout<<endl;
    for(int i=0;i<n;++i)cout<<setw(3)<<i<<" ";cout<<endl;
    for(int i=0;i<n;++i)cout<<a[i]<<" ";
    cout<<endl;
}
long long int max_coin_piles(int k,int *a,int n){

    int i=0,j=n-1;

    long long int ans=0 ;
    showAr(a,n);

    while(i<(j-1)){
        if((a[j]-a[i])>k){
                cout<<"helo"<<endl;
            int diff=(a[j]-a[i])-k;
            ans+=(diff);

            int diff1=(a[i+1]-a[i]);
            int diff2=(a[j]-a[j-1]);

            if((diff1+diff2)>=diff)      return ans;

            int rem=diff-(diff1+diff2);

            int x1=rem/2;
            int x2=rem-x1;

            a[i]=a[i]+diff1+x1;
            a[j]=a[j]-diff2-x2;
            cout<<" i "<<i<<" j "<<j<<" : ";
            showAr(a,n);

            bool flag=false;

            if(a[i+1]<a[i]) {++i;flag=true;}
            if(a[j-1]>a[j]) {--j;flag=true;}

            if(!flag) return ans;
        }

        else
            return ans;
    }

    return ans;
}


int main(){
int t;
cin>>t;
while(t--){

    int n,k;
    cin>>n>>k;
    int *a=new int[n];

    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);

    cout<<max_coin_piles(k,a,n)<<endl;

    sort(a,a+n);
    showAr(a,n);

}

return 0;
}
