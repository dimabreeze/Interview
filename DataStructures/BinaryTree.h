#pragma once

#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>

// Forward declaration
struct TreeNode;
TreeNode* successor_BST( TreeNode* root );
TreeNode* predecessor_BST( TreeNode* root );

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


void dfs_preorder( TreeNode* root, std::function<void( TreeNode* )> visit )
{
	if (!root) return;

	std::stack<TreeNode*> s;
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

void dfs_inorder( TreeNode* root, std::function<void( TreeNode*)> visit )
{
	if (!root) return;

	std::stack<TreeNode*> stack;
	auto node = root;
	//While there are still nodes in the tree or in the stack:
	while (!stack.empty() or node)
	{
		while (node) //Go left till you can, adding nodes in stack.
		{
			stack.push( node );
			node = node->left;
		}
		//Pop out the last node.
		node = stack.top(); stack.pop();

		/////visit node/////
		visit( node );

		//Go one step right.
		node = node->right;
	}
/*
	iterativeInorder(node)
	  s ← empty stack
	  while (not s.isEmpty() or node ≠ null)
		while (node ≠ null)
		  s.push(node)
		  node ← node.left

		node ← s.pop()
		visit(node)
		node ← node.right
*/
}

void dfs_postorder( TreeNode* root, std::function<void( TreeNode* )> visit )
{
	if (!root) return;

	std::stack<TreeNode*> s;
	TreeNode* lastVisited = nullptr;
	auto node = root;

	while (!s.empty() or node)
	{
		while(node)
		{
			s.push( node );
			node = node->left;
		}

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

void bfs( TreeNode* root, std::function<void( TreeNode* )> visit)
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
		visit( node );
	}
}

void morris_inorder( TreeNode* root, std::function<void( TreeNode* )> visit )
{
	auto current = root;
	while (current)
	{
		if (!current->left)
		{
			// visit( node )
			visit( current );

			current = current->right;
		}
		else
		{
			//find the predecessor:
			auto pred = predecessor_BST( current );	
			//if right node is null then go left after establishing link from predecessor to current.
			if (!pred->right)
			{
				pred->right = current;
				current = current->left;
			}
			else //left is already visit. Go rigth after visiting current.
			{
				pred->right = nullptr;

				// visit( node )
				visit( current );
				current = current->right;
			}
		}


	}
}


TreeNode* inorderSuccessor( TreeNode* root, TreeNode* p ) {
	std::stack<TreeNode*> stack;
	TreeNode* node = root;
	TreeNode* prev = nullptr;
	//While there are still nodes in the tree or in the stack:
	while (!stack.empty() or node)
	{
		while (node) //Go left till you can, adding nodes in stack.
		{
			stack.push( node );
			node = node->left;
		}
		//Pop out the last node.
		node = stack.top(); stack.pop();
		//If its predecessor is equal to p, return that last node.
		if (prev == p)
			return node;
		//Otherwise, save that node to be the predecessor in the next turn of the loop.
		prev = node;
		//Go one step right.
		node = node->right;
	}
	//If we're here that means the successor doesn't exit. Return nullptr.
	return nullptr;
}

//In Binary Tree, successor of node is the leftmost child in node's right subtree
TreeNode* successor_BST( TreeNode* root ) {
	TreeNode* cur = root->right;
	while (cur && cur->left) {
		cur = cur->left;
	}
	return cur;
}

//In Binary Tree predecessor of node is the rightmost child in node's left subtree
TreeNode* predecessor_BST( TreeNode* root ) {
	TreeNode* cur = root->left;
	//                       | a check for Morris traversal |
	//                       |________V_____________________|
	while (cur and cur->right and cur != root)
	{
		cur = cur->right;
	}
	return cur;
}

TreeNode* searchBST( TreeNode* root, int target )
{
	if (!root or root->val == target) return root;

	if (target < root->val)
		return searchBST( root->left, target );

	return searchBST( root->right, target );
}

TreeNode* insertBST_iterative( TreeNode* root, int val ) {
	auto newnode = new TreeNode( val );
	if (!root) return newnode;

	auto node = root;
	while (node)
	{
		if (val < node->val)
		{
			if (!node->left)
			{
				node->left = newnode;
				return root;
			}
			node = node->left;
		}
		else //if (val > node->val)
		{
			if (!node->right)
			{
				node->right = newnode;
				return root;
			}
			node = node->right;
		}
	}
	return root;
}

TreeNode* insertBST_recursive( TreeNode* root, int val ) {
	if (!root) return new TreeNode( val );

	if (val < root->val)
		root->left = insertBST_recursive( root->left, val );
	else //if (val > node->val)
		root->right = insertBST_recursive( root->right, val );
	return root;
}

TreeNode* deleteNode( TreeNode* root, int target ) {
	// return null if root is null
	if (!root) return nullptr;

	// delete current node if root is the target node
	if (root->val == target)
	{
		// replace root with root->right if root->left is null
		if (!root->left)
			return root->right;
		
		// replace root with root->left if root->right is null
		if (!root->right)
			return root->left;

		// replace root with its successor if root has two children
		auto successor = successor_BST( root );
		root->val = successor->val;
		root->right = deleteNode( root->right, successor->val );
		return root;
	}

	if (target < root->val)
		// find target in left subtree if key < root->val
		root->left = deleteNode( root->left, target );
	else
		// find target in right subtree if key > root->val
		root->right = deleteNode( root->right, target );
}