#include<iostream>
using namespace std;
struct Node
{
		int data;
		Node* left;
		Node* right;
		
		Node(int dat)
		{
			this->data = dat;
			left = NULL;
			right = NULL;
		}
};
class Tree
{
	private:
		Node* root;
	public:
		//Constructor
		Tree()
		{
			this->root = NULL;
		}
		//put the data into the tree
		void push(int input)
		{
			if(root == NULL)
				root = new Node(input);
			else
			{
				Node* now = root;
				while(1)
				{
					if(now->left == NULL && now->right == NULL)
					{
						if(now->data >= input)
						{
							now->left = new Node(input);
							return;
						}
						else
						{
							now->right = new Node(input);
							return;
						}
					}
					else
					{
						if(now->data >= input)
						{
							if(now->left == NULL)
							{
								now->left = new Node(input);
								return;
							}
							else
								now = now->left;
						}
						else
						{
							if(now->right == NULL)
							{
								now->right = new Node(input);
								return;
							}
							else
								now = now->right;
						}
					}
				}
			}
		}
		void LVR(Node* V)
		{
			if(V->left == NULL && V->right == NULL)
			{
				cout << V->data << " ";
				return;
			}
			else
			{
				if(V->left != NULL)
					LVR(V->left);
				cout << V->data << " ";
				if(V->right != NULL)
					LVR(V->right);
			}
			return;
		}
		//print the data orderly
		void print()
		{
			//By the method of LVR, we print ordered numbers
			LVR(root);
			cout << endl;
		}
};

int main()
{
	int data[20] = {8,4,1,2,150,7,13,9,-1,17,10,19,20,277,5,11,16,6,12,18};
	Tree t;
	//Put the data into tree and check
	for(int i = 0; i < 20; i++)
	{
		t.push(data[i]);
		cout << "printing : " << i << endl;
		t.print();
	}
}
