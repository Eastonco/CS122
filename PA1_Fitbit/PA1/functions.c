#include "Header.h"

void populateArray(FitbitData fitbit[], FILE * infile) {
	char line[100] = "";
	fgets(line, 100, infile); 
	strtok(line, ",");
	char * data = strtok(NULL, ","); // data is a temp information holder
	char target[10] = ""; // gets the target id for dynamic use and verrification
	strcpy(target, data); // coppies temp target data to permanant

	fgets(line, 100, infile);
	printf("Target: %s\n", target); // prints target
	int i = 0;
	while (!feof(infile)) { // loops until end of file 
		fgets(line, 100, infile);
		data = strtok(line, ",");
		if (strcmp(data, target) == 0) { // tests to verrify target user & copies all data to fitbit data struct
			strcpy(fitbit[i].patient, data);
			data = strtok(NULL, ",");
			strcpy(fitbit[i].minute, data);
			//printf("%s\n", fitbit[i].minute);
			data = strtok(NULL, ",");
			fitbit[i].calories = atof(data);
			data = strtok(NULL, ",");
			fitbit[i].distance = atof(data);
			data = strtok(NULL, ",");
			fitbit[i].floors = atoi(data);
			data = strtok(NULL, ",");
			//if(atoi(data) <= 170)
			fitbit[i].heartRate = atoi(data);
			data = strtok(NULL, ",");
			fitbit[i].steps = atoi(data);
			data = strtok(NULL, "\n");
			fitbit[i].sleepLevel = atoi(data);
			i++;
		}
		//if( i > 1439)
	//		__debugbreak();
		
	}

}

void DataClense(FILE * infile, FILE * outfile) {
	char line[100] = "";
	char editedLine[100] = "";
	char a1 = "", a2 = "";
	int i = 1;
	bool edited = false;
	fgets(line, 100, infile);
	fprintf(outfile, "%s", line);
	fgets(line, 100, infile); // skips the first two lines
	fprintf(outfile, "%s", line);
	while (!feof(infile)) {
		fgets(line, 100, infile);
		while (a1 != '\n' && a2 != '\n') { //tests for new line
			a1 = line[i];
			a2 = line[i-1];
			if ((a1 == ',' && a2 == ',') || (a1 == '\n' && a2 == ',')){ //tests for null data
				strcpy(editedLine, ShiftAndInsert(line, (i)));	//location = i+1
				edited = true; // notes that the line has been edited
				strcpy(line, editedLine); // sets the new line to the edited line
				i = -1; //restarts loop to test for multiple null data in the same line
			}
			i++;
		}
		if (edited) {
			fprintf(outfile, "%s", editedLine); // prints the line to the file
		//	printf("%s", editedLine);
		}
		else {
			fprintf(outfile, "%s", line); 
			//printf("%s", line);
		}
		a1 = ""; // resets all paramaters
		a2 = "";
		i = 0;
		edited = false;
	}
}
		

char * ShiftAndInsert(char line[], int location) {  //takes an array and a location and inserts a "-1" at the specified location
	int length = (strlen(line)), i = 0;
	char * tmp_line = (char *)malloc(sizeof(char) * length + 3); //reallocates memory to accomidate for the larger string
	while (length - i >= location) { // moves characters over until reaching designated insertion point
		tmp_line[length + 1 - i] = line[length - i];
		i++;
	}
	tmp_line[length + 1- i] = '0'; // inserts the 0 in the location
	while (length - i != -1) // fills in the rest of the string
	{
		tmp_line[length - i] = line[length - i];
		i++;
	}
	return tmp_line;
}

double CaloriesBurned(FitbitData fitbit[]) { // loops through the fitbit array and adds up the total calories
	double Calories = 0.0;
	int i = 0;
	while (i <= 1440) {
		Calories += fitbit[i].calories;
		i++;

	}
	return Calories;
}

double DistanceWalked(FitbitData fitbit[]) { // loops through the fitbit array and adds up the total distance 
	double TotalDistance = 0.0;
	int i = 0;
	while (i <= 1440) {
		TotalDistance += fitbit[i].distance;
		i++;
	}
	return TotalDistance;

}

int FloorsClimbed(FitbitData fitbit[]) { //calculates total flights climbed
	int Floors = 0;
	int i = 0;
	while (i <= 1440) {
		Floors += fitbit[i].floors;
		i++;
	}
	return Floors;
}

int StepsTaken(FitbitData fitbit[]) { // calculates total steps taken 
	int steps = 0, i = 0;
	while (i <= 1440) {
		steps += fitbit[i].steps;
		i++;
	}
	return steps;
}

double AvgHeartRate(FitbitData fitbit[]) { // calculates avg heart over 24 hours with valid heart rates
	double heartTotal = 0;
	int i = 0;
	int count = 0;
	while (i <= 1440) {
		if (fitbit[i].heartRate != 0) {
			heartTotal += fitbit[i].heartRate;
			count++;
			//printf("%d\n", fitbit[i].heartRate);
		}
		i++;
	}
	double avgHeart = (heartTotal / count);

	return avgHeart;
}

int maxsteps(FitbitData fitbit[]) { //calcualtes the most steps in one minute 
	int maxsteps = 0;
	int i = 0;
	while (i <= 1440){
		if (maxsteps <= fitbit[i].steps) {
			maxsteps = fitbit[i].steps;
		}
		i++;
	}
	return maxsteps;
}

BadSleep worstsleep(FitbitData fitbit[]) { //loops through the sleep files to find the worst total time 
	BadSleep tmp1 = { 0 }; //temp 
	BadSleep worst = { 0 };// the actual worst
	int i;
	for(i = 0; i <= 1440; i++){
		if (i > 1440)
			__debugbreak();
		if (fitbit[i].sleepLevel > 1) { // finds point of wake up 
			strcpy(tmp1.minuteStart, fitbit[i].minute);
			while (fitbit[i].sleepLevel > 1) { // runns only while awake
				tmp1.totalTime += fitbit[i].sleepLevel;
				i++;
			}
			strcpy(tmp1.minuteEnd, fitbit[i - 1].minute);
		}
		if (tmp1.totalTime > worst.totalTime) { //compares current to real worst time
			worst.totalTime = tmp1.totalTime;
			strcpy(worst.minuteStart, tmp1.minuteStart);
			strcpy(worst.minuteEnd, tmp1.minuteEnd);
		}
	}
	return worst;
}

void PrintResults(FILE * outfile, FILE * source, double totalCalories, double totalDistance, int totalFloors, int totalStep, double avgHeart, int maxSteps, BadSleep sleep) {
	char line[100] = "";
	
	fprintf(outfile, "Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");
	printf("Total Calories, Total Distance, Total Floors, Total Steps, Avg Heartrate, Max Steps, Sleep\n");


	

	printf("%.2lf, %.2lf, %d, %d, %.2lf, %d, %s : %s\n\n", totalCalories, totalDistance, totalFloors, totalStep, avgHeart, maxSteps, sleep.minuteStart, sleep.minuteEnd); //why are you being dumb
	fprintf(outfile, "%.2lf, %.2lf, %d, %d, %.2lf, %d, %s:%s\n\n", totalCalories, totalDistance, totalFloors, totalStep, avgHeart, maxSteps, sleep.minuteStart, sleep.minuteEnd);


	while (!feof(source)) { //prints the clensed file
		fgets(line, 100, source);
		fprintf(outfile, "%s", line);
		printf("%s", line);
	}
	printf("\n\n");
}
