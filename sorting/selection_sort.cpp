#include<bits/stdc++.h>
using namespace std;
void selection_sort(vector<int>arr,int n){
 for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
    cout<<"Sorted array:\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
void bubble_sort(vector<int>arr,int n)
{
for(int i=0;i<n-1;i++)
    {
        bool swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped)break;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
void insertion_sort(vector<int>arr,int n)
{
      for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter array size:";
    cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selection_sort(arr,n);
    bubble_sort(arr,n);
    insertion_sort(arr,n);
    return 0;
}