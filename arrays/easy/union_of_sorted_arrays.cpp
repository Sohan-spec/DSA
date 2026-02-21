#include <bits/stdc++.h>
using namespace std;
vector<int> using_map(vector<int> &nums1, vector<int> nums2)
{
    map<int, int> array_map;
    vector<int> temp;
    for (int i = 0; i < nums1.size(); i++)
    {
        array_map[nums1[i]] += 1;
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        array_map[nums2[i]] += 1;
    }
    for (auto it : array_map)
    {
        temp.push_back(it.first);
    }
    return temp;
}
vector<int> using_set(const vector<int> arr1, const vector<int> arr2) // this takes O((m+n)log(m+n)) as time complexity
{
    set<int> array_set;
    for (int i = 0; i < arr1.size(); i++)
    {
        array_set.emplace(arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        array_set.emplace(arr2[i]);
    }
    vector<int> temp(array_set.begin(), array_set.end());
    return temp;
}
vector<int> using_two_pointer(const vector<int> &arr1, const vector<int> &arr2) //this does it in O(m+n) time and O(m+n) for space
{
    int i = 0, j = 0;
    vector<int> temp;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            if (temp.empty() || temp.back() != arr1[i])
            {
                temp.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (temp.empty() || temp.back() != arr2[j])
            {
                temp.push_back(arr2[j]);
            }
            j++;
        }
        else
        {
            if (temp.empty() || temp.back() != arr1[i])
            {
                temp.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    while (i < arr1.size())
    {
        if (temp.empty() || temp.back() != arr1[i])
        {
            temp.push_back(arr1[i]);
        }
        i++;
    }
    while (j < arr2.size())
    {
        if (temp.empty() || temp.back() != arr2[j])
        {
            temp.push_back(arr2[j]);
        }
        j++;
    }
    return temp;
}
int main()
{
    vector<int> arr1 = {1, 3, 4, 5, 6};
    vector<int> arr2 = {2, 7, 8, 10};
    vector<int> temp = using_two_pointer(arr1, arr2);
    for (auto it : temp)
    {
        cout << it << endl;
    }
}