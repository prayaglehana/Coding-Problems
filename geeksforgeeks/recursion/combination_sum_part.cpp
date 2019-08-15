#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printOutput(int *output,int len){
//    for(int i=0;i<len;++i){
//        cout<<output[i]<<" ";
//    }

    sort(output, output+len);
    for(int i=0;i<len;++i){
        cout<<output[i]<<" ";
    }
    cout<<endl;
}
void generate_subset(int *input,int *output,int i,int j,int &N,vector<string> &s,int &sum){
	if(i>=N){
		//cout<<output<<" ";
		if(j!=0){
            string str="";
            int op[20];
            for(int u=0;u<j;++u){
                op[u]=output[u];
            }

            //printOutput(output,j);
            sort(op, op+j);

            str="("+to_string(op[0])+" ";
            for(int k=1;k<j-1;++k){

                  str=str+to_string(op[k])+" ";

            }
            if(j!=1) str=str+to_string(op[j-1])+")";
            else
                str[str.length()-1]=')';




            if(accumulate(op, op+j, 0)==sum ){
                           // cout<<" str "<<str<<endl;
                            s.push_back(str);
            }
		}


		return;
	}
	//rec case
	output[j] = input[i];
	generate_subset(input,output,i+1,j+1,N,s,sum);
	//output[j] = '\0';
	generate_subset(input,output,i+1,j,N,s,sum);

}

int main(){
    int T;
    cin>>T;
    while(T--){
            int N;
            int sum;
           // int test[]={8,5,3,1,45,6};
           // sort(test,test+6);
            //for(int u=0;u<6;++u)cout<<test[u]<<" ";
            //cout<<endl;

            cin>>N;

            int input[20],output[20];


            for(int i=0;i<N;++i) cin>>input[i];
            cin>>sum;

            vector <string> s;
            s.clear();
            generate_subset(input,output,0,0,N,s,sum);
           // cout<<" total elements "<<s.size();

           if(s.size()>0){
                        sort(s.begin(),s.end());

                       vector<string>::iterator ip;
                       ip = unique(s.begin(), s.begin() + N);
                       s.resize(distance(s.begin(), ip));


                        for(string x:s){ //for each loop
                           cout<<x;
                      }
           }
           else{
                    cout<<"Empty";
           }

          cout<<endl;

    }







	return 0;
}
