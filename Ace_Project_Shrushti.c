#include <stdio.h>
#include <stdlib.h>

#define NUM_SUBJECTS 5

// Function to calculate total marks
int calculateTotal(int marks[]) {
    int total = 0;
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        total += marks[i];
    }
    return total;
}

// Function to calculate average marks
float calculateAverage(int total) {
    return total / (float)NUM_SUBJECTS;
}

// Function to determine grade based on average
char determineGrade(float average) {
    if (average >= 90) {
        return 'A'; // Excellent
    } else if (average >= 75) {
        return 'B'; // Good
    } else if (average >= 50) {
        return 'C'; // Average
    } else if (average >= 35) {
        return 'D'; // Below Average
    } else {
        return 'F'; // Fail
    }
}

// Function to input marks with validation
int inputMarks(int subject) {
    int mark;
    while (1) {
        printf("Enter marks for Subject %d: ", subject);
        if (scanf("%d", &mark) != 1 || mark < 0 || mark > 100) {
            printf("Invalid input. Please enter a valid mark between 0 and 100.\n");
            while(getchar() != '\n'); // Clear input buffer
        } else {
            return mark;
        }
    }
}

int main() {
    int marks[NUM_SUBJECTS];
    int total;
    float average;
    char grade;

    // Input marks for 5 subjects with validation
    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        marks[i] = inputMarks(i + 1); // Call function for each subject
    }

    // Calculate total marks
    total = calculateTotal(marks);

    // Calculate average marks
    average = calculateAverage(total);

    // Determine grade
    grade = determineGrade(average);

    // Output the results
    printf("\nTotal Marks: %d\n", total);
    printf("Average Marks: %.2f\n", average);
    printf("Grade: %c\n", grade);

    return 0;
}
