#include<bits/stdc++.h>
using namespace std;
double brute_force(vector<int>&arr1,vector<int>&arr2){
    int left=0,right=0;
    vector<double>temp;
    while(left<arr1.size() && right<arr2.size()){
        if(arr1[left]<=arr2[right]){
            temp.push_back(arr1[left]);
            left++;
        }
        else if(arr1[left]>arr2[right]){
            temp.push_back(arr2[right]);
            right++;
        }
    }
    while(left<arr1.size()){
        temp.push_back(arr1[left]);
        left++;
    }
    while(right<arr2.size()){
        temp.push_back(arr2[right]);
        right++;
    }
    double median=0;
    int n=temp.size();
    if(n%2==1){
        median=temp[n/2];
    }else{
       median = (temp[n/2] + temp[(n/2) - 1]) / 2.0;
    }
    return median;
}
double optimal_soln(vector<int>&arr1,vector<int>&arr2){
    if(arr1.size()>arr2.size()) return optimal_soln(arr2,arr1);
    int n1=arr1.size();
    int n2=arr2.size();

    int low=0,high=n1;
    while(low<=high){
        int cut1=(low+high)/2;
        int cut2=(n1+n2+1)/2 -cut1;

        int left1=cut1==0?INT_MIN : arr1[cut1-1];
        int left2=cut2==0?INT_MIN : arr2[cut2-1];

        int right1=cut1==n1?INT_MAX : arr1[cut1];
        int right2=cut2==n2?INT_MAX : arr2[cut2];
        

        if(left1<=right2 && left2<=right1){
            if((n1+n2)%2==0){
                return(max(left1,left2)+min(right1,right2))/2.0;
            }
            else{
                return max(left1,left2);
            }
        }
        else if(left1>right2){
            high=cut1-1;
        }
        else{
            low=cut1+1;
        }
    }
    return -1.00;
}
int main()
{
    vector<int>arr1={1,3};
    vector<int>arr2={2};
    cout<<optimal_soln(arr1,arr2);
}