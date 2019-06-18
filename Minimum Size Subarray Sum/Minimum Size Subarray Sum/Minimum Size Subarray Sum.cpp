// Minimum Size Subarray Sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

#include <algorithm>
#include <ctype.h>
#include <cmath>
#include <string>
#include <malloc.h>
#include <vector>

using namespace std;
/*
209题目：给定一个整型数组和一个数字s,找到数组中最短的一个连续子数组，
	使得连续子数组的数字和sum>=s,返回这个最短的连续子数组的长度值，
	如：给定数组[2,3,1,2,4,3],s=7
		答案为[4,3],返回2
	
	什么叫子数组：不一定在数组中的位置是连续的。该题目中要求的为连续子数组
	思路：设置一个滑动窗口
*/

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		//时间复杂度：O（n）空间复杂度O（1）
		int l = 0, r = -1; //nums[l...r]为我们的滑动窗口
		int sum = 0;
		int res = nums.size()+1;  //满足条件的子串长度

		if (nums.empty())
		{
			return 0;
		}

		while (l < nums.size())
		{
			if (r + 1 < nums.size() && sum < s)
			{
				r++;
				sum += nums[r];
			}
			else
			{
				if (sum >= s)
				{
					res = min(res, r - l + 1);
				}

				sum -= nums[l];
				l++;
			}
		}

		if (res == nums.size()+1)
			return 0;

		return res;
	}
};


int main()
{
	int a[] = { 1,2,3,4,5 };
	int tar = 15;
	int res = 0;

	vector<int> vec(a, a + sizeof(a) / sizeof(int));

	res = Solution().minSubArrayLen(tar, vec);
	cout << res << endl;
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
