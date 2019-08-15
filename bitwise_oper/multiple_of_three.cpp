#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int power(int x, unsigned int y, int p)  /* Iterative Function to calculate (x^y)%p in O(log y) */
{
    int res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int main(){
    int T;
    cin>>T;
    while(T--){
         char str[1000];
         cin>>str;
        //getline (cin, str);
        cout<<
        int ans=0;
        for(int i=strlen(str)-1;i>=0;--i){
            if(str[i]=="1")ans+= power(2,i,3) ;
        }
        cout<<"ans"<<ans<<endl;

        cout<<str<<endl;


    }
return 0;
}

