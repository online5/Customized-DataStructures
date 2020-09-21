
#define header_flag
#ifndef header_flag // This will test if the header_flag is defined or not
                    //It yields true if the flag is not defined and includes the
                    // the code until endif statement is encountered.
template<class T>
struct Node
{
public:
  T data;
  Node<T>* next;
};

#endif

template<class T>
class Queue
{
  private:
    Node<T>* head;
    Node<T>* tail;
    int iSize;
  public:
    Queue()
    {
      head = NULL;
      tail = NULL;
      iSize=0;
    }
    void Enqueue(T data);
    T Dequeue();
    T Front();
    T Rear();
    void Display();
    bool isEmpty();
};

template<class T>
bool Queue<T>::isEmpty()
{
  if(iSize == 0 || head == NULL || tail == NULL)
  {
    return true;
  }
  return false;
}

template<class T>
T Queue<T>::Front()
{
  if(head == NULL || tail == NULL)
  {
    printf("Error: Queue empty.");
    exit(EXIT_FAILURE);
  }
  return (head->data);
}

template<class T>
T Queue<T>::Rear()
{
  if(head == NULL || tail == NULL)
  {
    printf("Error: Queue empty.");
    exit(EXIT_FAILURE);
  }
  return (tail->data);
}

template<class T>
void Queue<T>::Enqueue(T data)
{
  Node<T>* newn=new Node<T>;
  newn->data=data;
  newn->next=NULL;


  if(head == NULL)
  {
    head=newn;
    tail=newn;
  }
  else
  {
    tail->next=newn;
    tail=newn;

  }
  iSize++;
}
template<class T>
void Queue<T>::Display()
{
  if(head == NULL && tail == NULL )
  {
    printf("Queue: Empty.\n");
    exit(0);
  }
  else
  {
    Node<T>* temp=head;
    while(temp != NULL)
    {
      cout<<"["<<temp->data<<"]->";
      temp=temp->next;
    }
    cout<<"NULL\n";
  }
}
template<class T>
T Queue<T>::Dequeue()
{
  if(head == NULL || tail ==NULL)
  {
    cout<<"Error: Queue empty.\n";
    exit(EXIT_FAILURE);
  }
}
/*
int main()
{
  Queue<int> obj;
  Queue<string> sobj;
  sobj.Enqueue("Deepak");
  sobj.Enqueue("Amit");
  sobj.Enqueue("Rohit");
  sobj.Enqueue("Amit");
  sobj.Enqueue("Qiut");

  sobj.Display();
  cout<<sobj.isEmpty();
  cout<<sobj.Front()<<"\n";
  cout<<sobj.Rear()<<"\n";
  return 0;
}
*/
