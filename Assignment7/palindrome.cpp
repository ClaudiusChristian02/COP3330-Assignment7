#include<iostream>;
#include<stdio.h>;
#include"stack.h"
using namespace std;

char Array[ 100 ];
char TestArray[ 100 ];

// initial stack created called "A"
class Stack<char> A;

// compare stack created called "B"
class Stack<char> B;

int size = 0;
int flag = 1;
char ca, cb;


int main()
{
	// initialize all array indexes to a null character
	for( int i = 0; i < 100; i++ )
	{
		Array[ i ] = '\0';

	} // end of for( int i = 0; i < 100; i++ )

	cout<< "Please enter in text no more than 100 characters long: ";

	cout << "\n\n>";

	// read in user input
	cin.getline( Array, 100 );

	// determine the array size
	for( size = 0; size < 100; size++)
	{
		if( Array[ size ] == '\0')
			break;		

	} // end of for( size; size < 100; size++)  

	// push the character to the stack from the head to the tail
	for( int i = 0; i < size; i++)
	{

		//change all lowercase to upper case
		if( (Array[ i ] >= 97) && (Array[ i ] <= 122) )
		{
			Array[ i ] -= 32;
		}

		// determines if the character is a letter and if it is push it to
		// the stack
		if( (Array[ i ] >= 65) && (Array[ i ] <= 90) )
		{
			A.push( Array[ i ] );
		}
	} // end of for( int i = 0; i < size; i++) 


	// push the character to the stack from the tail to the head
	for( int i = size - 1; i >=  0; i--)
	{
			//change all lowercase to upper case
		if( (Array[ i ] >= 97) && (Array[ i ] <= 122) )
		{

			Array[ i ] -= 32;
		}

		// determines if the character is a letter and if it is push it to
		// the stack
		if( (Array[ i ] >= 65) && (Array[ i ] <= 90) )
		{
		B.push( Array[ i ] );
		}
	} // end of for( int i = 0; i < size; i++)

	// a while loop that determines if the stack is empty. If the stack is not empty
	// we find out if the contents are a palindrome
	while( (A.isStackEmpty() == false) && (B.isStackEmpty() == false) )
	{

		// this assigns the first stack character to ca or cb
		A.pop( ca );
		B.pop( cb );

		// determine if the characters are not equal
		if( (ca != cb) )
		{
			flag = 0;
			break;

		} // end of if( (ca != cb) )
	} // While( (A.isStackEmpty() == false) && (B.isStackEmpty() == false) )

	cout << "\n";
	cout << "\"";

	// print out the characters the user entered
	for( int i = 0; i < size; i++ )
	{
		cout << Array[ i ];

	} // end of for( int i = 0; i < size; i++ 

	// formating: adding a quotation mark
	cout << "\"";

	if( flag == 0 )
	{
		// if not equal let the user know by printing a message
		cout << " is NOT a palindrome.\n\n";
	}

	else
	{
		// if not equal let the user know by printing a message
		cout << " IS a palindrome.\n\n";

	} // end of if( flag == 0 )
} // end main
