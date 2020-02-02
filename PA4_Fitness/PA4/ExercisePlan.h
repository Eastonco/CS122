#include "Header.h"

#ifndef EXERCISEPLAN
#define EXERCISEPLAN

class ExercisePlan
{
public:
	ExercisePlan();
	~ExercisePlan();
	ExercisePlan(ExercisePlan &rhs);

	int getGoal();
	string getName();
	string getDate();
	void setGoal(int newGoal);
	void setName(string newName);
	void setDate(string newDate);
	void editGoal();
	void editName();
	void editDate();

private:
	int mgoalSteps;
	string mname;
	string mdate;
};
#endif // !EXERCISEPLAN
