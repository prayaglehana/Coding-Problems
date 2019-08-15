#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
 {
    int t;
    cin>>t;
	int dp[100][100];


    while(t--){
                    	//code

            	int E,F;
            	cin>>E>>F;
            	for(int j=0;j<=F;++j){
            	    dp[1][j]=j;
            	}
            	for(int i=0;i<=E;++i){
            	    dp[i][1]=0;
            	}
            	dp[1][1]=1;


                for(int i=2;i<=E;++i){
                    for(int j=1;j<=F;++j){
                        int MIN_=INT_MAX;
                        for(int k=1;k<=j;++k){
                            int breaks=dp[i-1][k-1];
                            int doesNotBreak=dp[i][j-k];
                            MIN_=min(MIN_,1+max(breaks,doesNotBreak));
                        }
                    dp[i][j]=MIN_;
                    }
                }

//                for(int i=1;i<=E;++i){
//                    for(int j=1;j<=F;++j){
//                        cout<<setw(2)<<dp[i][j]<<" ";
//                    }
//                    cout<<endl;
//                }

                cout<<dp[E][F]<<endl;
    }


	return 0;
}
