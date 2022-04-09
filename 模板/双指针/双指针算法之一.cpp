#include<iostream>
// https://www.acwing.com/problem/content/801/
using namespace std;
const int N=100010;
int a[N],b[N];//a[N]存储n个整数
//b[N]存储每个整数出现的次数
/*
  Eg:5
     1 2 2 3 5
     ↓
     b[1]=1;
     b[2]=2;
     b[3]=1;
     b[5]=5;
     对应的就是b[a[0]]=1....b[a[4]]=5
*/
int main()
{
    int n;
    cin>>n;
    int maxl=1;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0,j=0;i<n;i++)
    {
        //i为右指针,j为左指针
        b[a[i]]++;//记录a[i]在[i,j]间出现的次数
        while(b[a[i]]>1)//当a[i]在[i,j]间出现的次数>1时,说明有元素重复了
            //左指针j开始移动,当移动到重复的元素时,重复的元素的出现次数就<1了
            //循环结束,这时[i,j]区间的元素恢复无重复元素状态
            b[a[j++]]--;
        //最长的不包含重复数字的连续子序列的长度
        //i-j+1就是[i,j]无重复元素区间的长度
        maxl=max(maxl,i-j+1);//比较当前[i,j]无重复元素的长度与之前的maxl值,取最大
    }
    cout<<maxl;
    return 0;
}
