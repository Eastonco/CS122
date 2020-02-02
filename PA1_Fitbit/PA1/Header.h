#ifndef PA1_HEADER
#define PA1_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum sleep {
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
}Sleep;

typedef struct fitbit {
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
}FitbitData;

typedef struct badsleep {
	char minuteStart[9];
	char minuteEnd[9];
	int totalTime;
}BadSleep;

typedef struct mostmovement {
	char minute[9];
	int steps;
}MostMovement;

void populateArray(FitbitData fitbit[], FILE * infile);
void DataClense(FILE * infile, FILE * outfile);
char * ShiftAndInsert(char line, int location);
double CaloriesBurned(FitbitData fitbit[]);
double DistanceWalked(FitbitData fitbit[]);
int FloorsClimbed(FitbitData fitbit[]);
int StepsTaken(FitbitData fitbit[]);
double AvgHeartRate(FitbitData fitbit[]);
int maxsteps(FitbitData fitbit[]);
BadSleep worstsleep(FitbitData fitbit[]);
void PrintResults(FILE * outfile, FILE * source, double totalCalories, double totalDistance, int totalFloors, int totalStep, double avgHeart, int maxSteps, BadSleep sleep);


#endif // !PA1_HEADER