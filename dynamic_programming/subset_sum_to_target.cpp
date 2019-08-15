#include<iostream>
#include<bits/stdc++.h>
using namespace std;

map <pair<int,int> , bool> m;

bool checkIfPossible(int *a,int n,int sum){
    if(m.find(make_pair(n,sum))!=m.end()) return m.at(make_pair(n,sum));

        if(sum==0){
            m.insert(make_pair(make_pair(n,sum),true));
            return true;
        }

        if(sum!=0 && n==0){
            m.insert(make_pair(make_pair(n,sum),false));
            return false;
        }
    bool check;
    if(a[n]<=sum){
        check= (checkIfPossible(a,n-1,sum-a[n]) or checkIfPossible(a,n-1,sum));
        m.insert(make_pair(make_pair(n,sum),check));
        return check;
    }
    check=checkIfPossible(a,n-1,sum);
    m.insert(make_pair(make_pair(n,sum),check));
    return check;

}

int main(){

int n,sum;
int *a=new int[n+1];

cin>>n>>sum;
for(int i=1;i<=n;++i) cin>>a[i];


if(checkIfPossible(a,n,sum)) cout<<"Yes"<<endl;
else cout<<"No"<<endl;


return 0;
}


