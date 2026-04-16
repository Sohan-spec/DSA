#include<bits/stdc++.h>
using namespace std;

double helper(double x, long n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 1.0/helper(x,-(long)n);
    }
    if(n%2==1){
        return x*helper(x*x,(n-1)/2);
    }
    else{
        return helper(x*x,n/2);
    }
}
double optimal_soln(double x,int n){
    return helper(x,(long)n);
}
int main()
{
    cout<<optimal_soln(2,5);
}