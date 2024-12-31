#include<iostream>
#include<vector>
#include<set>
using namespace std;

void printArr(vector<int> v){
    for(auto it:v) cout<<it<<" ";
}
    
vector<int> brute(vector<int>& a, vector<int>& b){
    set<int> st;
    for(auto it: a) st.emplace(it);
    for(auto it: b) st.emplace(it);
    
    vector<int> ans;
    for(auto i: st) ans.emplace_back(i);
    return ans;
}
    
vector<int> optimal(vector<int>& a, vector<int>& b){
    int p1=0,p2=0,last;
    vector<int> ans;
    while(p1<a.size() && p2<b.size()){
        if(a[p1]>=b[p2]){
            if (b[p2]!=last){
            last=b[p2];
            ans.emplace_back(b[p2]);
            }
            p2++;
        }
        else {
            if (a[p1]!=last){
            last=a[p1];
            ans.emplace_back(a[p1]);
            }
            p1++;
        }
    }
    
    while(p1<a.size()){
        if (a[p1]!=last){
            last=a[p1];
            ans.emplace_back(a[p1]);
        }
        p1++;
    }
    
    while(p2<b.size()){
        if (b[p2]!=last){
            last=b[p2];
            ans.emplace_back(b[p2]);
        }
        p2++;
    }
    
    return ans;
}

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        return optimal(a,b);
}

int main(){
    vector<int> a = {1,2,5,7,8};
    vector<int> b = {1,3,4,5,7};

    printArr(findUnion(a,b));
}