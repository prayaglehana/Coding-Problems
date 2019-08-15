
// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;
int minSwaps(int A[], int N);
// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

void showMap(unordered_map <int,int> &mp){
    cout<<"map : \n";
    for(auto it=mp.begin();it!=mp.end();++it)cout<<it->first<<" : "<<it->second<<endl;
    cout<<endl;
}

bool mycompare(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}
int minSwaps(int A[], int N){
    bool vis[N];
    vector<int> vec;
    unordered_map <int,int> mp;
    for(int i=0;i<N;++i){
        vis[i]=false;
        vec.push_back(A[i]);
    }

    sort(vec.begin(),vec.end());

    for(int i=0;i<N;++i){
        mp.insert(make_pair(vec[i],i));
    }
    //showMap(mp);
    int swaps=0;


    for(int i=0;i<N;++i){
        if(vis[i]==true) continue;

        vis[i]=true;

        int j=mp[A[i]];
        int cycle=1;
        while(vis[j]==false){
            ++cycle;
            vis[j]=true;
            j=mp[A[j]];
        }
        //cout<<"j"<<j<<" cycle "<<cycle<<endl;

        swaps+=(cycle-1);


    }

    return swaps;
}
