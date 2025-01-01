//https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
#include<iostream>
#include<vector>
using namespace std;

int brute(vector<int>& arr, int k){
    int maxi=1;
    int sum;
    for(int i=0; i<arr.size(); i++){
        sum=0;
        for(int j=i; j<arr.size(); j++){
            sum+=arr[j];
            if (sum==k){
                if(j-i+1 > maxi) maxi = j-i+1;
            }
        }
    }
    return maxi;
}

int better(vector<int>& arr, int k){
    vector<int> hashSum;
    int maxi=1, sum=0;
    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
        if(sum==k) {if(i+1>maxi) maxi=i+1;}
        hashSum.emplace_back(sum);
        for(int j=0; j<hashSum.size();j++){
            if(arr[j]==sum-k){
                if(i-j>maxi) maxi=i-j;
            }
        }
    }
    return maxi;
}

int lenOfLongestSubarr(vector<int>& arr, int k) {
    // code here
    return brute(arr,k);
}

int main(){
    vector<int> v = {10, 5, 2, 7, 1, 9};
    int k=15;
    cout<<"length of largest subarray having sum ="<<k<<" is "<<lenOfLongestSubarr(v,k);
}