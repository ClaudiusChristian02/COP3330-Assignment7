COP3330-Assignment7
===================

Programming
Assignment
#7
Learning objective : You are to gain experience using a single class to implement a solution to more than one
problem and experience modifying a class that implements a data structure.

Exercise 1
Write a main program called palindrome.cpp. This program will accept as input a single group of character
and your output will be a single answer, either the string is a palindrome or not a palindrome. A palindrome is
a word or string of characters that is spelled the same backward or forward. Write a program that uses a stack object to determine if a string is a palindrome (i.e. the string is spelled
identically backward and forward). The program should ignore spaces and punctuation. Go ahead and start your program by reading in a C-style string from standard input, using the getline function.
You may assume a limit of 100 characters on the string (although this can be written, with a little more effort, to
accept any size string). Your algorithm must make use of a stack (of type char). Use the Deitel implementation
of the Stack from "stack.h" (you don't need to change this file). Your program should examine only the letters in the character string input and ignore spaces and any special
characters. Additionally your program must ignore the case of a letter. The letter ‘a’ is the same as ‘A’. See
the examples below.

Sample runs: (user input underlined)

Please enter a string:
> ABCDEFGHGFEDCBA

"ABCDEFGHGFEDCBA" IS a palindrome

Please enter a string:
> The quick brown fox

"The quick brown fox" is NOT palindrome

Please enter a string:
> Cigar? Toss it in a can. It is so tragic.

"Cigar? Toss it in a can. It is so tragic." IS a palindrome\

Want some palindromes to test you can visit the site www.palindrome.com.

Implementation Details:
-­‐ If the user enters a string of characters that contain spaces or special characters you need to ignore those characters when evaluating the string as a palindrome.
-­‐ You need to ignore the case ( upper or lower case) which means that you should change the input string to either upper or lower case letters.
-­‐ Since you are reading data into a C-style string to begin, you may use any of the libraries <iostream>, <cstring>, and <cctype>, if you like. (The first, of course, for I/O, and the other two, since they deal
with C-style strings and characters).

Exercise 2
Modify the List class (file list.h so that it has two more functions, which will allow inserts and removes from anywhere in the linked list. Your functions should be called:

• insertMiddle
• removeMiddle

Your functions should have all the same featuresasthegiven
insert and remove functions, except that yours each have one extra parameter. The second parameter on each of your functions should
be of type int, representing the position at which to insert (or delete). Sample calls for a list of integers:

L.insertMiddle(345, 5); // attempts to insert the value 345
                        // as the 5th item in the list.
                        
L.removeMiddle(x, 10); // attempts to delete the 10th item in the
                       // list and captures its value into x.
                       
For
insertMiddle, if the position number is larger than the number of items in the list, just insert the item at the back.
If it's too small (i.e. 0 or less), insert at the front. For removeMiddle, return false if the position is invalid (without removing
anything).

I've modified the menu program of Figure 21.5 so that it adds in two more menu options for testing these
features. You can use it to test your class: menu7.cpp
