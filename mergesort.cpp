#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& v, int low, int mid, int high){
    vector<int> ans;
    int p1=low, p2=mid+1;
    while(p1<=mid && p2<=high){
        if (v[p1]<=v[p2]){
            ans.emplace_back(v[p1]);
            p1++;
        } else {
            ans.emplace_back(v[p2]);
            p2++;
        }
    }
    while(p1<=mid){
        ans.emplace_back(v[p1]);
        p1++;
    }
    while(p2<=high){
        ans.emplace_back(v[p2]);
        p2++;
    }
    for(int i=low; i<=high;i++){
        v[i] = ans[i-low];
    }
}

void msort(vector<int>& v, int low, int high){
    if(low==high) return;
    int mid = (low+high)/2;
    msort(v,low,mid);
    msort(v,mid+1,high);
    merge(v,low,mid,high);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    msort(arr,0,n-1);
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}