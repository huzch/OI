#include<iostream>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};
typedef TreeNode Node;

bool IsComplete(Node* root)
{
	if(!root) return true;
	
	queue<Node*> q;
	q.push(root);
	bool flag = false;
	while(q.size())
	{
		Node* front = q.front();
		q.pop();
		
		if(front->left && front->right)
		{
			if(flag) return false;
			q.push(front->left);
			q.push(front->right);
		}
		else if(front->left && !front->right)
		{
			if(flag) return false;
			q.push(front->left);
			flag = true;//��ȫ������ֻ��һ���󲻿��ҿյĽ�㣬����ȫΪҶ�ӽ��
		}
		else if(!front->left && front->right)
		{
			return false;
		}
	}
	return true;
}

//#include<iostream>
//#include<stack>
//using namespace std;
//
//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//};
//typedef TreeNode Node;
//
//void PostOrder(Node* root, int x)
//{
//	stack<Node*> st;
//	Node* prev = nullptr;
//	Node* cur = root;
//	while(cur || st.size())
//	{
//		while(cur)
//		{
//			st.push(cur);
//			cur = cur->left;
//		}
//		
//		Node* top = st.top();
//		if(top->right == nullptr || top->right == prev)
//		{
//			st.pop();
//			prev = top;
//			//��ӡֵΪx������������
//			if(top->val == x)
//			{
//				while(st.size())
//				{
//					cout << st.top()->val << " ";
//					st.pop();
//				}
//				return;
//			}
//		}
//		else cur = top->right;
//	}
//}
