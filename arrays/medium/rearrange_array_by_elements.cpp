#include<bits/stdc++.h>
using namespace std;
vector<int> brute_force(vector<int>&nums){
        vector<int>pos_array;vector<int> neg_array;
        vector<int>result_array(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                pos_array.emplace_back(nums[i]);
            }
            else{
                neg_array.emplace_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size()/2;i++)
        {
            result_array[2*i]=pos_array[i];
            result_array[2*i+1]=neg_array[i];
        }
        return result_array;
}
vector<int>optimal_soln(vector<int>&nums)
{
    int posindex=0;
    int negindex=1;
    vector<int>result(nums.size());
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>0){
            result[posindex]=nums[i];
            posindex+=2;
        }
        else{
            result[negindex]=nums[i];
            negindex+=2;
        }
    }
    return result;
}
int main()
{
    vector<int>arr={2, 4, 5, -1, -3, -4};
    vector<int>temp=optimal_soln(arr);
    for(auto it:temp){
        cout<<it<<endl;
    }
}