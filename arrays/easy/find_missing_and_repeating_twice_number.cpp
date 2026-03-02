#include <bits/stdc++.h>
using namespace std;
vector<int> brute_force(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] += 1;
    }
    int missing_number = -1;
    int repeated_no = -1;
    for (int i = 1; i <= n; i++)
    {
        if (mpp.find(i) == mpp.end())
        {
            missing_number = i;
        }
        else if (mpp[i] == 2)
        {
            repeated_no = i;
        }
    }
    return {repeated_no, missing_number};
}
vector<int> optimal_soln_1(vector<int>&arr){
    long long n=arr.size();
    long long sum1=(n*(n+1))/2;
    long long sum2=(n*(n+1)*(2*n+1))/6;
    long long sum=0,sum_squares=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        sum_squares+=(long long)arr[i]*(long long)arr[i];
    }
    long long val1=sum-sum1;
    long long val2=sum_squares-sum2;
    val2=val2/val1;
    long long repeating=(val1+val2)/2;
    long long missing=repeating-val1;
    return {(int)repeating,(int)missing};
}
int main()
{
    vector<int> arr = {1, 2, 3, 6, 7, 5, 7};
    for (int i = 0; i < 2; i++)
    {
        cout << optimal_soln_1(arr)[i] << " ";
    }
}