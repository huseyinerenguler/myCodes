/*
NAME: Hüseyin Eren Güler
ID: 15050111014

-> This program takes the exam grades of each student and
   display student and exam average.
*/   

#include <stdio.h>

int main() {
	
	int studentNumber = 3;
	int examNumber = 3;
	
	int exam[studentNumber][examNumber];
	double studentAverage[studentNumber][1];
	double examAverage[examNumber][1];
	
	int  total = 0;
	
	// loop for to gets exam grades for each students and calculate averages
	for (int x = 0; x < studentNumber; x++) {
				
		for (int y = 0; y < examNumber; y++) {
			
			printf("Enter exam %d grade of student %d: ", y+1, x+1);
			scanf("%d", &exam[x][y]);
		}
		
		total = 0;
		
		// loop for to calculate total exam grades for each students
		for (int k = 0; k < examNumber; k++) {
			
			total = total + exam[x][k];
		}
		
		studentAverage[x][0] = (double)total / examNumber;
		printf("Average of student %d is: %.1lf\n\n", x+1, studentAverage[x][0]);
	}
	
	// loop for to calculate each exam average
	for (int x = 0; x < examNumber; x++) {
		
		total = 0;
		
		// loop for to calculate total exam grades on students
		for (int y = 0; y < studentNumber; y++) {
			
			total = total + exam[y][x];
		}
		
		examAverage[x][0] = (double)total / studentNumber;
	}
	
	// loop for to prints seperately each exam average
	for (int x = 0; x < examNumber; x++) {
		
		printf("Total exam %d average: %.1lf\n", x+1, examAverage[x][0]);
	}

	return 0;
}
