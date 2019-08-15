#include<iostream>
#include<limits.h>
using namespace std;
int N=4;
int T[4][4];
void PrintPath(int i,int j);

class matrix{
public:
int m,n;

}M[4];

class Path{
    public:
int x_m,x_n;
int y_m,y_n;


};
Path P[4][4];
int main(){
            M[0].m=2;
            M[0].n=3;
            M[1].m=3;
            M[1].n=6;
            M[2].m=6;
            M[2].n=4;
            M[3].m=4;
            M[3].n=5;


        for(int len=1;len<=4;++len){


                      for(int j=len-1;j<N;++j){
                          int i=j-len+1;
                                    int min_=1000;
                                     for(int k=i;k<j;++k){

                                               int val= T[i][k]+T[k+1][j]+M[i].m*M[k].n*M[j].n;

                                                if(val<min_){
                                                    min_=val;
                                                     P[i][j].x_m=i;
                                                     P[i][j].x_n=k;
                                                     P[i][j].y_m=k+1;
                                                     P[i][j].y_n=j;

                                                }

                                     }
                                     if((i-j)!=0)
                                        {T[i][j]=min_;

                                        }




                      }

                }

       for(int i=0;i<N;++i){
            for(int j=0;j<N;++j)
                cout<<T[i][j]<<" ";
       cout<<endl;
       }
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j)
                {cout<<"("<<P[i][j].x_m<<","<<P[i][j].x_n<<")("<<P[i][j].y_m<<","<<P[i][j].y_m<<") ";}
       cout<<endl;
       }


       PrintPath(0,N-1);

            return 0;



}

void PrintPath(int i,int j){

    if((P[i][j].x_m-P[i][j].x_n)!=0)
        {cout<<"(";
            PrintPath(P[i][j].x_m,P[i][j].x_n);
            cout<<")";
        }
    else
//        cout<<"("<<P[i][j].x_n<<")";
        cout<<P[i][j].x_n;

     if((P[i][j].y_m-P[i][j].y_n)!=0)
     {cout<<"(";
         PrintPath(P[i][j].y_m,P[i][j].y_n);
         cout<<")";
     }
    else
//        cout<<"("<<P[i][j].y_m<<")";
cout<<P[i][j].y_m;


}

