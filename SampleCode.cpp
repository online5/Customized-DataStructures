#include<iostream>
using namespace std;

#include "headers/stack.h"
#include "headers/Queue.h"
#include "headers/DLL.h"
#include "headers/SCLL.h"
#include "headers/SLL.h"
#include "headers/DCLL.h"

//Functions for stack
// T => Generic DataType
// void push(T data);x
// T pop();
// T peep();
// T getDataValue(int);
// int getSize();
// void Display();


//Functions for Queue.
/*
void Enqueue(T data);
T Dequeue();
T Front();
T Rear();
void Display();
bool isEmpty();*/

//Functions for SinglyLinkedList
/*
void InsertFirst(T data);
void InsertLast(T data);
void InsertAtPos(T data, int pos);
void DeleteFirst();
void DeleteLast();
void DeleteAtPos(int);
void Display();
int Count();*/

// Functions for DoublyCircularLinkedList
/*void InsertFirst(T data);
void InsertLast(T data);
void InsertAtPos(T data, int pos);
void DeleteFirst();
void DeleteLast();
void DeleteAtPos(int);
void Display();
void DisplayRev();
int Count();*/

// Functions for DoublyLinkedList
/*
void InsertFirst(T data);
void InsertLast(T data);
void InsertAtPos(T data, int pos);
void DeleteFirst();
void DeleteLast();
void DeleteAtPos(int);
void Display();
void DisplayReverse();
int Count();
*/
// Functions for SinglyCircularLinkedList
/*
void InsertFirst(T data);
void InsertLast(T data);
void InsertAtPos(T data, int pos);
void DeleteFirst();
void DeleteLast();
void DeleteAtPos(int);
void Display();
int Count();
*/

int main()
{

  Stack<char> cobj;
  Queue<char> qobj;
  DoublyLinkedList<int> dobj;
  DoublyCircularLinkedList <string> dcobj;

  dcobj.InsertLast("Deepak");
  dcobj.InsertLast("Amit");
  dcobj.InsertFirst("Amita");
  dcobj.Display();

  dobj.InsertFirst(50);
  dobj.InsertLast(70);

  dobj.Display();

  qobj.Enqueue('A');
  qobj.Enqueue('B');
  qobj.Enqueue('C');

  qobj.Display();
  return 0;
}
