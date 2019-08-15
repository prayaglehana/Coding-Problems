#include<iostream>
#include<stack>

using namespace std;
int N=2;
void permute(int *a);
int maxRepeating(string str);
void swap(int *x,int *y);
string showstack(stack <int> gq);
stack<int> s;
int totalCount=0;

int freq[20];

int main(){
int ar[20];



            for(int i=0;i<N;++i){
                ar[i]=i+1;
                }
freq[0]=11;
freq[1]=11;
                permute(ar);


cout<<" ans "<<totalCount;

}

void permute(int *a){
int flag=true;
        for(int i=0;i<N;++i){
                if(freq[i]>0){
                        flag=false;
                      s.push(a[i]);
                            --freq[i];

                                permute(a);


                           ++freq[i];
                        s.pop();
                }



        }

if(flag){

    string str=showstack(s);

  int cnt= maxRepeating(str);
if(cnt<=2)
     ++totalCount;
//cout<<endl;
}



}
void calculateIf(int d,stack <int> g){


}
string showstack(stack <int> gq){
    string str="";
    stack <int>g=gq;
    while(!g.empty()){
        //cout<<g.top();
        str+=char(g.top());
        g.pop();
    }
return str;

}

int maxRepeating(string str)
{
    int len = str.length();
    int count = 0;

    // Find the maximum repeating character
    // starting from str[i]
    char res = str[0];
    for (int i=0; i<len; i++)
    {
        int cur_count = 1;
        for (int j=i+1; j<len; j++)
        {
            if (str[i] != str[j])
                break;
            cur_count++;
        }

        // Update result if required
        if (cur_count > count)
        {
            count = cur_count;
            res = str[i];
        }
    }
    return count;
}



