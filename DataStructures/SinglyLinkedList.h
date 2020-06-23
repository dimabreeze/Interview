#pragma once


struct ListNode {
	ListNode() {};
	ListNode( int value ) : val( value ) {};
	int val = 0;
	ListNode* next = nullptr;
};


ListNode* advance( ListNode* head, size_t steps )
{
	while(steps--> 0 && head)
	{
		head = head->next;
	}
	return head;
}


ListNode* reverse( ListNode* head )
{
	if (!head or !head->next) return head;

	ListNode* prev = nullptr;
	auto node = head;
	while (node)
	{
		auto next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	return prev;
}

ListNode* reverse_recursive( ListNode* head ) {
	if (!head) return head;
	if (!head->next) return head;

	ListNode* newhead = reverse_recursive( head->next );
	head->next->next = head;
	head->next = nullptr;

	return newhead;
}

ListNode* reverse_range( ListNode* begin, ListNode* end = nullptr )
{
	if (!begin or !begin->next) return begin;

	ListNode* prev = nullptr;
	auto node = begin;
	while (node and node != end)
	{
		auto next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	begin->next = end;
	return prev;
}



ListNode* merge_two_sorted( ListNode* head1, ListNode* head2 )
{
	ListNode dummy;
	auto prev = &dummy;

	auto l1 = head1;
	auto l2 = head2;
	while (l1 and l2)
	{
		if (l1->val < l2->val)
		{
			prev->next = l1;
			l1 = l1->next;
		}
		else
		{
			prev->next = l2;
			l2 = l2->next;
		}
		prev = prev->next;
	}

	if (!l1) prev->next = l2;
	else if (!l2) prev->next = l1;

	return dummy.next;
}


//
//Node* merge_two_one_by_one( Node* l1, Node* l2 )
//{
//	if (!l1) return l2;
//	if (!l2) return l1;
//
//	auto l1 = head1, next1 = l1->next;
//	auto l2 = head2, next2 = l2->next;
//
//	Node<int> dummy{ 0 };
//	Node** tail = dummy.next;
///*
//	a0>a1>a2>a3>null
//	   ^ n=a2
//
//	b0>b1>b2>null
//	^ n=b1
//
//D>  a0>a1>a2>a3>null
//       ^__tail
//
//*/
//	while (l1 and l2)
//	{
//		Node* tmp_next = nullptr;
//
//		*tail = l1; //dummy->next = l1>...
//		tmp_next = l1->next;
//		*tail = l1->next;
//		l1->next = l2;
//		l1 = tmp_next;
//
//
//		*tail = l2; //dummy->next = l2>...
//		tmp_next = l2->next;
//		*tail = l2->next;
//		l2->next = l1;
//		l2 = tmp_next;
//	}
//
//	if (!l1) *tail = l2;
//	else *tail = l1;
//
//	return dummy.next;
///*
//   |
//a0>a1>a3>a4
//b0>b1>b3>b4
//   |
//
//a0
//
//dummy > a1>b0>b1
//               ^__ tail
//
//*/
//
//	return head1;
//}


ListNode* median( ListNode* head ) //int: O(N/2) ~ O(N), M: O(1)
{
	if (!head or !head->next) return head;

	ListNode* slow = head;
	ListNode* fast = head;
	while (fast and fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
