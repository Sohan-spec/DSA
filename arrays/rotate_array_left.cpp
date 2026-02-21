#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &arr)
{
    if (arr.empty())
        return;
    int temp = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            temp = arr[i];
        }
        else
        {
            arr[i - 1] = arr[i];
        }
    }
    arr[arr.size() - 1] = temp;
}
void reverse_and_rotate(vector<int>&arr,int k){ //broke my head to write this lmao
    if(arr.size()<=0)return;
    k=k%arr.size();
    int end=arr.size()-1;
    for(int i=0;i<arr.size();i++)
    {
        if(i>end)break;
        swap(arr[i],arr[end]);
        end=end-1;
    }
    end=k-1;
    for(int i=0;i<k;i++){
        if(i>end)break;
        swap(arr[i],arr[end]);
        end=end-1;
    }
    end=arr.size()-1;
    for(int i=k;i<arr.size();i++)
    {
        if(i>end)break;
        swap(arr[i],arr[end]);
        end=end-1;
    }
}
void easier_than_mine(vector<int>&arr,int k)
{
    k=k%arr.size();
    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5,6,7};
    reverse_and_rotate(arr,3);
    // easier_than_mine(arr,3);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}