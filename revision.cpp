#include <bits/stdc++.h>
using namespace std;
int largest_element(vector<int> &arr)
{
    int lar = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > lar)
        {
            lar = arr[i];
        }
    }
    return lar;
}
int second_largest(vector<int> &arr)
{
    int sl = INT_MIN, lar = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > lar)
        {
            sl = lar;
            lar = arr[i];
        }
        else if (arr[i] > sl && arr[i] < lar)
        {
            sl = arr[i];
        }
    }
    return sl;
}
bool check_array_sorted(vector<int> &arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > arr[(i + 1) % arr.size()])
        {
            count++;
        }
    }
    return count <= 1;
}
vector<int> remove_duplicates_from_sorted_array(vector<int> &arr)
{
    int prev = INT_MIN;
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != prev)
        {
            prev = arr[i];
            temp.emplace_back(arr[i]);
        }
        else if (arr[i] == prev)
        {
            continue;
        }
    }
    return temp;
}
void rotate_array_by_k(vector<int> &arr, int k)
{
    if (arr.empty())
        return;
    k = k % arr.size();

    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}
void move_zeroes_to_end(vector<int> &arr)
{
    int pos = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            arr[pos++] = arr[i];
        }
    }
    while (pos < arr.size())
    {
        arr[pos++] = 0;
    }
}
vector<int> union_of_two_sorted_arrays(vector<int> &arr1, vector<int> &arr2)
{
    if (arr1.empty() && arr2.empty())
        return {};
    if (arr1.empty())
        return arr2;
    if (arr2.empty())
        return arr1;
    vector<int> temp;
    int left = 0, right = 0;
    while (left < arr1.size() && right < arr2.size())
    {
        if(arr1[left]<arr2[right]){
            if(temp.empty() || temp.back()!=arr1[left]){
                temp.emplace_back(arr1[left]);
            }
            left++;
        }
        else if(arr1[left]>arr2[right]){
            if(temp.empty() || temp.back()!=arr2[right]){
                temp.emplace_back(arr2[right]);
            right++;
        }
    }
        else{
            if(temp.empty() || temp.back()!=arr1[left]){
                temp.emplace_back(arr1[left]);
            }
            left++;
            right++;
        }
    }
    while(left<arr1.size()){
        if(temp.empty() || temp.back()!=arr1[left]){
            temp.emplace_back(arr1[left++]);
        }
    }
    while(right<arr2.size()){
        if(temp.empty() || temp.back()!=arr2[right]){
            temp.emplace_back(arr2[right++]);
        }
    }
    return temp;
}
int find_missing_number(vector<int>&arr){
    int xorr1=0,xorr2=0;
    for(int i=0;i<arr.size();i++){
        xorr1^=arr[i];
        xorr2^=i+1;
    }
    return xorr1^xorr2;
}
int max_consec_ones(vector<int>&arr){
    int count=0;
    int max_count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            count++;
            max_count=max(max_count,count);
        }
        else{
            count=0;
        }
    }
    return max_count;
}
int num_that_occurs_once(vector<int>&arr){
    if(arr.empty())return -1;
    int xorr=0;
    for(int i=0;i<arr.size();i++){
        xorr^=arr[i];
    }
    return xorr;
}
int longest_subarray(vector<int>&arr,int target){
   int left=0;int right=0;
   int sum=0;
   int max_len=INT_MIN;
   while(right<arr.size()){
    while(left<=right && sum>target){
        sum-=arr[left];
        left++;
    }
    if(sum==target){
        max_len=max(max_len,right-left);
    }
    right+=1;
    if(right<arr.size()){
        sum+=arr[right];
    }
   }
   return max_len;
}
void two_sum(vector<int>&arr,int target){
    unordered_map<int,int>mpp;
    for(int i=0;i<arr.size();i++){
        int rem=target-arr[i];
        if(mpp.find(rem)!=mpp.end()){
            cout<<mpp[rem]<<" "<<i;
            return;
        }
        mpp[arr[i]]=i;
    }
}
void sort_arr_of_zero_one_and_twos(vector<int>&arr){
    int low=0,high=arr.size()-1,mid=0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
        else{
            throw invalid_argument("make sure the array only has 0's 1's and 2's");
        }
    }
}
int kadanes_algorithm(vector<int>&arr){
    if(arr.empty())return-1;
    int sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        max_sum=max(max_sum,sum);
        if(sum<0){
            sum=0;
        }
    }
    return max_sum;
}
vector<int> subarray_with_max_sum(vector<int>&arr){
    int sum=0;
    int max_sum=INT_MIN;
    int ansstart=0,start=0,end=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum>max_sum){
            max_sum=max(max_sum,sum);
            ansstart=start,end=i;
        }
        if(sum<0){
            sum=0;
            start=i+1;
        }
    }
    return {ansstart,end};

}
int buy_and_sell_stock(vector<int>&arr){
    int min_price=INT_MAX;
    int max_profit=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<min_price){
            min_price=arr[i];
        }
        else{
            max_profit=max(max_profit,arr[i]-min_price);
        }
    }
    return max_profit;
}
vector<int> rearrange_elements_by_sign(vector<int>&arr){
    vector<int>ans(arr.size());
    int posi=0;
    int negi=1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            ans[posi]=arr[i];
            posi+=2;
        }
        else{
            ans[negi]=arr[i];
            negi+=2;
        }
    }
    return ans;
}
int main()
{
    vector<int>arr={2,5,1,-1,8,-2,-4,-7};
    for(int i=0;i<arr.size();i++){
        cout<<rearrange_elements_by_sign(arr)[i]<<" ";
    }
}