/**
给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

1、哈希表
2、快慢指针
*/

#include <iostream>
#include <unordered_map>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return false;
		}

		std::unordered_map<ListNode*, int> unMap;

		int pos = -1;
		ListNode* cur = head;
		while (cur != NULL)
		{
			if(unMap[cur]){
				return true;
			}
			unMap[cur] = 1;
			cur = cur->next;
		}
		return false;
    }

	bool hasCycle_1(ListNode *head) {
		if (head == NULL || head->next == NULL)
		{
			return false;
		}


		ListNode* fast = head, *slot = head;

		while (fast != NULL)
		{
			if(!fast->next) return false;
			slot = slot->next;
			fast = fast->next->next;
			if (slot == fast) return true;
		}
		return false;
	}
};