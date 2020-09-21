

#ifndef flag
#define flag

template<class T>
struct SC_Node
{
public:
  T data;
  SC_Node<T>* next;
};
#endif



template<class T>
class SinglyCircularLinkedList
{
  private:
    SC_Node<T>* head;
    SC_Node<T>* tail;
    int iSize;
  public:
    SinglyCircularLinkedList()
    {
      head = NULL;
      tail = NULL;
      iSize=0;
    }
    void InsertFirst(T data);
    void InsertLast(T data);
    void InsertAtPos(T data, int pos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};
template<class T>
void SinglyCircularLinkedList<T>::DeleteFirst()
{
  if(head == NULL || tail == NULL)
  {
    return;
  }
  if(head == tail)
  {
    delete(head);
    head=NULL;
    tail=NULL;
  }
  else
  {
    SC_Node<T>* del=head;
    head=head->next;
    delete(del);
    tail->next=head;
  }
  iSize--;

}
template<class T>
void SinglyCircularLinkedList<T>::DeleteLast()
{
  if(head == NULL || tail == NULL)
  {
    return;
  }

  cout<<head<<" "<<tail<<"\n";
  if(head == tail)
  {
    delete(head);
    head=NULL;
    tail=NULL;
  }
  else
  {
    SC_Node<T>* temp=head;
    while(temp->next!=tail)
    {
      temp=temp->next;
    }
    tail=temp;
    delete(temp->next);
    tail->next=head;
  }
  iSize--;
}

template<class T>
void SinglyCircularLinkedList<T>::DeleteAtPos(int pos)
{
  if(pos < 1 || pos>iSize)
  {
    return;
  }
  if(pos == 1)
  {
    DeleteFirst();
  }
  else if(pos == iSize)
  {
    DeleteLast();
  }
  else
  {
    SC_Node<T>* temp=head,*temp1;
    int i=0;
    for(i=1; i<pos-1; i++)
    {
      temp=temp->next;
    }
    temp1=temp->next;
    temp->next=temp->next->next;
    delete(temp1);
  }
  iSize--;
}

template<class T>
void SinglyCircularLinkedList<T>::Display()
{
  if(head == NULL || tail == NULL)
  {
    return;
  }

  SC_Node<T>* temp=head;
  do
  {
    cout<<"["<<temp->data<<"]->";
    temp=temp->next;
  }
  while(temp!=tail->next);
  cout<<"\n";

}

template<class T>
void SinglyCircularLinkedList<T>::InsertFirst(T data)
{
  SC_Node<T>* newn=new SC_Node<T>;
  newn->data=data;
  newn->next=NULL;

  if(head == NULL || tail == NULL)
  {
    head=newn;
    tail=newn;
  }
  else
  {
    newn->next=head;
    head=newn;
  }
  tail->next=head;
  iSize++;
}

template<class T>
void SinglyCircularLinkedList<T>::InsertLast(T data)
{
  SC_Node<T>* newn=new SC_Node<T>;
  newn->data=data;
  newn->next=NULL;

  if(head == NULL || tail == NULL)
  {
    head=newn;
    tail=newn;
  }
  else
  {
    tail->next=newn;
    tail=newn;
  }
  tail->next=head;
  iSize++;
}

template<class T>
void SinglyCircularLinkedList<T>::InsertAtPos(T data, int pos)
{
  if(pos < 1|| pos>iSize+1)
  {
    return;
  }
  if(pos == 1)
  {
    InsertFirst(data);
  }
  else if(pos == iSize+1)
  {
    InsertLast(data);
  }
  else
  {
    SC_Node<T>* newn=new SC_Node<T>;
    newn->data=data;
    newn->next=NULL;
    SC_Node<T>* temp=head;
    for(int i=1; i<pos-1; i++)
    {
      temp=temp->next;
    }
    newn->next=temp->next;
    temp->next=newn;
  }
  iSize++;
}
template<class T>
int SinglyCircularLinkedList<T>::Count()
{
  return this->iSize;
}
