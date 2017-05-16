class stack{
	public:
	Node* head;
	int numNodes;
	
	stack(){
		head=NULL;
		numNodes=0;
	}
	
	int size(){
		return numNodes;
	}
	
	void push(int data){
		Node* newNode= new Node(data);
		newNode->next=head;
		head=newNode;
		numNodes++;
	}
	
	bool isEmpty(){
		if(head==NULL)
			return true;
		return false;
	}
	
	int top(){
			if(head!=NULL)
				return head->data;
			return -1;
	}
	
	int pop(){
		if(!head){
			numNodes--;
			Node* temp=head->next;
			int dataitem=head->data;
			delete head;
			head=temp;
			return dataitem;
		}
		return -1;
	}

};
