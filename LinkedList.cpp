class Node{
	public:
	int data;
	Node* next;
	Node(int data): data(data){
		next=NULL;
	}
	friend class LinkedList;
};

class LinkedList{
	//Node* head;
	int lengthRecursiveHelper(Node* node){
		if(!node) 
			return 0;
		return 1+lengthRecursiveHelper(node->next);
	}
		
	static int findElementPositionRecursiveHelper(Node* node, int data){
			if(!node)
				return -1;
			if(node->data==data)
				return 0;
			if( findElementPositionRecursiveHelper(node->next, data)==-1)
				return -1;
			else
				return 1+ findElementPositionRecursiveHelper(node->next, data);		
	}	
		
	public:
	Node* head;
	LinkedList():head(NULL){
	}
	
	Node* midPointNode(){
		if(!head)
			return NULL;
		Node* fast=head;
		Node* slow=head;
		while(fast->next!=NULL || fast->next->next!=NULL){
			fast=fast->next->next;
			slow=slow->next;
		}
		return slow;
	}
	
	void addAtBeginning(int data){
		Node* newNode=new Node(data);
		(*newNode).next=head;
		head=newNode;
	}
	
	void print() const{
		Node* temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
			cout<<endl;
	}
	
	void deleteAtBeginning(){
		if(head==NULL)
			return;
		Node* temp=head->next;
		delete head;
		head=temp;
	}
	
	void insertAtIth(int data, int position){
		if(position==0){
			addAtBeginning(data);
			return;
		}
		int currentPosition=0;
		Node* temp=head;
		while(currentPosition<position-1){
			currentPosition++;
			temp=temp->next;
			if(temp==NULL)
				break;
		}
		Node *newNode=new Node(data);
		newNode->next=temp->next;
		temp->next=newNode;	
	}
	
	int length() const{
			int len=0;
			Node* temp=head;
			while(temp!=NULL){
				temp=temp->next;
				len++;
			}
			return len;
	}
	
	int midPointer(){
		Node* slow=head;
		Node* fast=head;
		if(!head->next)
			return head->data;
		else{
			while(fast->next!=NULL || fast->next->next!=NULL){
				slow=slow->next;
				fast=fast->next;
			}
			return slow->data;
		}	
	}
	
	LinkedList merge(LinkedList &a, LinkedList &b){
			LinkedList* output=new LinkedList;
			Node* temp1=a.head;
			Node* prev=NULL;
			Node* temp2=b.head;
			while(temp1!=NULL && temp2!=NULL){
				if(temp1->data<=temp2->data){
					if(prev==NULL)
						output->head=temp1;
					else
						prev->next=temp1;
					prev=temp1;
					temp1=temp1->next;
				}
				else{
					if(prev==NULL)
						output->head=temp2;
					else
						prev->next=temp2;
					prev=temp2;
					temp2=temp2->next;
				}
			}
				while(temp1!=NULL){
						prev->next=temp1;
						prev=temp1;
						temp1=temp1->next;
				}
				
				while(temp2!=NULL){
					prev->next=temp2;
					prev=temp2;
					temp2=temp2->next;
				}
				a.head=NULL; b.head=NULL;
			return *output;
	}
	
	LinkedList(LinkedList const &s){
			this->head=NULL;
			Node* temp=s.head;
			Node* prev=NULL;
			while(temp!=NULL){
			Node* newNode=new Node(temp->data);
			if(this->head==NULL){
				this->head=newNode;
				prev=newNode;
			}
			else{
				prev->next=newNode;
				prev=newNode;
				temp=temp->next;
			}
		}
	}

//Joining the linkedlist b at the end of the current Linked list.	
	LinkedList operator+(LinkedList const &b) const{
		LinkedList *output=new LinkedList(*this);
		Node* temp=b.head;
		int len=output->length();
		while(temp!=NULL){
			output->insertAtIth(temp->data, len);
			temp=temp->next;
			len++;
		}
		return *output;
	}
	
	int lengthRecursive(){
		return lengthRecursiveHelper(head);
	}
	
	LinkedList & operator+=(LinkedList const &b){
		if(!this->head){
			*this=b;
			return *this;
		}
		
		Node* tail=this->head;
		while(tail->next!=NULL){
			tail=tail->next;
		}
		
		Node* temp=b.head;
		while(temp!=NULL){
			Node* newNode= new Node(temp->data);
			tail->next=newNode;
			tail=newNode;
			temp=temp->next;		
		}
		return *this;
	}
	
	Node* reverse1(Node* head){
			if(!head ||!head->next)
				return head;
			Node* smallerReverse=reverse1(head->next);
			Node* temp=smallerReverse;
			while(temp->next!=NULL){
					temp=temp->next;
					temp->next=head;
					head->next=NULL;
				}
			return smallerReverse;
	}
	
	Node* reverse2(Node* head){
		if(!head ||!head->next)
			return head;
		Node* smallerReverse=reverse2(head->next);
		head->next->next=head;
		head->next=NULL;
		return smallerReverse;			
	}
	
	Node* reverse3(Node* head){
			if(!head || !head->next)
				return head;
			Node* current=head;
			Node* prev=NULL;
			while(current!=NULL){
					Node* nodeNext=current->next;
					current->next=prev;
					prev=current;
					current=nodeNext;
			}
		return prev;
	}
	
	bool isPresent(int data){
		Node* temp=head;
		while(temp!=NULL){
			if(temp->data==data)
				return true;
			temp=temp->next;
		}
		return false;
	}
	
	Node* mergeSort(Node* head){
			if(head || head->next)
				return head;
			Node* mid=midPointNode();
			Node* firstHalf=head;
			Node* secondHalf=mid->next;
			mid->next=NULL;
			//Node* sortedPart1=mergeSort(firstHalf);
			//Node* sortedPart2=mergeSort(secondHalf);
			LinkedList a,b;
			a.head=mergeSort(firstHalf);
			//LinkedList b;
			b.head=mergeSort(secondHalf);
			LinkedList sorted=merge(a, b);
			return sorted.head;
	}
	
	
	int findElementPosition(int data){
		Node* temp=head;
		int position=0;
		while(temp!=NULL){
			if(temp->data==data)
				return position;
			temp=temp->next;
			position++;
		}
		return -1;
	}
	
	int findElementPositionRecursive(int data){
		return findElementPositionRecursiveHelper(head, data);
	}
	
	int midPoint(){
		if(!head) return -1;
		Node* midNode=midPointNode();
		return midNode->data;
		
	}
	
	void bubbleSort(){
			if(!head || !head->next)
				return;
			Node* current=head;
			Node* prev=NULL;
			while(current!=NULL && current->next!=NULL){
			if(current->data >current->next->data){
				Node* nextNode=current->next;
				current->next=current->next->next;
				if(prev==NULL)
					head=nextNode;
				else
					prev->next=nextNode;
				nextNode->next=current;
				prev=nextNode;
				}
			else{
				prev=current;
				current=current->next;
				}
			}
	}
	
	~LinkedList(){
		while(head!=NULL){
			Node* temp=head->next;
			delete head;
			head=temp;
		}
	}
	
};

//This function is used to take input from the user
	Node* takeInput(){
		int temp;
		cout<<"Enter next"<<endl;
		cin>>temp;
		Node* head=NULL;
		Node* tail=NULL;
		while(temp!=-1){
			Node* newNode=new Node(temp);
			if(head==NULL){
					head=newNode;
					tail=newNode;
				}
			else{
				tail->next=newNode;
				tail=newNode;
			}
			cout<<"Enter next"<<endl;
			cin>>temp;
		}
		return head;		
	}
