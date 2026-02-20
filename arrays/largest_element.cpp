#include<bits/stdc++.h>
using namespace std;
int brute_force(vector<int>&arr)
{
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}
int optimal_soln(vector<int>&arr)
{
    int max=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        if(max<arr[i])
        {
            max=i;
        }
    }
    return arr[max];
}
int main()
{
    vector<int>arr={3,6,1,8,9,2,10};
    cout<<"brute: "<<brute_force(arr)<<endl;
    cout<<"Optimal: "<<optimal_soln(arr);
    return 0;
}