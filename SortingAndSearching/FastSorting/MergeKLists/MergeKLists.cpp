#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* merge(ListNode* first, ListNode* second)
{
	ListNode merged;
	ListNode* curr = &merged;

	while (first && second)
	{
		if (first->val < second->val)
		{
			curr->next = first;
			first = first->next;
		}
		else
		{
			curr->next = second;
			second = second->next;
		}
		curr = curr->next;
	}

	curr->next = first ? first : second;
	return merged.next;
}

ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right)
{
	if (left == right)
		return lists[left];

	if (left + 1 == right)
		return merge(lists[left], lists[right]);

	lists[left + 1] = merge(lists[left + 1], lists[left]);
	if (left + 1 != right - 1)
		lists[right - 1] = merge(lists[right - 1], lists[right]);

	return left + 1 == right - 1 ? mergeKLists(lists, left + 1, right) : mergeKLists(lists, left + 1, right - 1);
}

void clear(ListNode* lst)
{
	ListNode* curr = lst;
	while (lst)
	{
		lst = lst->next;
		delete curr;
		curr = lst;
	}
}

int main()
{
	// условие: https://leetcode.com/problems/merge-k-sorted-lists/description/

	ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
	ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
	ListNode* l3 = new ListNode(2, new ListNode(6));
	ListNode* l4 = new ListNode(7, new ListNode(8));
	vector<ListNode*> lists = { l1, l2, l3, l4 };

	int size = lists.size();
	ListNode* result = lists.size() == 0 ? nullptr : mergeKLists(lists, 0, size - 1);
	ListNode* curr = result;
	while (curr)
	{
		cout << curr->val << ' ';
		curr = curr->next;
	}

	clear(result);

	return 0;
}