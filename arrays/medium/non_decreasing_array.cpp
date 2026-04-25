#include<bits/stdc++.h>
using namespace std;
bool optimal_soln(vector<int>arr){
    if(arr.empty())return true;
    if(arr.size()==1)return true;
    int n=arr.size();
    int count=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            count++;
            if(count>1)return false;

            if(i==0 || arr[i-1]<=arr[i+1]){
                arr[i]=arr[i+1];
            }
            else{
                arr[i+1]=arr[i];
            }
        }
    }
    return true;
}
int main()
{
    vector<int>arr={4,2,3};
    cout<<boolalpha<<optimal_soln(arr);
}