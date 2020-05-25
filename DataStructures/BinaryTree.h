#pragma once

#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>

struct TreeNode {
	int val = 0;
	TreeNode* left  = nullptr;
	TreeNode* right = nullptr;
	TreeNode( int x = 0, TreeNode* left = nullptr, TreeNode* right = nullptr ) 
		: val( x )
		, left( left )
		, right( right ) 
	{}
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


void dfs_preorder( TreeNode* root )
{
	if (!root) return;

	using Node = TreeNode;
	std::stack<Node*> s;
	s.push( root );
	while (!s.empty())
	{
		auto node = s.top();
		s.pop();
		//visit( node );
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

void dfs_inorder( TreeNode* root )
{
	if (!root) return;

	std::stack<TreeNode*> s;
	auto node = root;
	while (!s.empty() or node)
	{
		while(node) //top
		{   //go left, defer top
			s.push( node );
			node = node->left;
		}

		node = s.top(); s.pop();
		//visit( node );
		node = node->right;
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

void dfs_postorder( TreeNode* root )
{
	if (!root) return;

	std::stack<TreeNode*> s;
	TreeNode* lastVisited = nullptr;
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
				//visit( peeknode );
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
void bfs( TreeNode* root )
{
	if (!root) return;

	std::queue<TreeNode*> q;
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
		//visit( node );
	}
}

TreeNode* inorderSuccessor( TreeNode* root, TreeNode* p ) {
	std::stack<TreeNode*> stack;

	TreeNode* node = root;
	TreeNode* prev = nullptr;
	while (!stack.empty() or node)
	{
		while (node) //top
		{
			stack.push( node );  //defer top
			node = node->left; //prepare left
		}

		node = stack.top(); stack.pop();

		if (prev == p)
			return node;
		prev = node;

		node = node->right;  //prepare right
	}
	return nullptr;
}