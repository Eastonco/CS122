#include "Header.h"
#include "DietPlan.h"
#include "ExercisePlan.h"

#ifndef FITNESSAPP
#define FITNESSAPP

class FitnessAppWrapper
{
public:
	FitnessAppWrapper();
	~FitnessAppWrapper();
	FitnessAppWrapper(FitnessAppWrapper &rhs);

	void runApp();

	void loadDailyPlan(fstream &fileStream, ExercisePlan &plan);
	void loadWeeklyPlan(fstream &fileStream, ExercisePlan weeklyPlan[]);
	void displayDailyPlan(ExercisePlan e1);
	void displayWeeklyPlan(ExercisePlan e1[]);
	void storeDailyPlan(fstream & fileStream, ExercisePlan e1);
	void storeWeeklyPlan(ExercisePlan e1[]);
	void editDailyPlan(ExercisePlan &e1);
	void editWeeklyPlan(ExercisePlan e1[]);



	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void displayDailyPlan(DietPlan d1);
	void displayWeeklyPlan(DietPlan d1[]);
	void storeDailyPlan(fstream & fileStream, DietPlan d1);
	void storeWeeklyPlan(DietPlan d1[]);
	void editDailyPlan(DietPlan &d1);
	void editWeeklyPlan(DietPlan d1[]);

	int displayMenu();

private:
	fstream dietIn;
	fstream dietOut;
	fstream exerciseIn;
	fstream exerciseOut;
	DietPlan dietWeek[7];
	ExercisePlan ExerciseWeek[7];
};


#endif // FITNESSAPP
