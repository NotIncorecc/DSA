//https://leetcode.com/problems/single-number/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int fapp(vector<int>& arr){
    stable_sort(arr.begin(), arr.end());
    int i;
    for(i=0; i<arr.size(); i=i+2){
        if(i==0) continue;
        if(arr[i]==arr[i-1]) break;
    }
    return arr[i-2];
}

int main(){
    vector<int> v= {4,1,2,1,2};
    cout<<"Number that appears once is "<<fapp(v);
}