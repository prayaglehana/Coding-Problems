#include<iostream>
using namespace std;
void printNDIGIT(string s,int ND,int N){
    if(N<=0){
            cout<<s<<" ";
            return;
    }
    for(int i=ND;i<=9;++i)
            {   char d=i+'0';
                //string d=x;
                printNDIGIT(s+d,i+1,N-1);
            }

}


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        printNDIGIT("",1,N);
        cout<<endl;

    }
    return 0;
}
