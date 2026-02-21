#include <bits/stdc++.h>
using namespace std;
bool check_sorted(const vector<int> &arr,bool asc=true)
{
    for (int i = 0; i < arr.size()-1; i++)
    {
        if(asc)
        {
            if(arr[i]>arr[i+1])
            {
                return false;
            }
        }
        else{
            if(arr[i]<arr[i+1]){
                return false;
            }
        }
    }
    return true;
}
bool check_for_possible_sorted(const vector<int>&arr){
    int count=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>arr[(i+1)%arr.size()]){
            count++;
        }
    }
    return count<=1;

}
int main()
{
    vector<int>arr={3,4,5,1,2};
    cout<<boolalpha<<check_sorted(arr,true)<<endl;
    cout<<boolalpha<<check_for_possible_sorted(arr);
    return 0;
}