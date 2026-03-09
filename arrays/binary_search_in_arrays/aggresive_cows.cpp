#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> &arr, int cows, int mingap)
{
    int countcows = 1, last = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] - last >= mingap)
        {
            countcows += 1;
            last = arr[i];
        }
        if (countcows >= cows)
            return true;
    }
    return false;
}
int brute_force(vector<int> &arr, int cows)
{
    sort(arr.begin(), arr.end());
    int maxe = *max_element(arr.begin(), arr.end());
    int mine = *min_element(arr.begin(), arr.end());
    for (int i = 1; i <= (maxe - mine); i++)
    {
        if (ispossible(arr, cows, i))
        {
            continue;
        }
        else
        {
            return (i - 1);
        }
    }
    return -1;
}
int optimal_soln(vector<int> &arr, int cows)
{
    sort(arr.begin(), arr.end());
    int low=1;
    int high=arr.back()-arr.front();  
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (ispossible(arr, cows, mid))
        {
            low=mid+1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    vector<int>arr={5,4,3,2,1,1000000000};
    cout<<optimal_soln(arr,2);
}