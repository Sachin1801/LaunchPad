#include<iostream>
#include<vector>
#include<stack>
using namespace std ;

void next_greater(int a[], int n, vector<int> ans)
{
    stack<int> ans ;
    int i=0,j=n-1;
    while(i<=n)
    {
        if(a[j]>a[i])
    }
}

int main(){
    int a[]={2,5,9,3,1,12,6,8,7};
    int n= sizeof(a)/sizeof(int);

    vector<int> ans;

    next_greater(a,n,ans);

    return 0;
}