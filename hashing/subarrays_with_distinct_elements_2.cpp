#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j<n && m.find(arr[j])==m.end())
        {
            m[arr[j]]=1;
            j++;
        }
        sum=sum + ((j-i)*(j-i+1))/2;
        sum=sum%1000000007;
        m.erase(arr[i]);
    }
    cout<<sum;
    return 0;
}
