#include "grade_school.h"
#include <string.h>

void swap_students(roster_t *roster, size_t index) {
    student_t tmp;

    tmp.grade = roster->students[index].grade;
    roster->students[index].grade = roster->students[index + 1].grade;
    roster->students[index + 1].grade = tmp.grade;

    strcpy(tmp.name, roster->students[index].name);
    strcpy(roster->students[index].name, roster->students[index + 1].name);
    strcpy(roster->students[index + 1].name, tmp.name);
}

void sort_grades(roster_t *roster) {
    for (size_t i = 0; i < roster->count - 1; i++)
        for (size_t j = 0; j < roster->count - 1 - i; j++)
            if ((roster->students[j].grade > roster->students[j + 1].grade) ||
                (roster->students[j].grade == roster->students[j + 1].grade
                && strcmp(roster->students[j].name, roster->students[j + 1].name) > 0))
                swap_students(roster, j);
}

int check_student(roster_t roster, char name[]) {
    size_t i = 0;

    for (; i < roster.count && strcmp(roster.students[i].name, name); i++) {}

    return strcmp(roster.students[i].name, name);
}

void init_roster(roster_t *roster) {
    roster->count = 0;
    for (size_t i = 0; i < MAX_STUDENTS; i++) {
        roster->students[i].grade = 0;
        strcpy(roster->students[i].name, "");
    }
}

int add_student(roster_t *roster, char name[], uint8_t grade) {
    int check = 0;

    if (check_student(*roster, name)) {
        roster->students[roster->count].grade = grade;
        strcpy(roster->students[roster->count].name, name);
        roster->count++;
        sort_grades(roster);
        check++;
    }

    return check;
}

roster_t get_grade(roster_t *roster, uint8_t grade) {
    roster_t graded;

    init_roster(&graded);
    for (size_t i = 0; i < roster->count; i++)
        if (roster->students[i].grade == grade) {
            graded.students[graded.count].grade = roster->students[i].grade;
            strcpy(graded.students[graded.count].name, roster->students[i].name);
            graded.count++;
        }

    if (graded.count)
        sort_grades(&graded);

    return graded;
}
