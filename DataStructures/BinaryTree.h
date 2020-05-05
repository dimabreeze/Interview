#pragma once

#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>

template<typename T>
struct BinaryTreeNode
{
	explicit BinaryTreeNode( T t ) : data( t ) {}
	T data;
	BinaryTreeNode* left = nullptr;
	BinaryTreeNode* right = nullptr;
};

/*
preorder(node)
  if (node = null) return
  visit(node)            //*
  preorder(node.left)    //<
  preorder(node.right)   //>

inorder(node)
  if (node = null) return
  inorder(node.left)     //<
  visit(node)            //*
  inorder(node.right)    //>

postorder(node)
  if (node = null) return
  postorder(node.left)   //<
  postorder(node.right)  //>
  visit(node)            //*
*/


template<typename T>
void dfs_preorder( BinaryTreeNode<T>* root, std::function<bool( BinaryTreeNode<T>* )> visit )
{
	if (!root) return;

	using Node = BinaryTreeNode<T>;
	std::stack<Node*> s;
	s.push( root );
	while (!s.empty())
	{
		auto node = s.top();
		s.pop();
		visit( node );
		if (node->right) s.push( node->right );
		if (node->left) s.push( node->left );
	}
/*
iterativePreorder(node)
  if (node = null)
	return
  s ← empty stack
  s.push(node)
  while (not s.isEmpty())
	node ← s.pop()
	visit(node)
	//правый потомок заносится первым, так что левый потомок обрабатывается первым
	if (node.right ≠ null)
	  s.push(node.right)
	if (node.left ≠ null)
	  s.push(node.left)
*/
}

template<typename T>
void dfs_inorder( BinaryTreeNode<T>* root, std::function<bool( BinaryTreeNode<T>* )> visit )
{
	if (!root) return;

	using Node = BinaryTreeNode<T>;
	std::stack<Node*> s;
	auto node = root;
	while (!s.empty() or node)
	{
		if (node)
		{
			s.push( node );
			node = node->left;
		}
		else
		{
			node = s.top();
			s.pop();
			visit( node );
			node = node->right;
		}
	}
/*
iterativeInorder(node)
  s ← empty stack
  while (not s.isEmpty() or node ≠ null)
	if (node ≠ null)
	  s.push(node)
	  node ← node.left
	else
	  node ← s.pop()
	  visit(node)
	  node ← node.right
*/
}

template<typename T>
void dfs_postorder( BinaryTreeNode<T>* root, std::function<bool( BinaryTreeNode<T>* )> visit )
{
	if (!root) return;
	using Node = BinaryTreeNode<T>;
	std::stack<Node*> s;
	Node* lastVisited = nullptr;
	auto node = root;
	while (!s.empty() or node)
	{
		if (node)
		{
			s.push( node );
			node = node->left;
		}
		else
		{
			auto peeknode = s.top();
			if (peeknode->right and lastVisited != peeknode->right)
			{
				node = peeknode->right;
			}
			else
			{
				visit( peeknode );
				lastVisited = peeknode;
				s.pop();
			}
		}
	}
/*
iterativePostorder(node)
  s ← empty stack
  lastNodeVisited ← null
  while (not s.isEmpty() or node ≠ null)
	if (node ≠ null)
	  s.push(node)
	  node ← node.left
	else
	  peekNode ← s.peek()
	  // если правый потомок существует и обход пришёл из левого потомка, двигаемся вправо
	  if (peekNode.right ≠ null and lastNodeVisited ≠ peekNode.right)
		node ← peekNode.right
	  else
		visit(peekNode)
		lastNodeVisited ← s.pop()
*/
}

template<typename T>
void bfs( BinaryTreeNode<T>* root, std::function<bool( BinaryTreeNode<T>* )> visit )
{
	if (!root) return;
	using Node = BinaryTreeNode<T>;
	std::queue<Node*> q;
/*
levelorder(root)
  q ← empty queue
  q.enqueue(root)
  while (not q.isEmpty())
	node ← q.dequeue()
	visit(node)
	if (node.left ≠ null)
	  q.enqueue(node.left)
	if (node.right ≠ null)
	  q.enqueue(node.right)
*/
	
	q.push( root );
	while (!q.empty())
	{
		auto node = q.front();
		q.pop();
		if (node->left) q.push( node->left );
		if (node->right) q.push( node->right );
		visit( node );
	}
}