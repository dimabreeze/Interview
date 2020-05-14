#pragma once

template<typename T>
struct Node {
	Node( T value ) : val( value ) {};
	T val;
	Node* next = nullptr;
};

template<typename T>
Node<T>* advance( Node<T>* head, size_t steps )
{
	while(steps--> 0 && head)
	{
		head = head->next;
	}
	return head;
}

template<typename T>
Node<T>* reverse( Node<T>* head )
{
	Node<T>* prev = nullptr;
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

template<typename T>
Node<T>* merge_two_sorted( Node<T>* head1, Node<T>* head2 )
{
	auto dummy = Node<T>{ 0 };
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


//template<typename T>
//Node<T>* merge_two_one_by_one( Node<T>* l1, Node<T>* l2 )
//{
//	if (!l1) return l2;
//	if (!l2) return l1;
//
//	auto l1 = head1, next1 = l1->next;
//	auto l2 = head2, next2 = l2->next;
//
//	Node<T> dummy{ 0 };
//	Node<T>** tail = dummy.next;
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
//		Node<T>* tmp_next = nullptr;
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

template<typename T>
Node<T>* median( Node<T>* head ) //T: O(N/2) ~ O(N), M: O(1)
{
	if (!head or !head->next) return head;

	Node<T>* slow = head;
	Node<T>* fast = head;
	while (fast and fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
