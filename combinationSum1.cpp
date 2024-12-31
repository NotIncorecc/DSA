//https://leetcode.com/problems/combination-sum/
#include<iostream>
#include<vector>
using namespace std;

void solve(int i, vector<int> ans, int sum, vector<int>& array, vector<vector<int>>& answers){
        if(sum==0){
            answers.emplace_back(ans);
            return;
        }
        if(sum<0 || i==array.size()) return;

        solve(i+1, ans, sum, array, answers);
        ans.emplace_back(array[i]);
        solve(i, ans, sum-array[i], array, answers);
    }
//<drivercode>
void printarr(vector<vector<int>> arr){
    for(auto it: arr){
        for(auto num: it) cout<<num<<" ";
        cout<<endl;
    }
}
/*
void takeInput(int& target, vector<int>& canditates){
    int size;
    cin>>target;
    cin>>size;
    for(int i=0; i<size;i++) cin>>canditates[i];
}*/
//</drivercode>

int main(){
    vector<vector<int>> arrayOfAns;
    vector<int> ans;
    int target=8;
    vector<int> candidates = {1,2,6,7};
    solve(0,ans,target,candidates,arrayOfAns);
    printarr(arrayOfAns);
}