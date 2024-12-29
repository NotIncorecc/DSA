#include<iostream>
#include<vector>
using namespace std;

void subArrs(int i,vector<int> arr,vector<int> v){
    if(i==v.size()){
        for(int j=0; j<arr.size(); j++) cout<<arr[j]<<" ";
        cout<<endl;
        return;
    }
    subArrs(i+1, arr, v);
    arr.push_back(v[i]);
    subArrs(i+1, arr, v);
}

int main(){
    int n; 
    cin>>n;//not used
    vector<int> vec = {5,3,2,10};
    vector<int> subarr;
    subArrs(0,subarr,vec);
}