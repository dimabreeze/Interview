#pragma once

template<typename T>
struct Node {
	Node( T data ) : data( data ) {};
	T data;
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
