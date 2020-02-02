#include "Header.h"
#include "DietPlan.h"


DietPlan::DietPlan()
{
	mgoalCalories = 0;
	mname = '\0';
	mdate = '\0';
}

DietPlan::~DietPlan()
{
}

DietPlan::DietPlan(DietPlan & rhs)
{
	mgoalCalories = rhs.getGoal();
	mname = rhs.getName();
	mdate = rhs.getDate();
}

int DietPlan::getGoal()
{
	return mgoalCalories;
}

string DietPlan::getName()
{
	return mname;
}

string DietPlan::getDate()
{
	return mdate;
}

void DietPlan::setGoal(int newGoal)
{
	mgoalCalories = newGoal;
}

void DietPlan::setName(string newName)
{
	mname = newName;
}

void DietPlan::setDate(string newDate)
{
	mdate = newDate;
}

void DietPlan::editGoal()
{
	int goal;
	cout << "current goal: " << getGoal() << "calories" << endl;
	cout << "New goal: ";
	cin >> goal;
	cout << endl << "Goal set to " << goal << " calories" << endl;
	setGoal(goal);

}

void DietPlan::editName()
{
	string name;
	cout << "current name: " << getName() << endl;
	cout << "New name: ";
	cin >> name;
	cout << std::endl << "Name set to: " << name << endl;
	setName(name);
}

void DietPlan::editDate()
{
	string date;
	cout << "current date: " << getDate() << endl;
	cout << "New date: ";
	cin >> date;
	cout << std::endl << "Date set to: " << date << endl;
	setDate(date);
}

