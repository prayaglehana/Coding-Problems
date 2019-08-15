#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(long long int n,long long int s)
{

    bool prime[n+1];
   // memset(prime, true, sizeof(prime));
    for(long long int i=2;i<=n;++i) prime[i]=true;

    for (long long int p=2; p*p<=n; p++)
    {

        if (prime[p] == true)
        {
            for (long long int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }


   prime[1]=false;
  long long int count_=0;
    for (long long int p=s; p<=n; p++)
       if (prime[p]){
               ++count_;
              // cout << p << " ";
       }


    cout<<count_ <<endl;;
}

// Driver Program to test above function
int main()
{
    long long int t;
    cin>>t;
    while(t--){
        long long int n,s;
        cin>>s>>n;
        SieveOfEratosthenes(n,s);

    }

    return 0;
}
