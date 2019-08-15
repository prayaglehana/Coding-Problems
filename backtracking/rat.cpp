
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;

	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}

	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/*The function returns a sorted array of strings which represents
the directions mouse will take to reach the destination.
You are required to complete the below method. */

void getPath(int i,int j,vector<string> &res,string op,int m[MAX][MAX],int &n){
    if(i<0 or j<0 or i>=n or j>=n ) return;
    if(m[i][j]==0 or m[i][j]==2) return;

    if(i==(n-1) and j==(n-1)){
        res.push_back(op);
    }

    m[i][j]=2;

    getPath(i+1,j,res,op+"D",m,n) ;//down
    getPath(i,j+1,res,op+"R",m,n) ;//right
    getPath(i,j-1,res,op+"L",m,n); //left
    getPath(i-1,j,res,op+"U",m,n); //up
    m[i][j]=1;

}
vector<string> printPath(int m[MAX][MAX], int n)
{
    vector<string> res;


    getPath(0,0,res,"",m,n);

    return res;
}
