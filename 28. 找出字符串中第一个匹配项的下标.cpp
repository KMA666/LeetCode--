#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        int haystack_size=haystack.size();
        int needle_size=needle.size();
        int num=0;
        if(needle_size>haystack_size){   //needle比haystack还长，直接返回-1
            return ans;
        }
        while(ans==-1){  //当ans=-1时，继续循环
            for(int i=num;i<(num+needle_size);i++){  //从haystack的num位置开始，和needle进行对比
                if(haystack[i]==needle[i-num]) {      //如果haystack的i位置的字符和needle的i-num位置的字符相等，则继续循环
                    if(i==num+needle_size-1) {   //如果i==num+needle_size-1，则说明haystack的num位置开始，和needle进行对比，成功}
                        ans=num;
                    }
                if(haystack[i]!=needle[i-num]) {  //如果haystack的i位置的字符和needle的i-num位置的字符不相等，则跳出循环，num+1，继续从haystack的num+1位置开始，和needle进行对比
                    ans=-1;
                    break;
                }
            }
            
            if(num==haystack_size-needle_size){  //如果num已经到了haystack_size-needle_size位置，说明needle在haystack中不存在，直接返回-1
                break;
            }
            num++;  //num+1，继续从haystack的num位置开始，和needle进行对比
        }
        return ans;  
    }
}
};

int main(){
    std::string haystack="hello";
    std::string needle="ll";
    Solution sol;
    int ans=sol.strStr(haystack,needle);
    std::cout<<ans<<std::endl;
    return 0;   
    system("pause");
}