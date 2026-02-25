#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    
    for (int i = 0; i < nums.size(); i++)
    {
        bool swapped=false;
        for (int j = 0; j < nums.size() - 1; j++)
        {
            if (nums[j] == 0 && nums[j + 1] != 0)
            {
                swap(nums[j], nums[j + 1]);
                swapped=true;
            }
        }
        if(!swapped)return;
     
    }
}
void optimal_soln(vector<int>&arr){
    int j=-1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1){
        return;
    }
    for(int i=j+1;i<arr.size();i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

int main()
{
    vector<int>arr={0, 0, 0, 1, 3, -2};
    optimal_soln(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}