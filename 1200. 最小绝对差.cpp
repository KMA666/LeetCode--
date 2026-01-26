#include <iostream>
#include <vector>
#include <algorithm> // 包含sort函数
using namespace std;


class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> arr_2;
        long long minm=100000;
        // if(arr.size()==2){
        //     cout<<"[["<<arr[0]<<","<<arr[1]<<"]]"<<endl;
        //     return arr_2;
        // }
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]<minm){
                minm=arr[i+1]-arr[i];
            }
        }
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==minm){
                vector<int> temp={arr[i],arr[i+1]};
                arr_2.push_back(temp);
            }
        }
        //print module
        // cout<<"[";
        // for(int i=0;i<arr_2.size();i++){
        //     cout<<"[";
        //     for(int j=0;j<arr_2[i].size()-1;j++){
        //         cout<<arr_2[i][j]<<","<<arr_2[i][j+1]<<"]";
        //     }
        //     if(i==arr_2.size()-1){
        //         break;
        //     }
        //     cout<<",";
        // }
        // cout<<"]";
        return arr_2;
    }
};

int main() {
    Solution sol;
    // 测试用例1：普通情况
    vector<int> arr1 = {4, 2, 1, 3};
    sol.minimumAbsDifference(arr1); // 输出 [[1,2],[2,3],[3,4]]
    
    // 测试用例2：仅两个元素
    vector<int> arr2 = {10, 20};
    sol.minimumAbsDifference(arr2); // 输出 [[10,20]]
    
    // 测试用例3：多个最小差值
    vector<int> arr3 = {1, 3, 6, 10, 15};
    sol.minimumAbsDifference(arr3); // 输出 [[1,3]]
    
    return 0;
}