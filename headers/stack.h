#ifndef header_flag
#define header_flag

template<class T>
struct Node
{
public:
  T data;
  Node<T>* next;
};
#endif

template<class T>
class Stack
{
  private:
    Node<T>* head;
    int iSize;
  public:
    Stack()
    {
      head = NULL;
      iSize=0;
    }
    void push(T data);
    T pop();
    T peep();
    T getDataValue(int);
    int getSize();
    void Display();
};
template<class T>
int Stack<T>::getSize()
{
  return this->iSize;
}

template<class T>
T Stack<T>::peep()
{
  if(head != NULL)
  {
    return head->data;
  }
}
template<class T>
void Stack<T>::push(T data)
{
  Node<T>* newn=new Node<T>;
  newn->data=data;
  newn->next=NULL;

  if(head == NULL)
  {
    head=newn;
  }
  else
  {
    newn->next=head;
    head=newn;
  }
  iSize++;
}
template<class T>
T Stack<T>::pop()
{
  if(head == NULL)
  {
    printf("Error: Stack empty.\n");
    exit(EXIT_FAILURE);
  }

  Node<T>* temp=head;
  T data=head->data;
  head=head->next;
  iSize--;
  delete(temp);
  return data;

}



template <class T>
void Stack<T>::Display()
{
  if(iSize == 0)
  {
    printf("Stack is Empty.\n");
    return;
  }
  Node<T>* temp=head;
  while(temp!=NULL)
  {
    cout<<"["<<temp->data<<"] ->";
    temp=temp->next;
  }
  cout<<"NULL\n"<<endl;
}
