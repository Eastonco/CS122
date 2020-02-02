#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper()
{
	for (int i = 0; i < 7; i++) {
		dietWeek[i].setDate("");
		dietWeek[i].setGoal(0);
		dietWeek[i].setName("");
	}
	for (int i = 0; i < 7; i++) {
		ExerciseWeek[i].setDate("");
		ExerciseWeek[i].setGoal(0);
		ExerciseWeek[i].setName("");
	}
}

FitnessAppWrapper::~FitnessAppWrapper()
{

}



void FitnessAppWrapper::editWeeklyPlan(ExercisePlan e1[])
{
	int choice = 0;
	system("cls");
	do {
		displayWeeklyPlan(ExerciseWeek);
		cout << endl << "Enter '0' if you want to exit" << endl;
		cout << "What day would you like to edit: ";
		cin >> choice;
		system("cls");
		if (choice != 0)
			editDailyPlan(e1[choice - 1]);
	} while (choice != 0);
}

void FitnessAppWrapper::editDailyPlan(ExercisePlan &e1)
{
	int choice = 0;
	string name = "";
	string date = "";
	int goal = 0;
	do {
		system("cls");
		displayDailyPlan(e1);
		cout << endl << "What would you like to edit?" << endl;
		cout << "(1) Name" << endl;
		cout << "(2) Goal" << endl;
		cout << "(3) Date" << endl;
		cout << "(4) Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			e1.editName();
			break;
		case 2:
			system("cls");
			e1.editGoal();
			break;
		case 3:
			system("cls");
			e1.editDate();
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (choice != 4);
	system("cls");

}

void FitnessAppWrapper::editWeeklyPlan(DietPlan d1[])
{
	int choice = 0;
	system("cls");
	do {
		displayWeeklyPlan(dietWeek);
		cout << endl << "Enter '0' if you want to exit" << endl;
		cout << "What day would you like to edit: ";
		cin >> choice;
		system("cls");
		if (choice != 0)
			editDailyPlan(d1[choice - 1]);
	} while (choice != 0);
}

void FitnessAppWrapper::editDailyPlan(DietPlan &d1)
{
	int choice = 0;
	string name = "";
	string date = "";
	int goal = 0;
	do {
		system("cls");
		displayDailyPlan(d1);
		cout << endl << "What would you like to edit?" << endl;
		cout << "(1) Name" << endl;
		cout << "(2) Goal" << endl;
		cout << "(3) Date" << endl;
		cout << "(4) Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			d1.editName();
			break;
		case 2:
			system("cls");
			d1.editGoal();
			break;
		case 3:
			system("cls");
			d1.editDate();
			break;
		case 4:
			break;
		default:
			break;
		}
	} while (choice != 4);
	system("cls");

}

void FitnessAppWrapper::storeDailyPlan(fstream & fileStream, ExercisePlan e1) // how to overload
{
	fileStream << e1.getName() << endl;
	fileStream << e1.getGoal() << endl;
	fileStream << e1.getDate() << endl << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(ExercisePlan e1[])
{
	exerciseOut.open("Exercise.txt");
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(exerciseOut, e1[i]);
	}
	exerciseOut.close();
}

void FitnessAppWrapper::storeDailyPlan(fstream & fileStream, DietPlan d1) // how to overload
{
	fileStream << d1.getName() << endl;
	fileStream << d1.getGoal() << endl;
	fileStream << d1.getDate() << endl << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(DietPlan d1[])
{
	dietOut.open("Diet.txt");
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(dietOut, d1[i]);
	}
	dietOut.close();
}

void FitnessAppWrapper::loadDailyPlan(fstream & fileStream, ExercisePlan & plan)
{
	string line;
	if (fileStream.is_open()) {
		if(!fileStream.eof()){
			getline(fileStream, line);
			plan.setName(line);
			getline(fileStream, line);
			plan.setGoal(stoi(line));
			getline(fileStream, line);
			plan.setDate(line);
			getline(fileStream, line);
		}
	}
	
}

void FitnessAppWrapper::loadWeeklyPlan(fstream & fileStream, ExercisePlan weeklyPlan[])
{
	string line;
	if (fileStream.is_open()) {
		for (int i = 0; i < 7; i++) {
			if (!fileStream.eof()) {
				loadDailyPlan(fileStream, weeklyPlan[i]);
			}
		}
	}

}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan e1) //how to overload
{
	cout << "Name: " << e1.getName() << endl;
	cout << "Goal: " << e1.getGoal() << endl;
	cout << "Date: " << e1.getDate() << endl << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan e1[]) // how to overload
{
	cout << "Displaying weekly Exercise Plan" << endl << endl;
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(e1[i]);
	}
}




void FitnessAppWrapper::loadDailyPlan(fstream & fileStream, DietPlan & plan)
{
	string line;
	if (fileStream.is_open()) {
		if (!fileStream.eof()) {
			getline(fileStream, line);
			plan.setName(line);
			getline(fileStream, line);
			plan.setGoal(stoi(line));
			getline(fileStream, line);
			plan.setDate(line);
			getline(fileStream, line);
		}
	}
}

void FitnessAppWrapper::loadWeeklyPlan(fstream & fileStream, DietPlan weeklyPlan[])
{
	string line;
	if (fileStream.is_open()) {
		for (int i = 0; i < 7; i++) {
			if (!fileStream.eof()) {
				loadDailyPlan(fileStream, weeklyPlan[i]);
			}
		}
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan d1) // how to overload
{
	cout << "Name: " << d1.getName() << endl;
	cout << "Goal: " << d1.getGoal() << endl;
	cout << "Date: " << d1.getDate() << endl << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan d1[]) // how to overload
{
	cout << "Displaying weekly Diet Plan" << endl << endl;
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(d1[i]);
	}

}

int FitnessAppWrapper::displayMenu()
{
	int choice = -1;
	int attempt = 0;
	do {
		if (attempt > 0) {
			cout << "Invalid input, please try again" << endl;
			attempt--;
		}
		attempt++;
		cout << "1. Load weekly diet plan from file" << endl;
		cout << "2. Load weekly exercise plan from file" << endl;
		cout << "3. Store weekly diet plan to file" << endl;
		cout << "4. Store weekly exercise plan to file" << endl;
		cout << "5. Display weekly diet plan to screen" << endl;
		cout << "6. Display weekly exercie plan to screen" << endl;
		cout << "7. Edit daily diet plan" << endl;
		cout << "8. Edit daily exercise plan" << endl;
		cout << "9. Save and Exit" << endl << endl;
		cout << "choice ";
		cin >> choice;
		system("cls");
	} while (choice <= 1 && choice >= 9);
	return choice;
}

void FitnessAppWrapper::runApp() 
{
	int choice = 0;
	do {
		choice = displayMenu();
		if (choice == 1)
		{
			dietIn.open("Diet.txt");
			loadWeeklyPlan(dietIn, dietWeek);
			dietIn.close();
		}
		if (choice == 2)
		{
			exerciseIn.open("Exercise.txt");
			loadWeeklyPlan(exerciseIn, ExerciseWeek);
			exerciseIn.close();
		}
		if (choice == 3)
		{
			storeWeeklyPlan(dietWeek);
		}
		if (choice == 4)
		{
			storeWeeklyPlan(ExerciseWeek);
		}
		if (choice == 5)
		{
			displayWeeklyPlan(dietWeek);
		}
		if (choice == 6)
		{
			displayWeeklyPlan(ExerciseWeek);
		}
		if (choice == 7)
		{
			editWeeklyPlan(dietWeek);
		}
		if (choice == 8)
		{
			editWeeklyPlan(ExerciseWeek);
		}
	} while (choice != 9);
	system("cls");
	storeWeeklyPlan(dietWeek);
	storeWeeklyPlan(ExerciseWeek);
	cout << "Goodbye" << endl;

}
