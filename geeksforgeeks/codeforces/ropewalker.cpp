#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int ar[3],d;
    cin>>ar[0]>>ar[1]>>ar[2]>>d;

    sort(ar,ar+3);
    //cout<<ar[0]<<" "<<ar[1]<<" "<<ar[2]<<endl;
    int min_steps=0;
    if((ar[1]-ar[0])<d )
            min_steps=min_steps+(d-(ar[1]-ar[0]));
    if((ar[2]-ar[1])<d)
        min_steps=min_steps+(d-(ar[2]-ar[1]));


    cout<<min_steps;

    return 0;
}


