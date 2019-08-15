#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int MAX=0;
vector <int> v;
map<int,int> HASH;
int* hash__array(int A[], int n)
{

    int* hash_ = new int[MAX]; //MAX is the maximum possible value of A[i]
    for(int i=0;i<=MAX;i++) hash_[i]=-1; //initialize hash_ to -1.
    int count_ = 0;
    for(int i=0;i<n;i++) // Loop through elements of array
    {

        if(hash_[A[i]] == -1) // A[i] was not assigned any hash_ before
        {
            hash_[A[i]] = count_; // Assigning hash_ to A[i]
            count_++;
            v.push_back(A[i]);
            continue;
        }
        for(int j=0;j<i;j++)
        {
            if(hash_[A[j]] > hash_[A[i]]) // All the hash_es greater than previous hash_ of A[i] are decremented.
                hash_[A[j]]--;
        }
        hash_[A[i]] = count_ - 1; // Assigning a new hash_ to A[i]
    }

    return hash_;
}
bool mycompare(int a,int b){
    return HASH[a]<HASH[b];
}


int main(){
    int N;
    cin>>N;
    int *a=new int[100001];



        for(int i=0;i<N;i++)
    {
    	cin>>a[i];
        if(HASH.find(a[i])==HASH.end())
            v.push_back(a[i]);
        HASH[a[i]]=i;
    }




    sort(v.begin(),v.end(),mycompare);
//for(int i=0;i<N;++i){
//    cout<<a[i]<<" "<<hash_[a[i]]<<endl;
//}
for(int x:v) cout<<x<<endl;

    return 0;

}
