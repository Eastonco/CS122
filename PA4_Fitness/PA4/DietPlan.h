#include "Header.h"

#ifndef DIETPLAN
#define DIETPLAN

class DietPlan
{
public:
	DietPlan();
	~DietPlan();
	DietPlan(DietPlan &rhs);

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
	int mgoalCalories;
	string mname;
	string mdate;
};

#endif // !DIETPLAN
