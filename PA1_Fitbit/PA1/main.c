
/*******************************************
* Connor Easton                            *
* CptS 122 - Andy O'Fallon				   *
* Date Created: August 29, 2018            *
* Date Last Modified: Septermber 3, 2018   *
* Purpose: Reads in from FitbitData.csv,   *
*	clenses data for null values, writes   *
*	data to fitbit array, does calculations*
*	prints data to results.csv and screen  *
*******************************************/

//test commit

//push me

#include "Header.h"

int main(void) {

	FILE * infile = NULL;
	FILE * infile_c = NULL;
	//sets infile and data clensed infile copy
	infile = fopen("FitbitData.csv", "r");
	infile_c = fopen("FitbitData_c.csv", "w");

	if (infile == NULL || infile_c == NULL) { // tests for successful opening
		printf("File opening unsuccessful\n");
		return 0;
	}
	else 
		printf("File opening successful\n");
	
	FitbitData fitbit[1442] = { 0 }; //initailizes the fitbit array

	DataClense(infile, infile_c); //fills in any null data with 0

	fclose(infile); // closes orginal file
	fclose(infile_c); //closes and reopens clensed file for reading
	infile_c = fopen("FitbitData_c.csv", "r");

	populateArray(fitbit, infile_c); //populates the fitbit array 
	
	//does a bunch of calculations 
	double totalCalories = CaloriesBurned(fitbit);
	double totalDistance = DistanceWalked(fitbit);
	int totalSteps = StepsTaken(fitbit); 
	int totalFloors = FloorsClimbed(fitbit);
	double avgHeart = AvgHeartRate(fitbit); 
	int maxstep = maxsteps(fitbit); 
	BadSleep worstSleepTime = worstsleep(fitbit);


	FILE * outfile = NULL;
	outfile = fopen("Results.csv", "w"); //opens the results for printing
	fclose(infile_c);
	infile_c = fopen("FitbitData_c.csv", "r"); // reopens the clensed data for rereading

	PrintResults(outfile, infile_c, totalCalories, totalDistance, totalFloors, totalSteps, avgHeart, maxstep, worstSleepTime);


	return 0;
}