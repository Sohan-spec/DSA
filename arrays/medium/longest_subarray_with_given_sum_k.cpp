#include <bits/stdc++.h>
using namespace std;
int longest_subarray_brute_force(vector<int> &arr, int target)
{ // this takes O(n^2)
    int max_len = 0;
    for (int i = 0; i < arr.size(); i++) // this will iterate through all elements and fixes the starting index
    {
        int current_sum = 0;
        for (int j = i; j < arr.size(); j++) // this will take a specific element and go till the end and fixes the ending index
        {
            current_sum += arr[j];
            if (current_sum == target)
            {
                max_len = max(max_len, j - i + 1);
            }
        }
    }
    return max_len;
}
int optimal_soln(vector<int> &arr, int target)
{
    int left = 0;
    int right = 0;
    long long sum = arr[0];
    int max_len = 0;
    while (right < arr.size())
    {
        while(left<=right && sum>target){
            sum-=arr[left];
            left++;
        }
        if(sum==target){
            max_len=max(max_len,right-left+1);
        }
        right += 1;
        if (right < arr.size())
        {
            sum += arr[right];
        }
    }
    return max_len;
}
int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    cout << optimal_soln(arr, 15);
    return 0;
}
