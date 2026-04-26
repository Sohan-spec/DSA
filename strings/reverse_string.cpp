#include<bits/stdc++.h>
using namespace std;
void optimal_soln(vector<char>&s){
    if(s.empty())return ;
    int right=s.size()-1;
    int left=0;
    while(left<=right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
}
int main()
{
    vector<char>s={'h','e','l','l','o'};
    optimal_soln(s);
    for(char c:s){
        cout<<c;
    }
}