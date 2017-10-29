//
//  CharLinkedList.cpp
//  hw2
//
//  Created by Vincent Bett on 9/22/16.
//  Functions for the Charlinked list class that
//  Stores characters using a linked list.


#include <stdio.h>
#include "CharLinkedList.h"


/*
The default constructor takes no parameters and initializes an
empty list.
*/
CharLinkedList::CharLinkedList()
{
        head = NULL;
        num_elements = 0;
}

/*
takes in a single character as a
paramter and creates a one element list consisting of
that character.
*/
CharLinkedList::CharLinkedList(char add)
{
        node *temp = new node;
        temp->data = add;
        temp->next = NULL;
        head = temp;
        num_elements = 1;

}

// Destructor
CharLinkedList::~CharLinkedList()
{
        node *temp;
        while(head != NULL)
        {
                temp = head;
                head = head->next;
                delete temp;
        }
}

/*
Name:    isEmpty
         Purpose: function that takes no parameters and returns a
         boolean value that is true if this specific 
         instance of the
         CharLinkedList class is empty and false otherwise
Inputs:  None
Outputs: A boolean value
*/
bool CharLinkedList::isEmpty()
{
        return num_elements ==0;
}

/*
Name:    clear
Purpose: function that takes no parameters and has 
         a void return type.  It makes the list 
         into an empty list.
Inputs:  None
Outputs: None
*/
void CharLinkedList::clear()
{

        node *temp;
        while(head != NULL)
        {
                temp = head;
                head = head->next;
                delete temp;
        }
        num_elements=0;
}

/*
Name:    size
Purpose: function that takes no parameters and returns an
         integer value that is the number of characters
         in the list.
Inputs:  None
Outputs: an int number of elements.
*/
int CharLinkedList::size()
{
        return num_elements;
}

/*
Name:    concatenate
Purpose: function that takes in a pointer to a second
         CharLinkedList and has a void return type. 
         It adds a copy of the list pointed to by 
         the parameter value to the end of the
         list the function was called from
Inputs:  A linked list to be concatenated.
Outputs: none.
*/

void CharLinkedList::concatenate(CharLinkedList *scndLst)
{
        int size = scndLst->size();
        for (int i = 0; i < size; i++)
        {
                insertAtBack(scndLst->elementAt(i));

        }

}

/*
Name:    first
Purpose: function that takes no parameters and returns the
         first element (char) in the list.  Throws an
         exception if the sequence is empty.
Inputs:  None
Outputs: A char
*/

char CharLinkedList::first()
{
        checkIfEmpty();
        return head->data;
}

/*
Name:    checkIfEmpty
Purpose: Checks if a list is empty and throws an error
         if it is.
Inputs:  None
Outputs: None
*/
void CharLinkedList::checkIfEmpty()
{
        if(num_elements == 0)
        {
                throw string("List is empty");
        }

}

/*
Name:    last
Purpose: function that takes no parameters and returns the last
         element (char) in the list.  Throws an exception 
         if the sequence is empty.
Inputs:  None
Outputs: A char
*/

char CharLinkedList::last()
{
        checkIfEmpty();
        node *temp = head;

        if(temp-> next == NULL)
        {
                return temp->data;
        }
        while(temp -> next != NULL and temp->next->next != NULL)
        {
                temp = temp->next;
        }
        return temp->next->data;

}

/*
Name:    elementAt
Purpose: function that takes an integer index and returns
         the element (char) in the list at that index.  
         Indices are 0-based.  Throws an exception if 
         index is out of range.
Inputs:  int index
Outputs: a char
*/

char CharLinkedList::elementAt(int indx)
{
        if(indx > num_elements)
                throw out_of_range("index out of range");
        node *temp = head;
        if (indx == 0)
        {
                return temp->data;
        }
        for (int i =  0; i < indx - 1; i++)
        {
                temp = temp->next;
        }
        return temp->next->data;

}

/*
Name:    print
Purpose: function that takes no parameters and has a void
         return type.  It prints the list of characters
         to the screen (cout).
Inputs:  None
Outputs: None
*/
void CharLinkedList::print()
{
        node *temp = head;
        cout<<"[CharSequence of size " << num_elements;
        cout<<" <<";
        while(temp != NULL)
        {
                cout<<temp->data;
                temp = temp->next;
        }
        cout<< ">>]";
}

/*
Name:    insertAtBack
Purpose: function that takes an element (char) and has a
         void return type.  It inserts the given new
         element after the end of the existing elements 
         of the list.
Inputs:  A char
Outputs: None
*/
void CharLinkedList::insertAtBack(char bck)
{


        node *insrt = new node;
        insrt->next = NULL;
        insrt->data = bck;
        if(head == NULL)
        {
                head = insrt;
        }else
        {
                node *temp = head;
                while(temp->next != NULL)
                {
                        temp = temp->next;
                }
                temp->next = insrt;
        }


        countup();

}

/*
Name:    insertAtFront
Purpose: function that takes an element (char) and has
         a void return type.  It inserts the given new 
         element in front of the existing elements of
         the list.
Inputs:  A char
Outputs: None
*/
void CharLinkedList::insertAtFront(char frnt)
{
        node *temp = new node;
        temp->data = frnt;
        temp->next = head;
        head = temp;
        countup();
}

/*
Name:    insertAt
Purpose: function that takes an element (char) and an
         integer index as parameters and has a void 
         return type.  It inserts the new element at
         the specified index and shifts the
         existing elements as necessary.  Throws an 
         exception if index is out of range, though 
         it is allowed to insert at the index after
         the last element.
Inputs:  A char and an int
Outputs:
*/
void CharLinkedList::insertAt(char insrt, int at)
{
        if(at > num_elements)
        {
                throw out_of_range("index out of range");
        }
        if(at == num_elements)
        {
                insertAtBack(insrt);
        }
        else if(at == 0)
        {
                insertAtFront(insrt);
        }
        else
        {
                 node *To_Add = new node;
                 To_Add->data = insrt;

        
                node *temp = head;
                for(int i = 0; i < at-1; i++)
                {
                temp = temp->next;
                }
                To_Add->next = temp->next;
                temp->next = To_Add;

                countup();
        }
}

/*
Name:    removeFromFront
Purpose: function that takes no parameters and has a
         void return type.  It removes the first 
         element from the list. Throws an exception 
         of the sequence is empty.
Inputs:  None
Outputs: None
*/

void CharLinkedList::removeFromFront()
{
        checkIfEmpty();
        node *temp;
        temp = head;
        head = head->next;
        delete temp;
        countdown();
}

/*
Name:    removeFromBack
Purpose: function that takes no parameters and has a
         void return type.  It removes the last 
         element from the list.  Throws an 
         exception of the sequence is empty.
Inputs:  None
Outputs: None
*/

void CharLinkedList::removeFromBack()
{
        checkIfEmpty();
        node *temp = head;

        if(temp-> next ==NULL)
        {
                delete temp;
                temp = NULL;
        }
        while(temp -> next != NULL and temp->next->next != NULL)
        {
                temp = temp->next;
        }
        delete temp -> next;
        temp -> next = NULL;
        countdown();
}

/*
Name:    removeFrom
Purpose: function that takes an integer index and has a
         void return type.  It removes the element at 
         the specified index.  Throws an exception 
         if index is out of range.
Inputs:  An int
Outputs: None.
*/
void CharLinkedList::removeFrom(int rmv)
{
        node *temp = head;
        node *To_delete;
        if(rmv == 0)
        {
                head = temp->next;
                delete temp;
        }
        for (int i = 0; i < rmv - 1; i++)
        {
                temp = temp->next;
        }
        To_delete = temp->next;
        temp->next = To_delete->next;
        delete To_delete;

        countdown();
}

/*
Name:    replace
Purpose: function that takes an element (char) and an integer
         index as parameters and has a void return type. 
         It replaces the element at the specified index with 
         the new element.  Throws an
         exception if index is out of range.
Inputs:  None
Outputs: None
*/
void CharLinkedList::replace(char rplc, int n)
{
        if(n > num_elements)
        {
                throw out_of_range("index out of range");
        }
        node *temp = head;
        if (n == 0)
        {
                temp->data = rplc;
        }
        for (int i =  0; i < n -1; i++)
        {
                temp = temp->next;
        }
        temp->next->data = rplc;
}

/*
Name:    insertInOrder
Purpose: function that takes an element (char) and
         inserts it into the list in alphabetical order. 
         When this function is called you can assume 
         that the list is correctly sorted in ascending 
         order, and it should insert the element in
         the first correct index.
Inputs:  A Char
Outputs: None
*/
void CharLinkedList::insertInOrder(char insrt)
{
        node *temp = head;
        int count = 0;
        while(temp != NULL)
        {
                if(temp->data > insrt)
                {
                        insertAt(insrt, count);
                }
                temp = temp->next;
                count++;
        }
}

/*
Name:    CountUp
Purpose: To keep track of added elements.
Inputs:  None
Outputs: None.
*/
void CharLinkedList::countup()
{
        num_elements++;
}

/*
Name:    CountDown.
Purpose: To keep track of removed elements
Inputs:  none
Outputs: None.
*/
void CharLinkedList::countdown()
{
        num_elements--;
}


