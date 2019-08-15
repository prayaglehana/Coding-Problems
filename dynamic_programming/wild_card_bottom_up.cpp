#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){

string str,pattern;
cin>>str;
cin>>pattern;
int n=(str).length();
int m=(pattern).length();

 if (m == 0)
        {cout<<(n == 0);
        return 0;}

    bool dp[n + 1][m + 1];


    memset(dp, false, sizeof(dp));

    dp[0][0] = true;

    for (int j = 1; j <= m; j++)
        if (pattern[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
// string in rows(i) pattern in columns(j)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (pattern[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] ||
                               dp[i - 1][j];
            else if (pattern[j - 1] == '?' || str[i - 1] == pattern[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = false;
        }
    }

   cout<<dp[n][m];

return 0;}

