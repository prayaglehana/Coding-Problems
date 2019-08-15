#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void showVector(vector<int> v){
    cout<<"show vector ";
    for(int x:v)cout<<x<<" ";
    cout<<endl;

}

unordered_map <char, vector<int>> m;
unordered_map <char,bool> h;
int min_si=-1,min_ei=-1;

int find_indx(vector<int> v,int x,bool inclusive=true){
    int s=0;
    int e=v.size()-1;
    int ans=-1;

                while(s<=e){

                        int mid=(s+e)/2;
                        if(v[mid]==x){
                            if(inclusive) return v[mid];
                            s=mid+1;
                        }

                       else if(v[mid]>x) {
                            ans=mid;
                            e=mid-1;
                        }
                        else{
                            s=mid+1;
                        }
                }



     if(ans!=-1) return v[ans];
    else return -1;
}
int getMaxLength(int s,string s1,string s2){
           // cout<<" get max length called with s= "<<s<<endl;


            int max_indx=-1;
            int nextJump=s1.length();


            for(auto it=h.begin();it!=h.end();++it){
                char ch=it->first;
                vector <int > v=m[ch];
                int e=find_indx(v,s);

                //showVector(v);
                //cout<<"ch: "<<ch<<" e "<<e <<endl;
                if(e==-1) return s1.length();


                   max_indx=max(max_indx,e);
                   if(find_indx(v,s,false)!=-1)
                    nextJump=min(nextJump,find_indx(v,s,false));
            }


            if(min_si==-1) {
                min_si=s;
                min_ei =max_indx;

            }
            else if((max_indx-s)<(min_ei-min_si)){

                min_si=s;
                min_ei =max_indx;
            }


             return nextJump;

}
int main(){

string s1,s2;
getline(cin,s1);
getline(cin,s2);
int s=-1;

for(int i=0;i<s2.length();++i){
    h[s2[i]]=true;
}


for(int i=0;i<s1.length();++i){
    vector <int > v;
    if(h.find(s1[i])!=h.end()){

          if(m.find(s1[i])==m.end()){
                if(s==-1) s=i;
                v.push_back(i);
                m.insert(make_pair(s1[i],v));
            }
            else{
                v=m[s1[i]];
                v.push_back(i);
                m.erase(s1[i]);
                m.insert(make_pair(s1[i],v));
            }

    }
}




//for(auto it=m.begin();it!=m.end();++it){
//            cout<<it->first<<" : ";
//
//        vector<int> v=it->second;
//
//        for(int x:v)cout<<x<<" ";
//    cout<<endl;
//}

//cout<<"s "<<s<<endl;
if(s==-1){
        cout<<"No string";
        return 0;

}
if(s>0 && h.size()==1) {
    cout<<s1[s];
    return 0;
}
if(s2.length()>1){
        do{
          s=getMaxLength(s,s1,s2);
    }
    while(s!=-1 && s<s1.length());
}
else{
    cout<<s2;
    return 0;
}


if(min_ei==-1) cout<<"No string";
else {
        for(int i=min_si;i<=min_ei;++i)
            cout<<s1[i];
}
cout<<endl;





return 0;}
