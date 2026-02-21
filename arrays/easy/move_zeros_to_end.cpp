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
int main()
{
    vector<int>arr={0, 0, 0, 1, 3, -2};
    moveZeroes(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<endl;
    }
}