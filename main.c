#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// simple (v1)
// we create a array of tasks with memory dynamically allocated
// simply when the program is restarted the task are gone
// fetch a task from the array
// all from the command line
// ./main add "complete C project v1"
// ./main get
// ./main complete <num> (simple array indexing?)
// ./main delete <num>

int main(int argc, char *argv[]){

  char **tasks;
  int max_len;
  int num_tasks;

  printf("Number of tasks: ");
  scanf("%d", &num_tasks);
  
  // ???
  while(getchar() != '\n' && getchar() != EOF); 

  printf("Max length for each task: ");
  scanf("%d", &max_len);
  
  while(getchar() != '\n' && getchar() != EOF); 
  
  tasks = (char **)malloc(num_tasks * sizeof(char *));
  if (tasks == NULL){
    printf("Memory allocation failiure\n");
    return 1;
  }
  
  for(int i = 0; i < num_tasks; i++){
    tasks[i] = (char *)malloc((max_len + 1) * sizeof(char));  

    if (tasks[i] == NULL){
      printf("Memory allocation failiure for taks %d\n", i);
    }

    printf("Enter task %d:", i+1);
    // scanf("%s", tasks[i]); this is causing a buffer overflow so the safer alternative is fgets()

    fgets(tasks[i], max_len + 1, stdin); // +1 for null terminator(0 at end)
   
    tasks[i][strcspn(tasks[i], "\n")] = 0; // this is for manual insertion of the null terminator
    // why this ? cause scanf() does not include /n newline character at the end of the input string 
    // if the line is shorter than the buffer
  }


  printf("Your tasks are: \n");
  for (int i = 0; i < num_tasks; i++){
    printf("%d %s\n",i+1, tasks[i]);
  }

  for (int i = 0; i < num_tasks; i++){
    free(tasks[i]);
  }

  free(tasks);

  
  return 0;
}
