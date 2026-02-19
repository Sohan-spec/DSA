#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int>&arr,int low,int high)
{
    if(low<high)
    {
        int pindex=partition(arr,low,high);
        qs(arr,low,pindex-1); //bec we gotta keep the partition one constant
        qs(arr,pindex+1,high);
    }
}
vector<int> quicksort(vector<int>&arr){
    qs(arr,0,arr.size()-1);
    return arr;
}
int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    quicksort(arr);

    cout<<"After sorting:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}