class Node{
	public:
	int data;
	Node* next;
	Node(int data): data(data){
		next=NULL;
	}
	friend class Queue;
};

template<typename T>
class Queue{
	public:
	Node<T>* head;
	Node<T>* tail;
	int currentSize;

	Queue(){
			currentSize=0;
			head=NULL;
			tail=NULL;
	}
	
	bool isEmpty() const{
		return (head==NULL)?true:false;
	}
	
	void enQueue(T data){
		if(head==NULL){
			head=new Node<T>(data);
			tail=head;
		}
		else{
			tail->next=new Node<T>(data);
			tail=tail->next;		
		}
		currentSize++;
		return;
	}
	
	T dequeue(){
		if(!head)
			return;
		T data=head->data;
		Node<T>* temp=head;
		head=head->next;
		delete temp;
		currentSize--;
		return data;
	}
	
	int getSize(){
		return currentSize;
	}
	
	T getFront(){
		if(!head)
			return;
		return head->data;
	}
	
	~Queue(){
		Node<T>* temp;
		while(head!=NULL){
			temp=head->next;
			delete head;
			head=temp;
		}
	}
};


//Implementing a stack using 2 Queues
class stack{
		public:
		Queue *q1;
		Queue *q2;
		int currentSize=0;
		
		stack(){
				q1=new Queue();
				q2=new Queue();
				currentSize=0;
		}
		
		void push(int data){
				if(q1.isEmpty() && q2.isEmpty()){
					q1.enQueue(data);
					currentSize++;
				}
				else{
					if(q1.isEmpty() && !q2.isEmpty()){
						q2.enQueue(data);
						currentSize++;
					}
					else{
						q1.enQueue(data);
						currentSize++;
					}
				}
		}
		
		int pop(){
			if(q1.isEmpty() && q2.isEmpty())
				return -1;
			if(!q1.isEmpty()){
				while(q1.getSize()>1){
					int temp=q1.dequeue();
					q2.enQueue(temp);
				}
				return q1.enQueue();				
			}
			else{
				while(q1.getSize()>1){
					int temp=q2.dequeue();
					q1.enQueue(temp);
				}
				return q2.dequeue();
			}
		
		}
};
