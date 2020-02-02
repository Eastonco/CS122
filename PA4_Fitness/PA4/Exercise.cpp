#include "Header.h"
#include "ExercisePlan.h"

ExercisePlan::ExercisePlan()
{
}

ExercisePlan::~ExercisePlan()
{
}

ExercisePlan::ExercisePlan(ExercisePlan & rhs)
{
	mgoalSteps = rhs.getGoal();
	mname = rhs.getName();
	mdate = rhs.getDate();
}

int ExercisePlan::getGoal()
{
	return mgoalSteps;
}

string ExercisePlan::getName()
{
	return mname;
}

string ExercisePlan::getDate()
{
	return mdate;
}
void ExercisePlan::setGoal(int newGoal)
{
	mgoalSteps = newGoal;
}

void ExercisePlan::setName(string newName)
{
	mname = newName;
}

void ExercisePlan::setDate(string newDate)
{
	mdate = newDate;
}

void ExercisePlan::editGoal()
{
	int goal;
	cout << "current Goal: " << getGoal() << "calories" << endl;
	cout << "New goal: ";
	cin >> goal;
	cout << endl << "Goal set to " << goal << " calories" << endl;
	setGoal(goal);
}


void ExercisePlan::editName()
{
	string name;
	cout << "current name: " << getName() << endl;
	cout << "New name: ";
	cin >> name;
	cout << endl << "Name set to: " << name << endl;
	setName(name);
}

void ExercisePlan::editDate()
{
	string date;
	cout << "current date: " << getDate() << endl;
	cout << "New date: ";
	cin >> date;
	cout << endl << "Date set to: " << date << endl;
	setDate(date);
}
