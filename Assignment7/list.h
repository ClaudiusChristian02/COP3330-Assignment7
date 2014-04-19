

  // * *******************************************************************
  // * * Taken from Deitel & Associates, Inc. and Prentice Hall          *
  // * * Deitel & Deitel How to Probram in C++ 3rd Edition.              *
  // * * Figure 21.4: list.h                                             *
  // * * Template ListNode Class definition.                             *
  // * *                                                                 *
  // * * This class must inherit the class listnode.h in order to        *
  // * * function properly.                                              *
  // * *                                                                 *
  // * * Additional comments and modifications added by                  *
  // * *   Dr. David A. Gaitros                                          *
  // * *******************************************************************
#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std; 
using std::cout;
  // * *******************************************************************
  // * *  The #include <new> ensures that the operators "new" and        *
  // * *  "delete" and other functions of types composing the            *
  // * *  fundamentals of C++ memory management are provided to the      *
  // * *  class.                                                         *
  // * *******************************************************************

#include <new>
#include "listnode.h"  // ListNode class definition

template< class NODETYPE >
class List {

public:
   List();      // constructor
   ~List();     // destructor
   void insertAtFront( const NODETYPE & );
   void insertAtBack( const NODETYPE & );
   void insertMiddle( const NODETYPE &, int );
   bool removeFromFront( NODETYPE & );
   bool removeMiddle (NODETYPE &, int);
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const;
   void print() const;

private:
   ListNode< NODETYPE > *firstPtr;  // pointer to first node
   ListNode< NODETYPE > *lastPtr;   // pointer to last node
   int RecordCounter; 
  
   ListNode< NODETYPE > *getNewNode( const NODETYPE & );

}; 


template< class NODETYPE >
// * *******************************************************************
// * * Default constructor, set the head and tail pointer to null      *
// * * indicating a null or empty list.                                *
// * *******************************************************************

List< NODETYPE >::List(): 
  firstPtr( 0 ), 
     lastPtr( 0 )
{
    // RecordCounter=0;
  } 
// * ******************************************************************
// * *  Class destructor.  Goes through the entire list and removes   *
// * *  each ListNode one at a time.  When you are done with a        *
// * *  destructor the list should be empty.                          *
// * ******************************************************************

template< class NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) {    // List is not empty
 // *******************************************************************
 //  COMMENTED OUT.  USED IN TESTING TO SEE IF WE ARE DESTROYING THE  *
 //  NODES.                                                           *
 // *******************************************************************
 //      cout << "Destroying nodes ...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 )         // delete remaining nodes
      {  
         tempPtr = currentPtr;

 // *******************************************************************
 //  COMMENTED OUT.  USED IN TESTING TO SEE IF WE ARE DEALLOCATING    *
 //  THE NODES PROPERLY.                                              *
 // *******************************************************************
 //         cout << tempPtr->data << '\n';  

         currentPtr = currentPtr->nextPtr;
         delete tempPtr;

      }
    RecordCounter=0; 
   }

//   cout << "All nodes destroyed\n\n";

} 

// * ******************************************************************
// * * insertAtFront.  Takes a NODETYPE record and inserts it at the  *
// * *   front of the list.  If the list is empty, it places it where *
// * *   both the first and last pointer are pointing to it.          *
// * ******************************************************************


// insert node at front of list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;

   } 
 RecordCounter++; 
} 


// * ******************************************************************
// * *  insertAtBack:  Inserts a NODETYPE record at the end of the    *
// * *    list. If the list is empty, it points the first and last    *
// * *    pointer to this record.                                     *
// * ******************************************************************

template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      lastPtr->nextPtr = newPtr;
      lastPtr = newPtr;

   } // end else
   RecordCounter++; 
} // end function insertAtBack

template< class NODETYPE >
void List < NODETYPE >::insertMiddle( const NODETYPE &value, int index )
{
	ListNode< NODETYPE > *newPtr = getNewNode( value );

	// creating a left pointer
	ListNode< NODETYPE > *lftPtr;

	// creating a right pointer
	ListNode< NODETYPE > *rgtPtr;

    // if the position number is smaller than the number of items in the list, just 
	// insert the item at the back.
	if( index <= 1 )
	{

		insertAtFront( value );

	} // end of if( index <= 1 )

	// if the position number is larger than the number of items in the list, just 
	// insert the item at the back.
	else if( index > RecordCounter )
	{

		insertAtBack( value );

	} // end of else if( index >= RecordCounter )

	else
	{
	
	// set left pointer to the first pointer
	lftPtr = firstPtr;

	    // find the left pointer by subtracting the index by one and setting the 
	    // left pointer to the next pointer after every iteration of the loop
		while( ((index - 2) >= 0) )
		{
			lftPtr = lftPtr->nextPtr;

			index--;
		} // end of while( ((index - 1) >= 0) )
	
		// finds the right pointer
		rgtPtr = lftPtr->nextPtr;

		// makes the left pointer point to the new pointer
		lftPtr->nextPtr = newPtr;

		// makes the new pointer point to the right pointer
		newPtr->nextPtr = rgtPtr;

	} // end of else
} // end of void insertMiddle( const NODETYPE &, int )

   
// delete node from front of list
// * ******************************************************************
// * *  removeFromFront:  Delete a NODETYPE from the front of the     *
// * *      list.  If the list is empty it returns a false.           *
// * *      Also, you must be concerned if you are removing the       *
// * *      last node.                                                *
// * ******************************************************************

template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )  // List is empty
      return false;  // delete unsuccessful

   else {  
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;  // data being removed
      delete tempPtr;

      return true;  // delete successful

   } // end else
 RecordCounter--; 
} // end function removeFromFront

template< class NODETYPE >
bool List< NODETYPE >::removeMiddle (NODETYPE &value, int index)
{

	// determines if the position is valid or invalid
	if( (index < 1) || (index > RecordCounter) )
	{

		return false;

	} // end of if( (index < 0) || (index >= RecordCounter) )


	// if the index equals the 1 that means it is the first
	// in the list therefore call remove from front function
	else if( index == 1 )
	{
		return removeFromFront( value );

	}

	// if the index equals the record counter that means it is the last
	// in the list therefore call remove from back function
	else if( index == RecordCounter )
	{

		return removeFromBack( value );
	}

	else
	{

	// creating a left pointer
	ListNode< NODETYPE > *lftPtr;

	// creating a right pointer
	ListNode< NODETYPE > *rgtPtr;

	// set left pointer to the first pointer
	lftPtr = firstPtr;

	    // find the left pointer by subtracting the index by one and setting the 
	    // left pointer to the next pointer after every iteration of the loop
		while( ((index - 2) >= 0) )
		{
			lftPtr = lftPtr->nextPtr;

			index--;
		} // end of while( ((index - 1) >= 0) )

		// finds the right pointer
		rgtPtr = lftPtr->nextPtr->nextPtr;

		// delete the desired pointer
		delete lftPtr->nextPtr;

		// deletes the middle pointer, and assigns right pointer to next pointer
		lftPtr->nextPtr = rgtPtr;

		return true;
	}
} // end of bool List< NODETYPE >::removeMiddle (NODETYPE &value, int index)

// * ******************************************************************
// * * removeFromBack:  Similar to removerFromFront.  If the list     *
// * *     is empty you return a false.  Else you remove the node     *
// * *     pointed to by the last pointer.  You must also check to    *
// * *     to see if you are creating an empty list by removing       *
// * *     the last node.                                             *
// * ******************************************************************


template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;  // delete unsuccessful

   else {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else {
         ListNode< NODETYPE > *currentPtr = firstPtr;

         // locate second-to-last element
         while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr;

         lastPtr = currentPtr;
         currentPtr->nextPtr = 0;

      } // end else

      value = tempPtr->data;
      delete tempPtr;

      return true;  // delete successful

   } // end else
 RecordCounter--; 
} // end function removeFromBack


// * ******************************************************************
// * *  isEmpty() returns true if the firstPtr is null.               *
// * *   otherwise it returns a false.                                *
// * ******************************************************************

template< class NODETYPE > 
bool List< NODETYPE >::isEmpty() const 
{ 
   return firstPtr == 0; 
   
} // end function isEmpty

// * ******************************************************************
// * *   getNewNode().  Not really needed but returns a pointer       *
// * *      to a new node of type NODETYPE.  Usually part of a        *
// * *      template.                                                 *
// * ******************************************************************

// return pointer to newly allocated node
template< class NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode( 
   const NODETYPE &value )
{
   return new ListNode< NODETYPE >( value );

} // end function getNewNode

// * ******************************************************************
// * *   print(); Prints the list if it is not empty.                 *
// * *   NOTE: Here you  must overload the << operator to work with   *
// * *   NODETYPE.                                                    *
// * ******************************************************************

template< class NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) {
      cout << "The list is empty\n\n";
      return;

   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 ) {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;

   } // end while

   cout << "\n\n";

} // end function print

#endif

/**************************************************************************
 * (C) Copyright 1992-2003 by Deitel & Associates, Inc. and Prentice      *
 * Hall. All Rights Reserved.                                             *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
