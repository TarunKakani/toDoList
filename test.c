#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  
  // double pointer for dynamic array of dynamic strings
  char **tasks;
  int max_len;
  int num_tasks;

  printf("Number of tasks: ");
  scanf("%d", &num_tasks);

  printf("Max length for each task: ");
  scanf("%d", &max_len);

  // we need to allocate memory for an array of characters
  // not a single character
  //
  // (char *)malloc(num_tasks * sizeof(char));
  // this above code allocates memory for an array of characters
  // but in the end it is a single strings
  //
  // (char **)malloc(num_tasks * sizeof(char *))
  // lets understand this one
  // this is the correct way of representing a dynamic array of string
  // basically each element in the array is a pointer that will hold
  // the address of a string
  
  // so in the end we are allocating memory for an array of pointers
  // (for num_tasks tasks)
  tasks = (char **)malloc(num_tasks * sizeof(char *));
  if (tasks == NULL){
    printf("Memory allocation failiure\n");
    return 1;
  }
  
  // now we will allocate memory for each individual task like we did before
  for(int i = 0; i < num_tasks; i++){
    tasks[i] = (char *)malloc((max_len + 1) * sizeof(char));
    // max_len + 1, the plus 1 is for null terminator
    // when working with strings in C you need one extra byte of memory
    // for a special character called the null terminator
    // it tells the Compiler when the string ends without it 
    // functions like printf wont know when to stop reading

    // they would continue past the end of your intended strings
    // and read into unallocated memory leading buffer overflows etc


    if (tasks[i] == NULL){
      printf("Memory allocation failiure for taks %d\n", i);
    }

    printf("Enter task %d: ", i + 1);
    scanf("%[^\n]s", tasks[i]); // the regex reads the entire line until
    // a new line characer \n
  }

  printf("Your tasks are: \n");
  for (int i = 0; i < num_tasks; i++){
    printf("%d %s\n",i+1, tasks[i]);
  }

  // free the memory for each individual task first
  for (int i = 0; i < num_tasks; i++){
    free(tasks[i]);
  }

  // then free the array of pointers
  free(tasks);

  return 0;
}
