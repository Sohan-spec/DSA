#include<bits/stdc++.h>
using namespace std;
vector<int> brute_force(vector<int>&arr){
    if(arr.empty())return {};
    int count0=0,count1=0,count2=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==0)count0++;
        else if(arr[i]==1)count1++;
        else if(arr[i]==2)count2++;
        else throw invalid_argument("invalid input, only include 0's, 1's and 2's");
    }
    int index=0;
    while(count0--){
        arr[index++]=0;
    }
    while(count1--){
        arr[index++]=1;
    }
    while(count2--){
        arr[index++]=2;
    }
    return arr;
}
void dutch_national_flag_algo(vector<int>&arr)
{
    int low=0;
    int high=arr.size()-1;
    int mid=0;
    while(mid<=high)
    {
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main()
{
    vector<int>arr={0,1,2,1,0,2,1};
    dutch_national_flag_algo(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}