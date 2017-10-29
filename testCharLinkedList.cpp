//
//  main.cpp
//  hw2
//
//  Created by Vincent Bett on 9/22/16.
//  Copyright © 2016 Vincent Bett. All rights reserved.
//

#include <iostream>
#include "CharLinkedList.h"


// Characters to use in testing the CharLinkedList
// Class.
char c1 = 'V';
char c2 = 'i';
char c3 = 'n';
char c4 = 'c';
char c5 = 'e';
char c6 = 'n';
char c7 = 't';
char c8 = 'B';
char c9 = 'e';
char c10 = 't';
char c11 = ' ';

// Declare instances of the class that will be used for testing
CharLinkedList *frstnm = new CharLinkedList();
CharLinkedList *lstnm = new CharLinkedList(c2);
CharLinkedList *Seq = new CharLinkedList();

// Declaration of testing functions.
void testForAddAtFront(CharLinkedList *Sqnc, char c );
void testForAddAtBack(CharLinkedList *Sqnc, char c);
void testForInsertAt(CharLinkedList *sqnc, char c, int n);
void testForConcatenate(CharLinkedList *Sqnc1, CharLinkedList *Sqnc2);
void testForRemoveFromBack(CharLinkedList *Sqnc);
void testForPrint(CharLinkedList *Sqnc);
void testForRemoveFromLoc(CharLinkedList *Sqnc, int at);
void testForReplace(CharLinkedList *Sqnc, char put, int at);
void testForRemoveFromFront(CharLinkedList *Sqnc);
void clearSqnc(CharLinkedList *Sqnc);
bool IfisEmpty(CharLinkedList *Sqnc);
char testForelementAt(CharLinkedList *Sqnc, int at);
void testFotInsertInOrder(CharLinkedList *Sqnc, char add);



int main() {
    
    // Test for Add at front
    testForAddAtFront(lstnm, 'd');
    testForAddAtFront(lstnm, 'b');
    testForAddAtFront(lstnm, 'a');
    
    // Test for inserting in order.
    testFotInsertInOrder(lstnm, 'c');
    testForPrint(lstnm); // test for print.
    
    // Add at front
    testForAddAtFront(frstnm, c2);
    testForPrint(frstnm);// Print after adding.
    testForAddAtFront(frstnm, c1);
    
    testForPrint(frstnm);
    
    // Add at back
    testForAddAtBack(frstnm, c6);
    testForPrint(frstnm);// Print
    // Insert at a given location
    testForInsertAt(frstnm, c10, 2);
    testForPrint(frstnm);// Print.
    
    // test for concatenate.
    testForConcatenate(frstnm, lstnm);
    testForPrint(frstnm);
    
    // Remove from back
    testForRemoveFromBack(frstnm);
    testForPrint(frstnm);
    
    // Replace
    testForReplace(frstnm, c8, 3);
    testForPrint(frstnm);
    
    // Remove from a particular location
    testForRemoveFromLoc(frstnm, 2);
    testForPrint(frstnm);
    
    // Return the element at a particular location.
   char bett =  testForelementAt(frstnm, 1);
    cout<<bett<<endl;
    
    // Test for the overloaded constructor.
    cout<<"overloaded"<<endl;
    testForPrint(lstnm);
    
    //Get the first element of the list.
    cout<<"first char "<<frstnm->first()<<endl;
    
    // Get the last element of the list.
    cout<<"last Char"<<frstnm->last()<<endl;
    
    // Get the size of the list
    cout<<frstnm->size()<<endl;
    
    // Delete everything in the list.
    frstnm->clear();
    testForPrint(frstnm);
    
    
    return 0;
}


/*
 Function: TestForAddAtFront.
 Arguments: A CharLinkedList Class, A Character.
 Tests if the class can correctly add a character up front.
 Return Value: None, It's a void function.
 */
void testForAddAtFront(CharLinkedList *Sqnc, char  add )
{
    Sqnc->insertAtFront(add);
}

/*
 Function: testForAddAtBack.
 Arguments: A CharLinkedList Class, A Character.
 Tests if the class can correctly add a character at the
 back.
 Return Value: None, It's a void function.
 */

void testForAddAtBack(CharLinkedList *Sqnc, char c)
{
    Sqnc->insertAtBack(c);
}

/*
 Function: testForInsertAt
 Arguments: A CharLinkedList Class, A Character, an integer.
 Tests if the class can correctly add a character at a
 specified location.
 Return Value: None, It's a void function.
 */
void testForInsertAt(CharLinkedList *sqnc, char c, int n)
{
    sqnc->insertAt(c, n);
}

/*
 Function:testForConcatenate
 Argumnets: 2 CharLinkedLists.
 tests if the class can add a second character list onto
 another to make a long one.
 Return Value: None.
 */
void testForConcatenate(CharLinkedList *Sqnc1, CharLinkedList *Sqnc2)
{
    Sqnc1->concatenate(Sqnc2);
}

/*
 Function: testForPrint
 Arguments: A Charalist.
 Purpose: Tests if the class can print the list correctly.
 Return value: None.
 */
void testForPrint(CharLinkedList *Sqnc)
{
    Sqnc->print();
}

/*
 Function: testForRemoveFromBack
 Arguments: A CharLinkedList.
 Purpose: tests if the class can correctly remove a
 character from the back of the list.
 Return value: None.
 */
void testForRemoveFromBack(CharLinkedList *Sqnc)
{
    Sqnc->removeFromBack();
}

/*
 Function: testForRemoveFromLoc
 Arguments: A CharLinkedList, An int.
 Purpose: test is the class can correctly remove an elements from
 a specified location.
 */
void testForRemoveFromLoc(CharLinkedList *Sqnc, int at)
{
    Sqnc->removeFrom(at);
}

/*
 Function: testForReplace
 Arguments: A chaelist, a char, an int.
 Purpose: Test if the class can correctly replace an element at a
 specified location.
 */
void testForReplace(CharLinkedList *Sqnc, char put, int at)
{
    Sqnc->replace(put, at);
}

/*
 Function: testForRemoveFromFront
 Arguments: A CharLinkedList
 Purpose: To test if the class can correctly remove from  the front.
 */
void testForRemoveFromFront(CharLinkedList *Sqnc)
{
    Sqnc->removeFromFront();
}

/*
 Function: clearSqnc
 Arguments: A CharLinkedList.
 Purpose: Test if the class can correctly clear a list.
 */
void clearSqnc(CharLinkedList *Sqnc)
{
    Sqnc->clear();
}

/*
 Function IFisempty
 Arguments: A CharLinkedList
 Returns true if a list is empty.
 */

bool IfisEmpty(CharLinkedList *Sqnc)
{
    return Sqnc->isEmpty();
}

/*
 Function: testForelementAt
 Arguments: A list and an int
 Returns the element at a particular location
*/
char testForelementAt(CharLinkedList *Sqnc, int at)
{
    return Sqnc->elementAt(at);
}
/*
 Function: testFotInsertInOrder
 Arguments: a list of chars and a char
 inserts the elements alphabetically.
*/
void testFotInsertInOrder(CharLinkedList *Sqnc, char add)
{
    Sqnc->insertInOrder(add);
}
