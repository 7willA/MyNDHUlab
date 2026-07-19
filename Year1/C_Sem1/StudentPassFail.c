#include <stdio.h>
#include <string.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int sid, student_id, course_id, score;
    int student_scores[100000000] = {0}; 
    int student_courses[100000000] = {0}; 
    int total_students = 0, failed_students = 0;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &sid, &student_id, &course_id);
        student_courses[student_id]++; 
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &sid, &score);
        student_scores[sid] += score;
    }

    for (int i = 10000000; i < 100000000; i++) {
        if (student_courses[i] > 0) {
            total_students++;
            double avg_score = (double)student_scores[i] / student_courses[i];
            if (avg_score < 60) {
                failed_students++;
            }
        }
    }

    printf("%d %d\n", total_students, failed_students);
    return 0;
}

/*#include <stdio.h>
#include <string.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int sid, student_id, course_id, score;
    int student_scores[100000000] = {0};  // Total scores for each student
    int student_courses[100000000] = {0}; // Number of courses for each student
    int total_students = 0, failed_students = 0;

    // Read `courses` table
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &sid, &student_id, &course_id);
        student_courses[student_id]++; // Count courses per student
    }

    // Read `scores` table and update total scores
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &sid, &score);
        student_scores[sid] += score; // Update scores for course sid
    }

    // Calculate total students and check failed students
    for (int i = 10000000; i < 100000000; i++) { // Loop over valid 8-digit IDs
        if (student_courses[i] > 0) {
            total_students++; // Count this as a unique student
            double avg_score = (double)student_scores[i] / student_courses[i];
            if (avg_score < 60) {
                failed_students++; // Student failed if average < 60
            }
        }
    }

    // Print the result
    printf("%d %d\n", total_students, failed_students);
    return 0;
}
*/