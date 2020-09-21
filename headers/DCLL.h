

#ifndef flag_dcl

#define flag_dcl
template<class T>
class DC_Node
{
public:
  T data;
  DC_Node<T>* next;
  DC_Node<T>* prev;
};
#endif

template<class T>
class DoublyCircularLinkedList
{
  private:
    DC_Node<T>* head;
    DC_Node<T>* tail;
    int iSize;
  public:
    DoublyCircularLinkedList()
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
    void DisplayRev();
    int Count();
};

template<class T>
void DoublyCircularLinkedList<T>::DisplayRev()
{
  cout<<"Inside Display DisplayReverse"<<endl;
  DC_Node<T>* temp=tail;
  do
  {
    cout<<"["<<temp->data<<"]->";
    temp=temp->prev;
  }
  while(temp!=head->prev);
}
template<class T>
void DoublyCircularLinkedList<T>::InsertAtPos(T data, int pos)
{
  if(pos < 1 || pos > iSize+1)
  {
    printf("Error: Invalid Position.\n");
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
    cout<<"Inside else.\n";
    DC_Node<T>* newn=new DC_Node<T>;
    newn->data=data;
    newn->prev=NULL;
    newn->next=NULL;

    DC_Node<T>* temp=head;
    for(int i=1; i<pos-1; i++)
    {
      temp=temp->next;
    }
    newn->next=temp->next;
    temp->next->prev=newn;
    temp->next=newn;
    newn->prev=temp;
    iSize++;
  }

}

template<class T>
void DoublyCircularLinkedList<T>::DeleteAtPos( int pos)
{
  if(pos < 1 || pos > iSize)
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
    DC_Node<T>* temp=head;
    for(int i=1; i<pos; i++)
    {
      temp=temp->next;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    delete(temp);
    iSize--;
  }


}
template<class T>
void DoublyCircularLinkedList<T>::DeleteLast()
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
    tail=tail->prev;
    delete(tail->next);
  }
  tail->next=head;
  head->prev=tail;
  iSize--;
}

template<class T>
void DoublyCircularLinkedList<T>::DeleteFirst()
{
  if(head == NULL || tail == NULL)
  {
    return;
  }

  DC_Node<T>* temp;

  if(head == tail)
  {
    delete(head);
    head=NULL;
    tail=NULL;
  }
  else
  {
    temp=head;
    head=head->next;
    delete(temp);
  }
  head->prev=tail;
  tail->next=head;
  iSize--;
}

template<class T>
int DoublyCircularLinkedList<T>::Count()
{
  return (iSize);
}

template<class T>
void DoublyCircularLinkedList<T>::InsertLast(T data)
{
  DC_Node<T>* newn=new DC_Node<T>;
  newn->data=data;
  newn->next=NULL;
  newn->prev=NULL;

  if(head == NULL || tail == NULL)
  {
    head=newn;
    tail=newn;
  }
  else
  {
    tail->next=newn;
    newn->prev=tail;
    tail=newn;
  }
  head->prev=tail;
  tail->next=head;
  iSize++;
}


template<class T>
void DoublyCircularLinkedList<T>::InsertFirst(T data)
{
  DC_Node<T>* newn=new DC_Node<T>;
  newn->data=data;
  newn->next=NULL;
  newn->prev=NULL;

  if(head == NULL || tail == NULL)
  {
    head=newn;
    tail=newn;
  }
  else
  {
    newn->next=head;
    head->prev=newn;
    head=newn;
  }
  tail->next=head;
  head->prev=tail;
  iSize++;
}

template<class T>
void DoublyCircularLinkedList<T>::Display()
{
  if(head == NULL || tail == NULL)
  {
    return;
  }
  cout<<"Size:"<<iSize<<"\n";
  DC_Node<T>* temp=head;
  do
  {
    cout<<"["<<temp->data<<"]->";
    temp=temp->next;
  }
  while(temp!=tail->next);
  cout<<"\n";
}
