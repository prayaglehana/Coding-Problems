#include<bits/stdc++.h>
using namespace std;

void showStack(stack<int> s){
    cout<<"stack : ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;

    int *h=new int[n];

    for(int i=0;i<n;++i){
        cin>>h[i];
    }
// for(int i=0;i<n;++i){
//        cout<<setw(3)<<i<<" ";
//    }
  //  cout<<endl;

    stack <int> s;

    int *mp =new int[n];


    for(int i=n-1;i>=0;--i){

            while(!s.empty() && h[i]>=h[s.top()]){
                    int t=s.top();
                    s.pop();
                    if(!s.empty()) mp[t]=s.top();
                    else mp[t]=-1;
                }

                if(s.empty()){
                    mp[i]=-1;
                }
                else{
                    mp[i]=s.top();
                }
                s.push(i);

                //showStack(s);

        }




        while(!s.empty()){
                    //cout<<"top"<<s.top()<<endl;
                    int t=s.top();
                    s.pop();
                    if(!s.empty()) mp[t]=s.top();
                    else mp[t]=-1;
        }

   int sum=0;
   int m=1000000001;
   for(int i=0;i<n;++i){
        if(mp[i]!=-1)sum=(sum+h[mp[i]]%m)%m;
   }

   cout<<sum<<endl;

}

return 0;}
