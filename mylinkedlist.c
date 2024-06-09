
/*
 * File: mylinkedlist.c
 * Arshdeep Sandhu gbu472 ...
 * YOU NEED TO IMPLEMENT THE FUNCTIONS  here
 * ....
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylinkedlist.h"
#include <math.h>
/*
 * Function: NewStudentCell
 * Usage: student_cell_T *element;
 *        element = NewStudentCell(int id, double gpa, char *name);
 * --------------------------
 * This function allocates space for a student cell and intilize its fileds
 */
student_cell_T *NewStudentCell(int id, double gpa, char *name)
{
  student_cell_T *element;

  element = (student_cell_T *)malloc(sizeof(student_cell_T));
  if (!element)
  {
    fprintf(stderr, "NewStudentCell cannot allocate memory\n");
    return NULL;
  }
  element->id = id;
  element->gpa = gpa;
  element->name = name;

  return element;
}

/*
 * Function: NewLinkedList
 * Usage: linked_list_T *list;
 *        list = NewLinkedList();
 * --------------------------
 * This function allocates and returns an empty linked list.
 */
linked_list_T *NewLinkedList(void)
{
  linked_list_T *list;

  list = (linked_list_T *)malloc(sizeof(linked_list_T));
  if (!list)
  {
    fprintf(stderr, "NewLinkedList cannot allocate memory\n");
    return NULL;
  }

  list->head = NULL;
  list->tail = NULL;

  return list;
}

/*
 * Function: FreeLinkedList
 * Usage: FreeLinkedList(list);
 * ------------------------
 * This function frees the storage associated with list.
 */
void FreeLinkedList(linked_list_T *list)
{
  student_cell_T *temp = Delist(list);
  while (temp)
  {

    freeStudent(temp);
    temp = Delist(list);
  }
  free(list);
}

/*
 * Function: Enlist
 * Usage: Enlist(list, element);
 * -------------------------------
 * This function adds a student cell pointed by element to the end of the list.
 */
void Enlist(linked_list_T *list, student_cell_T *element)
{

  if (list->head == NULL)
  {
    list->head = element;
    list->tail = element;
  }
  else
  {
    list->tail->next = element;
    list->tail = element;
  }
  element->next = NULL;
}

/*
 * Function: Delist
 * Usage: element = Delist(list);
 * --------------------------------
 * This function removes the student cell at the head of the list
 * and returns its address to the caller (client).  If the list is empty, Delist
 * prints an Error with an appropriate message and returns NULL.
 */
student_cell_T *Delist(linked_list_T *list)
{
  if (LinkedListIsEmpty(list))
  {
    printf("Linked list is empty cannot Delist\n");
    return NULL;
  }
  student_cell_T *temp = list->head;
  list->head = list->head->next;
  return temp;
}

/*
 * Functions: LinkedListIsEmpty, LinkedListIsFull
 * Usage: if (LinkedListIsEmpty(list)) . . .
 *        if (LinkedListIsFull(list)) . . .
 * -------------------------------------
 * These functions test whether the list is empty or full.
 */
int LinkedListIsEmpty(linked_list_T *list)
{
  if (list->head == NULL)
  {
    return 1;
  }
  return 0;
}

int LinkedListIsFull(linked_list_T *list)
{
  // linked_list_T* temp = list->head;
  // while(temp != NULL || ){

  //   temp
  // }
  return 0; // because we have linked list
}

/*
 * Function: LinkedListLength
 * Usage: n = LinkedListLength(list);
 * ------------------------------
 * This function returns the number of elements in the list.
 */
int LinkedListLength(linked_list_T *list)
{
  student_cell_T *temp = list->head;
  int count = 0;
  while (temp)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

/*
 * Function: GetLinkedListElement
 * Usage: element = GetLinkedListElement(list, index);
 * -----------------------------------------------
 * This function returns the element at the specified index in the
 * list, where the head of the list is defined as index 0. For
 * example, calling GetLinkedListElement(list, 0) returns the initial
 * element from the list without removing it.  If the caller tries
 * to select an element that is out of range, GetLinkedListElement prints
 * Error and returns NULL.  Note: This function is not a fundamental list operation
 * and is instead provided mainly to facilitate debugging.
 */
student_cell_T *GetLinkedListElement(linked_list_T *list, int index)
{
  student_cell_T *temp = list->head;
  while (index != 0)
  {
    if(temp == NULL){
      return NULL;
    }
    index--;
    temp = temp->next;
  }
  return temp;
}

/* OTHER FUNCTIONS YOU WOULD NEED....
 * EXPORT THEM HERE, BUT IMPLMENT THEM in mylinkedlist.c
 */
/* 
 * IMPLEMENTATION of ReadLine();
 * Function: ReadLine
 * Usage: s = ReadLine();
 * ---------------------
 * ReadLine reads a line of text from standard input and returns
 * the line as a string.  The newline '\n' character that terminates
 * the input is not stored as part of the string.
 *
 * In contrast to standard I/O functions (e.g., scanf with "%s", fgets) 
 * that can read strings into a given static size buffer, ReadLine function 
 * should read the given input line of characters terminated by a newline 
 * character ('\n') into a dynamically allocated and resized buffer based on 
 * the length of the given input line. 
 *
 * When implementing this function you can use standard I/O functions. 
 * We just want you to make sure you allocate enough space for the entered data. 
 * So don't simply allocate 100 or 1000 bytes every time. 
 * If the given input has 5 characters, you need to allocate space for 6 characters.
 *
 * Hint: initially dynamically allocate an array of char with size 10. 
 * Then, read data into that array character by charecter (e.g, you can use getchar()). 
 * If you see '\n' char before reading 10th character, you are done. And you know the 
 * exact length of the input string. So, accordingly allocate enough space and copy the 
 * data into new char array, insert '\0' instead of '\n' and free the original array. 
 * Then return the new string. However, if you DO NOT see '\n' char after 10th character, 
 * then you need larger space. Accordingly, resize your original array and double its size 
 * and continue reading data character by character as in the first step... 
 * Hope you got the idea! 
 *
 * Also please check for possible errors (e.g., no memory etc.) and appropriately handle 
 * them. For example, if malloc returns NULL, free partially allocated space and return 
 * NULL from this function. The program calling this function may take other actions, 
 * e.g., stop the program!
 */
char *ReadLine()
{
  // A SIMPLE WAY TO IMPLEMENT JUST TO TEST FOR NOW, BUT THIS IS NOT WHAT WE WANT!!!
  int allocatedNum=10;
  char *buff = malloc(allocatedNum*sizeof(char));
  if( buff == NULL){
    printf("could not allocate memory for buff");
    return NULL;
  }
  int position = 0;
  char c;
  while((c=getchar())!='\n'){
    if(position==allocatedNum){
      allocatedNum*=2;
      buff = (char*)realloc(buff,allocatedNum * sizeof(char));
      if( buff == NULL){
        printf("could not allocate memory for buff");
        return NULL;
      }
    }
    buff[position++] = c;
  }
  if(position==allocatedNum){
      
    buff = (char*)realloc(buff,allocatedNum*sizeof(char)+1);
    if( buff == NULL){
      printf("could not allocate memory for buff");
      return NULL;
    }
  }


  buff[position] ='\0';
  return buff;



}


/*
  frees student
*/
void freeStudent(student_cell_T *student)
{
  free(student->name);
  free(student);
}

/*
checks if student id exists in list
*/
bool studentExists(linked_list_T *list, int student){
  student_cell_T *temp = list->head;
  while (temp)
  {
    if (student == temp->id)
    {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

/*
  gets user selection and calls according functions
*/
int userSelect()
{
  printf("please enter one of the following: \n");
  printf("1 - Create a new student cell with given id, gpa, name info, and add it to the end of the linked list.\n");
  printf("2 - Remove the first student from linked list and print his/her id, gpa, name info \n");
  printf("3 - Print the number of students in the linked list (Length) \n");
  printf("4 - Print (id, gpa, name) of a student at a specific index (head of the list is defined as index 0)\n");
  printf("5 - Print the list of all students in the linked list. Print (id, gpa, name) of every student\n");
  printf("6 - Print the min, average, max GPAs in the linked list\n");
  printf("7 - Remove the student with highest GPA and print his/her info (if there are ties, just take the first one you found\n");
  printf("8 - Exit\n");
  int condition=getIndex();
  switch (condition)
  {
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    return condition;
    break;
  default:
    printf("defaulted %d\n",condition);
    return 0;
    break;
  }
  return 0;
}
/*
takes condition number 1-8 and calls correlated function
*/
void doFunction(int condition, linked_list_T *list)
{
  student_cell_T* temp;
  int index;
  switch (condition)
  {
  case 1:
    addStudent(list);
    break;
  case 2:
    printf("\n");
    temp= Delist(list);
    if(temp==NULL){
      return;
    }
    printf("Student Info\nStudents id: %d\nStudents GPA: %lf\nStudents Name: %s\n\n",temp->id,temp->gpa,temp->name);
    freeStudent(temp);
    break;
  case 3:
    printf("\n");
    printf("Number of students in List: %d\n\n",LinkedListLength(list));
    break;
  case 4:
    printf("\nPlease Enter Index you would like to find: ");
    index=getIndex();
    temp= GetLinkedListElement(list,index);
    if(temp==NULL){
      printf("input index exceeds length\n");
      break;
    }
    printf("Student Info at Index %d\nStudents id: %d\nStudents GPA: %lf\nStudents Name: %s\n\n",index,temp->id,temp->gpa,temp->name);
    
    break;
  case 5:
    printAllStudents(list);
    break;
  case 6:
    printData(list);
    break;
  case 7:
    findAndDeleteIndex(list);
    break;
  default:
    printf("Error in doFunction");
    break;
  }
}

/*
adds student to list
*/
void addStudent(linked_list_T *list){
  
  printf("Enter student id: ");
  int tempInt=getIndex();

  if(studentExists(list,tempInt)){
    printf("Student already exists: please choose another option\n");
    return;
  }

  printf("Enter student GPA: ");
  double tempDouble;
  char newLine[50];
  scanf("%lf", &tempDouble);
  fgets(newLine, 50, stdin);
  printf("Enter student name: ");
  char *tempName = ReadLine();
  student_cell_T *tempStudent = NewStudentCell(tempInt, tempDouble, tempName);
  if (tempStudent == NULL)
  {
    printf("mem failed for student");
  }
  Enlist(list, tempStudent);
  printf("\n");
}

/*
prints all students
*/
void printAllStudents(linked_list_T* list){
  int index=0;
  student_cell_T* temp= list->head;
  if(temp!=NULL)
    printf("\nStudent Info\n");
  else
    printf("No Students in List");
  while(temp){
    printf("Student Info at Index %d\nStudents id: %d\nStudents GPA: %lf\nStudents Name: %s\n\n",index,temp->id,temp->gpa,temp->name);
    temp = temp->next;
    index++;
  }
}
void printData(linked_list_T* list){
  student_cell_T* temp= list->head;
  int totalStudents=0;
  double minGPA=100;
  double maxGPA=-100;
  double average=0;
  if(temp!=NULL)
    printf("\nData:\n");
  else{
    printf("\nNo Students in List\n");
    return;
  }
  while(temp){
    minGPA=fmin(minGPA,temp->gpa);
    maxGPA= fmax(maxGPA,temp->gpa);
    ++totalStudents;
    average+=temp->gpa;
    temp = temp->next;
  }
  printf("Average GPA: %lf\nHighest GPA: %lf\nLowest GPA: %lf\n\n",average/totalStudents,maxGPA,minGPA);
}

/*
finds right index and deletes it from list then prints data
*/
void findAndDeleteIndex(linked_list_T* list){
  if(LinkedListIsEmpty(list)){
    printf("\nList is Empty\n");
    return;
  }
  student_cell_T* temp = list->head;
  student_cell_T* tempFindIndex = list->head;
  printf("Highest GPA student: \n");
  int maxGPA=-100;
  int index=0;
  int count=0;
  while(tempFindIndex){
    if(tempFindIndex->gpa>maxGPA){
      maxGPA=tempFindIndex->gpa;
      index=count;
    }
    count++;
    tempFindIndex=tempFindIndex->next;
  }
  
  int printIndex=index;
  if(index==0){
    printf("Student Info at Index %d\nStudents id: %d\nStudents GPA: %lf\nStudents Name: %s\n\n",printIndex,temp->id,temp->gpa,temp->name);
    freeStudent(temp);
    printf("Student is no longer in List\n");
    list->head=temp->next;
    return;
  }
  student_cell_T* prev = list->head;
  while(temp){
    if(index==0){
      prev->next=temp->next;
      printf("Student Info at Index %d\nStudents id: %d\nStudents GPA: %lf\nStudents Name: %s\n",printIndex,temp->id,temp->gpa,temp->name);
      freeStudent(temp);
      printf("Student is no longer in List\n\n");
      return;
    }
    prev=temp;
    --index;
    temp=temp->next;
  }
  
}

int getIndex(){
  char buffer[10];
  fgets(buffer, 10, stdin);
  int index;
  sscanf(buffer, "%d", &index);
  return index;
}