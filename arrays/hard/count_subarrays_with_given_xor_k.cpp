#include <bits/stdc++.h>
using namespace std;
int brute_force(vector<int> &arr, int target)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int xorr = 0;
        for (int j = i; j < arr.size(); j++)
        {
            xorr ^= arr[j];
            if (xorr == target)
                count++;
        }
    }
    return count;
}
int optimal_soln(vector<int> &arr,int k)
{
    unordered_map<int, int> mpp;
    int count = 0;
    int xr=0;
    mpp[xr]=1;
    for(int i=0;i<arr.size();i++){
        xr^=arr[i];
        int x=xr^k;
        count+=mpp[x];
        mpp[xr]++;
    }
    return count;
}
int main()
{
    vector<int>arr={4, 2, 2, 6, 4};
    cout<<optimal_soln(arr,6);
}
