//https://leetcode.com/problems/two-sum/
#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v;
    for (int i=0; i<nums.size(); i++){
        v.emplace_back(target-nums[i]);
        for(int j=0; j<i;j++){
            if(v[j]==nums[i]){
                vector<int> ans = {i,j};
                return ans;
            }
        }
    }
    return v;//just for function completeness
}
//Time is O(n^2) and space is O(n), I will provide better soln in future

int main(){
    int n,k;
    cin>>n;
    cin>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    vector<int> ans = twoSum(arr,k);
    for(int i=0; i<2; i++) cout<<ans[i]<<" ";
}