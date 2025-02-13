#include<iostream>
// #include"queuelinklist.cpp"
using namespace std;


struct list // 
{
	int index;
	list *next;
};


struct Node
{
	int data;
//	int num;
	Node *next;
	list *listHead;
};

class graph
{
	protected:
		Node *head;
		Node *tail;
		int counter=0;
		int *arr;
		int count;
        
	public:
        int count1=0;
		graph();

		~graph();
		void addVertex(char info);
		void addEdge(char info1, char info2);
		void addHalfEdge(Node *temp, int info);
		void delVertex(char info);
		void delEdge(char info1, char info2);
		// void searchVertex(int info);
		// void searchEdge(int info);
		void breadthFirst();
		Node* searchingIndexInVertex(Node *temp, int info);
		int search(int info);
		void display();
        void adj_matrix();
};


graph::graph()
{
	head = NULL;
	tail = NULL;
	counter = 0;
	count = 0;
}

graph::~graph()
{
	Node *pre;
	Node *query;
	query = head;
	while(query != NULL)
	{
		pre = query;
		query = query->next;
		delete pre;
	}
	delete query;
	delete head;
}




void graph::addVertex(char info)
{
	Node *temp = new Node;
	temp->data = info;
//	temp->num = counter;
	temp->next = NULL;
	temp->listHead = NULL;

	if(head == NULL)
	{
		head = temp;
		tail = temp;
		counter += 1;
	}
	else
	{
		tail->next = temp;
		tail = temp;
		counter += 1;
	}
	
}

void graph::addEdge(char info1, char info2)
{
	
	if(head==NULL)
	{
		cout<<"graph is empty"<<endl;
	}
	else
	{
		Node *temp;
		temp = head;
		Node *temp1 = NULL;
		Node *temp2 = NULL;
		while(temp != NULL)
		{
			if (temp->data == info1)
				temp1 = temp;
			if (temp->data == info2)
				temp2 = temp;
			temp = temp->next;
		}
		if (temp1 != NULL && temp2 != NULL)
		{
			addHalfEdge(temp1, temp2->data);
			 addHalfEdge(temp2, temp1->data);
			return;	
		}
		else
		{
			cout<<"Vertex not found!"<<endl;
			return;
		}
	}
	
}

void graph::addHalfEdge(Node *temp, int info)
{
	list *t;
	if (temp->listHead == NULL)
	{
		t = new list;
		t->index = info;
		t->next = NULL;
		temp->listHead = t;
		return;
	}
	t = temp->listHead;
	while(t->next != NULL)
	{
		t = t->next;
	}
	t->next = new list;
	t->next->index = info;
	t->next->next = NULL;
}






// void graph::breadthFirst()
// {
// 	if(head==NULL)
// 	{
// 		cout<<"graph is empty"<<endl;
// 	}
// 	else
// 	{
		
// 		Node *temp;
// 		Node *temp1;
// 		temp = head;

// 		queue obj(counter);
// 		obj.eQueue(temp->num);

// 		arr = new int[counter]; 
// 		*(arr+count) = temp->num;
// 		count += 1;
		
// 		while(obj.checkSize() != counter)
// 		{
// 			int num = obj.dQueue();
// 			temp1 = searchingIndexInVertex(temp, num);
// 			// cout<<temp1->data<<endl;
// 			temp = head;
// 			list *t = temp1->listHead;	
// 			while(t != NULL)
// 			{
// 				int num = t->index;
				
// 				temp1 = searchingIndexInVertex(temp, num);
// 				temp = head;
// 				if (search(temp1->num) == 0)
// 				{	
// 					obj.eQueue(temp1->num);
// 					*(arr+count) = temp1->num;
// 					count += 1;
// 					cout<<temp1->data<<" ";
// 				}

// 				t = t->next;
// 			}
// 			cout<<endl;
// 			// cin>>num;	
// 		}
// 	}
// }

// Node* graph::searchingIndexInVertex(Node *temp, int info)
// {
// 	while(temp != NULL)
// 	{
// 		if (temp->num == info)
// 		{
// 			return temp;
// 		}
// 		temp = temp->next;
// 	} 
// }



// int graph::search(int info)
// {
// 	for (int i = 0; i <= count; i++)
// 	{
// 		if (*(arr+i) == info)
// 			return 1;
// 	}
// 	return 0;
// }


void graph::display()
{
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else
	{
		// cout<<counter<<endl;
		int i = 1;
		Node *temp;
		temp = head;
		while(temp != NULL)
		{
			cout<<i<<" : "<<temp->data<<":";
			list *t = temp->listHead;
			while(t != NULL)
			{
				cout<<t->index<<" ";
				t = t->next;
			}
			cout<<endl;
			temp = temp->next;
            count1++;
			i++;
		}
	}
}


void graph::adj_matrix()
{
    int m,n;
    m=n=0;
    int** arr = new int* [count1];
    for(int i=0 ;i<count1;i++)
    {
        arr[i] = new int [count1];
    }
	if(head==NULL)
	{
		cout<<"linklist is empty"<<endl;
	}
	else
	{
		// cout<<counter<<endl;
		int i = 1;
		Node *temp;
        Node *temp1;
		temp = head;
		while(temp != NULL)
		{
            
			cout<<i<<" : "<<temp->data<<":";
			list *t = temp->listHead;
			while(t != NULL)
			{
                temp1=head;
                while (temp1 != NULL)
                {
                
                if(t->index==temp1->data)
                {
                    arr[m][n]=1;
//                    break;
                }
//                else
//                    {
//                        arr[m][n]=0;
//                    }
                temp1 = temp1->next;
                }
                if(arr[m][n]==1)
                {
                	cout<<arr[m][n];
				}
				else
				{
					arr[m][n]=0;
					cout<<arr[m][n];
				}
				
				t = t->next;
                n++;
			}
			cout<<endl;
            m++;
			temp = temp->next;
			i++;
		}
	}
    delete[] arr;
}


int main()
{
	graph obj;
	obj.addVertex(10);
	obj.addVertex(9);
	obj.addVertex(8);
//	obj.addVertex(7);
	obj.addVertex(1);
	obj.addVertex(4);
	obj.addVertex(7);
	// obj.addVertex('8');
	// obj.addVertex('9');
     obj.addVertex(15);
	obj.addEdge(10,7);
	obj.addEdge(10,1);
	obj.addEdge(7,8);
	obj.addEdge(4,7);
	obj.addEdge(9,10);
	obj.addEdge(8,4);
	obj.addEdge(4,15);
	obj.addEdge(15,9);
//	obj.addEdge('e','b');
//	obj.addEdge('g','c');
	// obj.addEdge('6','7');
	// obj.addEdge('6','9');
	// obj.addEdge('7','5');
	// obj.addEdge('7','4');
	// obj.addEdge('7','8');
	// obj.addEdge('9','8');
	// obj.addEdge('9','7');
    // obj.addEdge('15','7');
	obj.display();
    obj.adj_matrix();
	// obj.breadthFirst();
	
	return 0;
}
