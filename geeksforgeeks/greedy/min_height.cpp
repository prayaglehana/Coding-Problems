#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
            int n, k, t; cin >> k >>  n;
            int ar[n];
            for(int i = 0 ; i < n; i++){
                cin >> ar[i];
            }
            if (n == 1) {cout<<0<<endl; continue;}
            sort(ar, ar+n);
            int ans = ar[n-1] - ar[0];
            int mini = ar[0]+k;
            int maxi = ar[n-1]-k;
            if(mini > maxi)  swap(mini, maxi);

            for(int i = 1; i < n-1; i++){

                int canbe_min = ar[i]-k;
                int canbe_max = ar[i]+k;
                if(canbe_min >= mini || canbe_max <= maxi)  continue; // if ar[i]  will not change our ans.

                //if range changes , update it such that it minimize our ans.
                if(maxi-canbe_min <= canbe_max-mini)
                    mini = canbe_min;
                else
                    maxi = canbe_max;
            }
            ans = min(ans, maxi-mini);
            cout<<ans<<endl;
        }
}
