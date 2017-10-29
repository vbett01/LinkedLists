//
//  CharLinkedList.h
//  hw2
//
//  Created by Vincent Bett on 9/22/16.
// A header file for a class that stores a
// list of characters using a linked list

#ifndef CharLinkedList_h
#define CharLinkedList_h

#include <iostream>
using namespace std;
const int CAPACITY = 1;

struct node{
        char data;
        node *next;
};

class CharLinkedList
{
        public:
/*
 The default constructor takes no parameters and initializes
 an empty list.
*/
                CharLinkedList();
 /*
takes in a single character as a
paramter and creates a one element list consisting of
that character.
 */
                CharLinkedList(char add);
                // Destructor./
                ~CharLinkedList();

/*
Name:    isEmpty
Purpose: function that takes no parameters and returns a
        boolean value that is true if this specific
        instance of the
        CharLinkedList class is empty and false otherwise
Inputs:  None
Outputs: A boolean value
*/
                bool isEmpty();

/*
Name:    clear
Purpose:function that takes no parameters and has
        a void return type.  It makes the list
        into an empty list.
Inputs:  None
Outputs: None
*/
                void clear();

/*
Name:    size
Purpose: function that takes no parameters and returns an
         integer value that is the number of characters
         in the list.
Inputs:  None
Outputs: an int number of elements.
*/
                int size();

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
                void concatenate(CharLinkedList *ScndLst);

/*
Name:    first
Purpose: function that takes no parameters and returns the
         first element (char) in the list.  Throws an
         exception if the sequence is empty.
Inputs:  None
Outputs: A char
*/
                char first();
/*
Name:    last
Purpose: function that takes no parameters and returns the last
         element (char) in the list.  Throws an exception
         if the sequence is empty.
Inputs:  None
Outputs: A char
*/
                char last();

/*
Name:    elementAt
Purpose: function that takes an integer index and returns
         the element (char) in the list at that index.
         Indices are 0-based.  Throws an exception if
         index is out of range.
Inputs:  int index
Outputs: a char
*/

                char elementAt(int indx);

/*
Name:    print
Purpose: function that takes no parameters and has a void
         return type.  It prints the list of characters
         to the screen (cout).
Inputs:  None
Outputs: None
*/
                void print();

/*
Name:    insertAtBack
Purpose: function that takes an element (char) and has a
         void return type.  It inserts the given new
         element after the end of the existing elements
         of the list.
Inputs:  A char
Outputs: None
*/
                void insertAtBack(char bck);

/*
Name:    insertAtFront
Purpose: function that takes an element (char) and has
         a void return type.  It inserts the given new
         element in front of the existing elements of
         the list.
Inputs: A char
Outputs: None.
*/

                void insertAtFront(char frnt);

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
                void insertAt(char insrt, int at);

/*
Name:    removeFromFront
Purpose: function that takes no parameters and has a
         void return type.  It removes the first
         element from the list. Throws an exception
         of the sequence is empty.
Inputs:  None
Outputs: None
*/
                void removeFromFront();

/*
Name:    removeFromBack
Purpose: function that takes no parameters and has a
         void return type.  It removes the last
         element from the list.  Throws an
         exception of the sequence is empty.
Inputs:  None
Outputs: None
*/
                void removeFromBack();
/*
Name:    removeFrom
Purpose: function that takes an integer index and has a
         void return type.  It removes the element at
         the specified index.  Throws an exception
         if index is out of range.
Inputs:  An int
Outputs: None.
*/
                void removeFrom(int rmv);


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
                void replace(char rplc, int n);
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
                void insertInOrder(char insrt);

        private:

                // the head of the list
                node *head;
                // Elements in the list
                int num_elements;
                // Keep track of the added elements.
                void countup();
                // Keep track of the deleted elements.
                void countdown();
                // Check if a list is empty.
                void checkIfEmpty();



};


#endif /* CharLinkedList_h */
