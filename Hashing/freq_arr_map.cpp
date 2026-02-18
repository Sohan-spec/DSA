#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter array size:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    map<int,int>array_map;
    for(int i=0;i<n;i++)
    {
        array_map[arr[i]]+=1;
    }
    int number;
    cout<<"Enter a number:";
    cin>>number;
    cout<<"Freq:"<<array_map[number]<<endl;
    auto it=max_element(array_map.begin(),array_map.end(),[](const pair<int,int>&a,const pair<int,int>&b){
        return a.second<b.second;
    });
    cout<<"max freq element: "<<it->first<<endl;
    cout<<"max freq count: "<<it->second<<endl;
    return 0;
}