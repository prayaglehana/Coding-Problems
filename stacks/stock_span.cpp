#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void showStack(stack<int> s){
    cout<<"Stack ";
    while(!s.empty()){
        cout<<s.top()<<" ";s.pop();
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int *a=new int[n];

    for(int i=0;i<n;++i)
        cin>>a[i];

    int i=0;
    int *span=new int[n];
    stack<int> stck;

while(i<n){


            while(!stck.empty() && a[stck.top()]<=a[i]) stck.pop();
            //while(!stck.empty()&& stck.top()>a[i])stck.pop();


            if(stck.empty())span[i]=i+1;
            else span[i]=i-stck.top();


            stck.push(i);

            ++i;
        //showStack(stck);
}
for(int i=0;i<n;++i) cout<<span[i]<<" ";
cout<<"END"<<endl;

return 0;
}




