#include <vector>
#include <cstddef>
#include <iostream>
using namespace std;
namespace CPP_adventures {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}

	};
	class Solution {
	public:
		void callMethod();
		ListNode* sortList(ListNode* head);
		ListNode* divideAndConquer(ListNode* head);
		ListNode* MergeList(ListNode* head, ListNode* mid);
		ListNode* findMid(ListNode* head);
		int findPeakElement(vector<int>& nums);
		int peakElement(vector<int>& nums, int low, int high, int n);
		//kadanes algorthim
		int maxSumSubArray(vector<int>& nums);
	};
}