/*
 * File: driver1.c
 * YOUR NAME ... YOU NEED TO IMPLEMENT THE main() + additional functions if needed
 *  Arshdeep Sandhu gbu472
 * ....
 */

/*
	gcc -Wall -g -c mylinkedlist.c
	gcc -Wall -g -c driver1.c
	gcc -Wall -g -o driver1.exe driver1.o mylinkedlist.o
  ./driver1.exe

*/
#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"
#include <stddef.h>
#include <fcntl.h>

/* 
 * Function: ReadLine
 * Usage: s = ReadLine();
 * ---------------------
 * ReadLine reads a line of text from standard input and returns
 * the line as a string.  The newline '\n' character that terminates
 * the input is not stored as part of the string.
 */

//moved to .h
// char *ReadLine(void);



 
int main(int argc, char *argv[])
{
  // YOU NEED TO IMPLEMENT THIS driver1.c USING FUNCTIONS FROM mylinkedlist.h
  // But before that, implement your ReadLine() function, and test it as shown below. 
  // IF NEEDED, YOU CAN ALSO IMLEMENT YOUR OWN FUNCTIONS HERE

  char *name;
  // eeee
  // if(fd < 0) 
  //       printf("Error opening the file\n");
  // dup2(fd,STDOUT_FILENO);
  printf("Enter a name to test your ReadLine function  : ");
  name = ReadLine();
  printf("User entered : %s \n", name);  
  linked_list_T* list= NewLinkedList();
  if(list==NULL){
    printf("list is nulll failed mem");
  }
  int condition = userSelect();
  while(condition!=8){
    doFunction(condition,list);
    condition=userSelect();
  }
  FreeLinkedList(list);
  free(name);
  return 0;
}


   
