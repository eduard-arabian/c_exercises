#ifndef GRADE_SCHOOL_H_
#define GRADE_SCHOOL_H_

#include <stdint.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

void swap_students(roster_t *roster, size_t index);
void sort_grades(roster_t *roster);
int check_student(roster_t roster, char name[]);
void init_roster(roster_t *roster);
int add_student(roster_t *roster, char name[], uint8_t grade);
roster_t get_grade(roster_t *roster, uint8_t grade);

#endif  // GRADE_SCHOOL_H_
