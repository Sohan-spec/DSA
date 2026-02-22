#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr){
    int max_sum=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int sum=arr[i];
        for(int j=i+1;j<arr.size();j++)
        {
            sum+=arr[j];
            max_sum=max(max_sum,sum);
        }
    }
    return max_sum;
}
int kadanes_algorithm(vector<int>&arr){
    if(arr.empty())return -1; //wtf man this shit crazy though, such a simple implementation
    long long max_sum=INT_MIN;
    long long sum=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        max_sum=max(max_sum,sum);
        if(sum<0){
            sum=0;
        }
    }if(max_sum<0)max_sum=0;
    return max_sum;
}
vector<int> kadanes_algorithm_with_indices(vector<int>&arr){
if(arr.empty())return {}; //wtf man this shit crazy though, such a simple implementation
    long long max_sum=LLONG_MIN;
    long long sum=0;
    int start=0,end=0,ansstart=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
        if(sum>max_sum){
            max_sum=sum;
            ansstart=start,end=i;
        }
        if(sum<0){
            sum=0;
            start=i+1;
        }
    }
    return{ansstart,end};
}
int main()
{
    vector<int>arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<brute_force(arr);
}