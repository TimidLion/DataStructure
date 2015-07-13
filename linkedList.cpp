#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    private:
        Node *head;
        int length;
    public:
        LinkedList()
        {
            head = NULL;
            length = 0;    
        }
        int pop(int n)
        {
            Node *prev = this->head;
            if(prev == NULL)
            {   cout << "Error:Index exceeds boundary" << endl;
                return 0;
            }
            if(n == 0)
            {
                head = prev->next;
                length--;
                return prev->data;
            }
            else
            {
                for(int i = 0; i < n ; i++)
                {
                    if(prev == NULL)
                    {   cout << "Error:Index exceeds boundary" << endl;
                        return 0;
                    }
                    int answer;
                    answer = (prev->next->data);
                    delete prev->next;
					prev->next = (prev->next->next);
                    length--;
					return answer;
                }
            }
        }
        void push(int val)
        {
            Node* tail = head;
            if(head == NULL)
            {   
                head = new Node(val);
                length++;
                return;
            }
            else
            {
                while(1)
                {
                    if(tail->next == NULL)
                    {
                        tail->next = new Node(val);
                        length++;
                        return;
                    }
                        tail = tail->next;
                }
            }
		}
		void print()
		{
			//print all the elements in the linked list
			Node* curr = head;
			while(curr)
			{	
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << endl;
			return;
		}
};

int main()
{
    LinkedList test;
	test.print();
    test.push(1);
	test.print();
    test.push(2);
	test.print();
    test.push(3);
 	test.print();
    test.push(4);
  	test.print();
    test.pop(1); // delete b
  	test.print();
    test.pop(1); // delete c
  	test.print();
    test.pop(0); // delete a
  	test.print();
    test.pop(0); // delete d
  	test.print();
}
