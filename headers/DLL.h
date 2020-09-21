#ifndef header_dll
#define header_dll

template<class T>
struct D_NODE
{
  T data;
  D_NODE<T>* next;
  D_NODE<T>* prev;
};
#endif

template<class T>
class DoublyLinkedList
{
  private:
    D_NODE<T>* head;
    D_NODE<T>* tail;
    int iSize;
  public:
    DoublyLinkedList()
    {
      head = NULL;
      tail=NULL;
      iSize=0;
    }
    void InsertFirst(T data);
    void InsertLast(T data);
    void InsertAtPos(T data, int pos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    void DisplayReverse();
    int Count();
};
template<class T>
void DoublyLinkedList<T>::DisplayReverse()
{
  if(head == NULL || tail == NULL)
  {
    printf("Error: DisplayReverse Not possible.\n");
    return;
  }
  D_NODE<T>* temp=tail;
  while(temp != NULL)
  {
    cout<<"["<<temp->data<<"]->";
    temp=temp->prev;
  }
  cout<<"NULL\n";

}
template<class T>
void DoublyLinkedList<T>::DeleteAtPos(int pos)
{
  if(pos<1 || pos>iSize)
  {
    printf("Error: Invalid Position.\n");
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
    D_NODE<T>* temp=head;
    for(int i=1; i<pos; i++)
    {
      temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete(temp);

  }


}

template<class T>
void DoublyLinkedList<T>::DeleteFirst()
{
  if(head == NULL || tail ==NULL)
  {
    return;
  }
  if(head == tail)
  {
    free(head);
    head=NULL;
    tail=NULL;
  }
  else
  {
    D_NODE<T>* temp=head;
    head=head->next;
    head->prev=NULL;
    delete(temp);
  }
  iSize--;
}
template<class T>
void DoublyLinkedList<T>::DeleteLast()
{
  if(head == NULL || tail == NULL)
  {
    printf("Error : Linked is empty.\n");
    return;
  }
  if(head == tail)
  {
    free(head);
    head=NULL;
    tail=NULL;
  }
  else
  {
    D_NODE<T>* temp=head;
    while(temp->next != tail)
    {
      temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;
    tail=temp;
  }
  iSize--;

}

template<class T>
int DoublyLinkedList<T>::Count()
{
  return this->iSize;
}
template<class T>
void DoublyLinkedList<T>::Display()
{
  if(head == NULL || tail == NULL)
  {
    return;
  }
  D_NODE<T>* temp=head;
  while(temp != NULL)
  {
    cout<<"["<<temp->data<<"]->";
    temp=temp->next;
  }
  cout<<"NULL\n";

}
template<class T>
void DoublyLinkedList<T>::InsertAtPos(T data, int pos)
{
  if(pos < 1|| pos>iSize+1)
  {
    printf("Error: Invalid Position.\n");
    return;
  }
  if(pos == 1)
  {
    InsertFirst(data);
  }
  else if(pos == iSize)
  {
    InsertLast(data);
  }
  else
  {
    D_NODE<T>* newn=new D_NODE<T>;
    newn->data=data;
    newn->next=NULL;
    newn->prev=NULL;
    D_NODE<T>* temp=head;
    D_NODE<T>* temp1;
    for(int i=0; i<pos-2; i++)
    {
      temp=temp->next;
    }
    newn->next=temp->next;
    temp->next->prev=newn;
    temp->next=newn;
    newn->prev=temp;
  }
  iSize++;
}
template<class T>
void DoublyLinkedList<T>::InsertFirst(T data)
{
  D_NODE<T>* newn=new D_NODE<T>;
  newn->data=data;
  newn->next=NULL;
  newn->prev=NULL;

  if(head == NULL)
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
  iSize++;
}
template<class T>
void DoublyLinkedList<T>::InsertLast(T data)
{
  D_NODE<T>* newn=new D_NODE<T>;
  newn->data=data;
  newn->next=NULL;
  newn->prev=NULL;

  if(head == NULL)
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
  iSize++;
}
