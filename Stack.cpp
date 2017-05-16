
class stack{
		public:
		int *data;
		int nextElementPosition;
		int maxSize;
		stack(){
				maxSize=1000;
				data=new int[maxSize];
				nextElementPosition=0;
		}
		
		stack(int capacity){
			maxSize=capacity;
			data=new int[capacity];
			nextElementPosition=0;
		}
		
		int size(){
				return nextElementPosition;
		}
		
		bool isEmpty(){
				if(size()==0)
					return true;
				return false;
		}
		
		int top(){
			if(isEmpty()){
				return -1;
			}
			return data[nextElementPosition-1];
		}
		
		void push(int nextElement){
				if(nextElementPosition==maxSize){
						int *temp=new int[2*maxSize];
						for(int i=0; i<maxSize; i++)
							temp[i]=data[i];
						maxSize*=2;
						delete [] data;
						data=temp;
					}
				data[nextElementPosition++]=nextElement;
		}
		
		int pop(){
				if(isEmpty())
					return -1;
				int tobeReturned=data[nextElementPosition-1];
				nextElementPosition--;
				return tobeReturned;
		}
	
		stack(const stack & s2){
				int maxSize=s2.maxSize;
				this->maxSize=maxSize;
				for(int i=0; i<maxSize; i++)
					this->data[i]=s2.data[i];
			}
	
		void insertAtBottom(stack &s, int data){
			if(s.isEmpty())
				s.push(data);
			else{
				int temp=s.pop();
				insertAtBottom(s, data);
				s.push(temp);
			}
		}
		
		void reverseStack(stack &s){
			if(!s.isEmpty()){
				int top=s.pop();
				reverseStack(s);
				insertAtBottom(s, top);
			}
		}
	
		~stack(){
			delete [] data;
			data=NULL;
		}
};
