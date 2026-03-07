#include<bits/stdc++.h>
using namespace std;
int ideal_binary_search_soln(int n){
    if(n==0)return 0;
    int low=0,high=n;
    int ans=1;
    while(low<=high){
        int mid=(low+high)/2;
        if((mid * mid)<=n){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
double multiply(double num,int n){
double ans=1.0;
for(int i=1;i<=n;i++){
    ans=ans*num;
}
return ans;
}
double find_nth_root(double num,int n){
    double low=0,high=num;
    double eps=1e-6;
    while((high-low)>eps){
        double mid=(low+high)/2.0;
        if(multiply(mid,n)<num){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return low;
}
int main()
{
    cout<<find_nth_root(27,3);
}