#include <stdio.h>

struct Activity {
  char id[5];
  int start;
  int finish;
};

void activitySelection(Activity activities[], int n);

int main(void) {

  //activities
  Activity activities[8] = {
    {"a1", 1, 5},
    {"a2", 3, 4},
    {"a3", 7, 9},
    {"a4", 2, 6},
    {"a5", 10, 12},
    {"a6", 14, 17},
  };

  //number of activities
  int n = 6;

  activitySelection(activities, n);

  return 0;
}

void activitySelection(Activity activities[], int n) {

  int i, j;

  Activity temp;

  //step 1
  //sort the activities as per finishing time in ascending order
  //Bubble sort
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - 1; j++){
      if(activities[j].finish > activities[j+1].finish) {
        temp = activities[j];
        activities[j] = activities[j+1];
        activities[j+1] = temp;
      }
    }
  }

  //sorted
  printf("Sorted activities as per finish time (ascending order)\n");
  printf("%10s %10s %10\n","Activity", "Start", "Finish");
  for(i = 0; i < n; i++) {
    printf("%10s %10i %10i\n", activities[i].id, activities[i].start, activities[i].finish);
  }

  //step 2
  //select the first activity
  printf("-----Selected Activities-----\n");
  //printf("%10s %10s %10s\n", "Activity", "Start", "Finish");
  printf("%10s %10i %10i\n", activities[0].id, activities[0].start, activities[0].finish);

  //step 3
  //select next activity whose start time is greater than
  //or equal to the finish time of the previously selected activity
  i = 0;
  for(j = 1; j < n; j++) {
    if(activities[j].start >= activities[i].finish) {
      printf("%10s %10i %10i\n", activities[j].id, activities[j].start, activities[j].finish);
      i = j;
    }
  }
}
