#include <bits/stdc++.h>
using namespace std;
vector<int> optimal_soln(vector<int> &arr)
{
    vector<int>temp;
    int count1 = 0, count2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele1)
        {
            count1++;
        }
        
        else if (arr[i] == ele2)
        {
            count2++;
        }
        else if (count1 == 0)
        {
            ele1 = arr[i];
            count1=1;
        }
        else if (count2 == 0)
        {
            ele2 = arr[i];
            count2=1;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1=0,count2=0;
    for(int i=0;i<arr.size();i++){
        if(ele1==arr[i])count1++;
        if(ele2==arr[i])count2++;
    }
    if(ele1==ele2){
        temp.emplace_back(ele1);
        return temp;
    }
    if(count1>arr.size()/3)temp.emplace_back(ele1);
    if(count2>arr.size()/3)temp.emplace_back(ele2);
    return temp;
}
int main(){
    vector<int>arr={2,2,2,3,3,3,3,3,3,5,5,5,5,5};
    vector<int>temp=optimal_soln(arr);
    for(auto it:temp){
        cout<<it<<" ";
    }
}