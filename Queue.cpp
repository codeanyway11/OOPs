class Queue{
	public:
	int* q;
	int currentSize;
	int maxSize;
	int front;
	int rear;
	
	Queue(){
			currentSize=0;
			maxSize=1000;
			front=0;
			rear=maxSize-1;
			q=new int[maxSize];
	}
	
	bool isFull() const{
			return(currentSize==maxSize)?true:false;
	}
	
	bool isEmpty() const{
		return (currentSize==0)?true:false;
	}
	
	void enQueue(int data){
		if(isFull()){
			return;
		}
		rear=(rear+1)%n;
		q[rear]=data;
		currentSize++;
	}
	
	int dequeue(){
		if(isEmpty())
			return -1;
		int data=q[front];
		front=(front+1)%maxSize;
		currentSize--;
		return data;
	}
	
	int getSize(){
		return currentSize;
	}
	
	int getFront(){
		if(isEmpty())
			return -1;
		return q[front];
	}
	
	~Queue(){
		delete [] q;
		q=NULL;
	}
};
