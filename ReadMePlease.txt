Welcome to DataStructure repository.

This repository consist of Customized Standard Library which include the generic implementation
of the following data structures in C++ programming language .

1: Stack
2: Queue
3: SinglyLinkedList(SLL)
4: SinglyCircularLinkedList(SCLL)
5: DoublyLinkedList(DLL)
6: DoublyCircularLinkedList(DCLL)

Note : All the header files are included in the headers folder
To use the following data structures refer the below syntax

--:-- class_name <type_name> object_name ---


Suppose if we want to create and use DoublyLinkedList which would store data of interger type
we can write syntax as

DoublyLinkedList<int> dobj;

You can refer SampleCode.cpp file for more info about files

1: Stack(LIFO)
ClassName-Stack


To include stack ADT use the header file "stack.h" in your code.
Operations:
a: push(element) -> Pushes the element on to the stack
b. pop()-> Popes the element at the top positon of stack and return it from the stack;
           function would call exit funtion in case the stack is empty.

c: peep()-> Returns the data at head position. The function would exit in case the stack is empty.
d: getSize()-> Returns the size of the stack.
3: Display()-> Displays the elements of the stack.

2:Queue(FIFO)
class_name -Queue
To include this header file use "queue.h" in your code.
Functions:

a: Enqueue(element) -> inserts the data in queue from the last position.
b: Dequeue() -> removes the data and returns it from the Queue.
c: Front()-> returns the data from  the front positon of queue.
d: Rear()-> returns the data from  the rear positon of queue

e: isEmpty()->Returns bool value (True/False) in case the queue is empty or not.
              Returns True if the queue is empty and false if queue is not empty;



3:SinglyLinkedList(SLL)

ClassName SinglyLinkedList

Use header file "SLL.h" to include in your program.
To use the SLL use the following symbol

SinglyLinkedList<int> sobj.(Creates a LinkedList which stores integer data.)

Functions:
  Inserting Logic

  InsertFirst(element)-> Inserts the data at the first position in our linked list.
  InsertLast(element)-> Inserts the data at the last position .
  InsertAtPos(element, pos)->Inserts the data at the given valid position.

  Deleting the nodes

  DeleteFirst()->Deletes the first Node(If Linked list is empty then return from function)
  DeleteLast() -> Deletes the Last Node(If Linked list is empty then return from function)
  DeleteAtPos(pos)->Deletes the node at a given valid position or else returns from the function.

  Display() -> To display the data in each nodes of our linked list
  Count->to count the number of nodes.


For remaining linked list use the same above Functions

4:SinglyCircularLinkedList(SCLL) ClassName- SinglyCircularLinkedList
5:SinglyLinkedList(SLL) ClassName->SinglyLinkedList
6:DoublyLinkedList(DLL) ClassName->DoublyLinkedList
7:DoublyCircularLinkedList(DCLL) ClassName->DoublyCircularLinkedList


In DCLL and DLL as we can also display the LinkedList in reverse form
by using function DisplayRev() in DCLL and DisplayReverse in DLL .
