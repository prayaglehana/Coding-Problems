#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int T;
cin>>T;
while(T--){
    int D;
    cin>>D;
    char s[1000]="";
    cin>>s;


    if((strcmp(s, "PP")==0)||(strcmp(s, "P")==0)) cout<<0;
    else if(D<=2) cout<<-1;
    else {

            int countP=0;
            for(int i=0;i<D;++i) if(s[i]=='P')++countP;

            int requiredP=ceil(0.75*D-countP);
            int requiredPT=requiredP;
            cout<<"requiredP "<<requiredP<<endl;
            //cout<<"s"<<s[0];
            for(int i=2;i<D;++i){
                if(s[i]=='A')
                    {   //if(i==2) cout<<"ans "<<((s[i-1]=='P')||(s[i-2]=='P')||(((i+2)<N)&&((s[i+1]=='P')||(s[i+2]=='P'))))<<endl;

                        if((s[i-1]=='P'||s[i-2]=='P')&&(((i+2)<D)&&(s[i+1]=='P'||s[i+2]=='P'))) {--requiredPT;
                        cout<<"i: "<<i<<endl;
                        }

                    }

            }
            if(requiredPT<=0) cout<<requiredP;
            else cout<<-1;

    }
    cout<<endl;

}
return 0;
}
