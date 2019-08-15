#include <iostream>
using namespace std;

int main() {

    int T;
    cin>>T;
    int ar[9];


    while(T--){
        int N;
        cin>>N;
        for(int i=0;i<9;++i) ar[i]=0;

        for(int i=0;i<N;++i){
            char ch;
            cin>>ch;

            if(ch=='!')      ar[0]=1;
            else if(ch=='#') ar[1]=1;
            else if(ch=='$') ar[2]=1;
            else if(ch=='%') ar[3]=1;
            else if(ch=='&') ar[4]=1;
            else if(ch=='*') ar[5]=1;
            else if(ch=='@') ar[6]=1;
            else if(ch=='^') ar[7]=1;
            else if(ch=='~') ar[8]=1;
        }
       char output[9];
       for(int i=0;i<9;++i) output[i]='\0';

       for(int i=0;i<N;++i){
             char ch;
            cin>>ch;

            if(ch=='!' &&     ar[0]==1) output[0]='!';
            else if(ch=='#'&& ar[1]==1) output[1]='#';
            else if(ch=='$'&& ar[2]==1) output[2]='$';
            else if(ch=='%'&& ar[3]==1) output[3]='%';
            else if(ch=='&'&& ar[4]==1) output[4]='&';
            else if(ch=='*'&& ar[5]==1) output[5]='*';
            else if(ch=='@'&& ar[6]==1) output[6]='@';
            else if(ch=='^'&& ar[7]==1) output[7]='^';
            else if(ch=='~'&& ar[8]==1) output[8]='~';
       }

       for(int i=0;i<9;++i)
        if(output[i]!='\0') cout<<output[i]<<" ";
    cout<<endl;

    }
	//code
	return 0;
}
