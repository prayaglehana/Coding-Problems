#include <bits/stdc++.h>
using namespace std;
class job{
    public:
        int id;
        int deadline;
        int profit;

        job(int id_,int d,int p){
            id=id_;
            deadline=d;
            profit=p;
        }
};

bool mycompare(job a,job b){
    return a.profit>b.profit;
}


int main() {

    int T;
    cin>>T;


    while(T--){
        int n;
        cin>>n;
          vector <job> v;

        int max_t=0;

        for(int i=1;i<=n;++i){
            int id,d,p;
            cin>>id>>d>>p;
            max_t=max(max_t,d);
            job j(id-1,d,p);
            v.push_back(j);
        }

        sort(v.begin(),v.end(),mycompare);

//        for(int i=0;i<n;++i){
//            cout<<v[i].id<<" "<<v[i].deadline<<" "<<v[i].profit<<endl;
//        }
        int max_profit=0;
        int max_jobs=0;

        int *slot=new int[max_t+1];
        for(int i=0;i<=max_t;++i) slot[i]=-1;

        for(int i=0;i<n;++i){

                for(int t=v[i].deadline;t>=1;--t){
                    if(slot[t]==-1){

                        slot[t]=i;
                        break;
                    }
                }
            }


        int max_P=0;
        int max_J=0;

        for(int t=1;t<=max_t;++t){
             //cout<<"at t "<<t<<" : "<<slot[t]<<endl;
             if(slot[t]!=-1){
               max_P+=v[slot[t]].profit;
               ++max_J;
             }
        }

        cout<<max_J<<" "<<max_P<<endl;
    }
	return 0;
}
