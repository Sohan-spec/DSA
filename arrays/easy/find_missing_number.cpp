#include <bits/stdc++.h>
using namespace std;
int brute_force(vector<int> &arr)
{
    if(arr.empty())return -1;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] !=i)
        {
            return i;
        }
    }
    return arr.size();
}
int optimal_soln(vector<int>&arr)
{
    if(arr.empty())return -1;
    int sum=0;
    for(int i=0;i<arr.size();i++)
    {
        sum+=arr[i];
    }
    int expected_sum=(arr.size()*(arr.size()+1))/2;
    return expected_sum-sum;
}
int main()
{
    vector<int> arr = {8, 2, 4, 5, 3, 7, 1};
    cout << optimal_soln(arr);
}