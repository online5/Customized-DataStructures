

#ifndef flag_sll

#define flag_sll
template<class T>
class SL_Node
{
public:
  T data;
  SL_Node<T>* next;
};
#endif


template<class T>
class SinglyLinkedList
{
  private:
    SL_Node<T>* head;
    SL_Node<T>* tail;
    int iSize;
  public:
    SinglyLinkedList()
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
int SinglyLinkedList<T>::Count()
{
  return this->iSize;

}
template<class T>
void SinglyLinkedList<T>::DeleteLast()
{
  if(head == NULL || tail == NULL)
  {
    return;
  }
  else if(head == tail)
  {
    free(head);
    head=NULL;
    tail=NULL;
  }
  else
  {
    SL_Node<T>* temp=head;
    while(temp->next!=tail)
    {
      temp=temp->next;
    }
    free(tail);
    tail=temp;
    temp->next=NULL;
  }
  iSize--;
}

template<class T>
void SinglyLinkedList<T>::DeleteFirst()
{
  if(head == NULL || tail == NULL)
  {
    return;
  }
  else if(head == tail)
  {
    delete(head);
    head=NULL;
    tail=NULL;
  }
  else
  {
    SL_Node<T>* temp=head;
    delete(temp);
    head=head->next;
  }
  iSize--;
}

template<class T>
void SinglyLinkedList<T>::DeleteAtPos(int pos)
{
  if(pos<1 || pos>iSize)
  {
    printf("Error: Invalid Position.\n");
    return;
  }

  SL_Node<T>* temp=head;


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
    SL_Node<T>* temp=head, *prev;
    for(int i=1; i<pos-1; i++)
    {
      temp=temp->next;
    }
    prev=temp->next;
    temp->next=temp->next->next;
    delete(prev);

  }
  iSize--;
}

template<class T>
void SinglyLinkedList<T>::InsertAtPos(T data, int pos)
{
  if(pos < 1 || pos > iSize+1)
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
    SL_Node<T>* newn=new SL_Node<T>;
    newn->data=data;
    newn->next=NULL;
    SL_Node<T>* temp=head;

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
void SinglyLinkedList<T>::InsertLast(T data)
{
  SL_Node<T>* newn=new SL_Node<T>;
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
void SinglyLinkedList<T>::InsertFirst(T data)
{
  SL_Node<T>* newn=new SL_Node<T>;
  newn->data=data;
  newn->next=NULL;


  if(head == NULL)
  {
    head=newn;
    tail=newn;
  }
  else
  {
    newn->next=head;
    head=newn;
  }
  iSize++;
}
template<class T>
void SinglyLinkedList<T>::Display()
{
  if(head == NULL || tail == NULL)
  {
    return;
  }
  SL_Node<T>* temp=head;
  while(temp != NULL)
  {
    cout<<"["<<temp->data<<"]-> ";
    temp=temp->next;
  }
  cout<<"NULL\n";
}
