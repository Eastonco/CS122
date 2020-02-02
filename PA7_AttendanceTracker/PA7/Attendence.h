#include "List.h"

class Attendence
{
public:
	Attendence();
	~Attendence();

	void runapp();
	int printmenu();
	void importCourseList(bool MasterList);
	void storeMasterList();
	void printStudent(Data myStudent);
	void markAbsences();
	void generateReport();

private:
	List<Data> Students;

	void everyStudnetReport();
	void thresholdReport();
};

Attendence::Attendence()
{
}

Attendence::~Attendence()
{
}

void Attendence::runapp()
{
	int choice = 0;
	do {
		system("cls");
		choice = printmenu();
		switch (choice)
		{
		case 1:
			importCourseList(false);
			break;
		case 2:
			importCourseList(true);
			break;
		case 3:
			storeMasterList();
			break;
		case 4:
			markAbsences();
			break;
		case 5:
			generateReport();
			break;
		case 6:
			storeMasterList();
			break;
		}
	} while (choice != 6);
	system("cls");
	cout << "Goodbye" << endl;
}

int Attendence::printmenu()
{
	int choice = 0, attempt = 0;
	do {
		system("cls");
		if (attempt != 0) {
			attempt--;
			cout << "ERROR: Invalid user input" << endl << endl;
		}
		attempt++;
		cout << "ATTENDANCE TRACKER" << endl << endl;
		cout << "[1] Import course list" << endl;
		cout << "[2] Load master list" << endl;
		cout << "[3] Store master list" << endl;
		cout << "[4] Mark absences" << endl;
		cout << "[5] Generate report" << endl;
		cout << "[6] Exit" << endl << endl;
		cout << "choice: ";
		cin >> choice;
	} while (choice != 1 && choice != 2 && choice != 3 &&
			 choice != 4 && choice != 5 && choice != 6);
	return choice;
}

void Attendence::importCourseList(bool MasterList)
{
	fstream infile;
	if (MasterList)
		infile.open("MasterList.csv");
	else
		infile.open("MyClass.csv");
	bool success = infile.is_open();
	//string line = "";
	char line[100] = "";
	Data newstudent;
	infile.getline(line, 100);
	while (!infile.eof()) {
		infile.getline(line, 100, ',');
		newstudent.setRecordNum(atoi(line));
		infile.getline(line, 100, ',');
		newstudent.setID(atoi(line));
		infile.getline(line, 100, '\"');
		infile.getline(line, 100, ',');
		newstudent.setLastName(line);
		infile.getline(line, 100, '\"');
		newstudent.setFirstName(line);
		infile.getline(line, 100, ',');
		infile.getline(line, 100, ',');
		newstudent.setEmail(line);
		infile.getline(line, 100, ',');
		newstudent.setCredits(line);
		infile.getline(line, 100, ',');
		newstudent.setMajor(line);
		infile.getline(line, 100, '\n');
		newstudent.setGrade(line);
		Students.InsertAtFront(newstudent);
	}
	infile.close();
	system("cls");
	cout << "Course list imported successfully" << endl << endl;
	system("pause");
}

void Attendence::storeMasterList()
{
	fstream outfile;
	outfile.open("MasterList.csv");
	outfile << "                 ***MASTER LIST***";
	Node<Data> * pMem = Students.getHeadPtr();
	while (pMem != nullptr) {
		outfile << endl << pMem->getData()->getRecordNum() << "," << pMem->getData()->getID() << ",\"";
		outfile << pMem->getData()->getLastName() << "," << pMem->getData()->getFirstName() << "\",";
		outfile << pMem->getData()->getEmail() << "," << pMem->getData()->getCredits() << ",";
		outfile << pMem->getData()->getMajor() << "," << pMem->getData()->getGrade();
		pMem = pMem->getNextPtr();
	}
	outfile.close();
	system("cls");
	cout << "MASTER LIST SAVED" << endl << endl;
	system("pause");
}

void Attendence::printStudent(Data myStudent)
{
	cout << "Name: " << myStudent.getFirstName() << " " << myStudent.getLastName() << endl;
	cout << "ID: " << myStudent.getID() << endl;
	cout << "Email: " << myStudent.getEmail() << endl;
	cout << "Credits: " << myStudent.getCredits() << endl;
	cout << "Major: " << myStudent.getMajor() << endl;
	cout << "Grade: " << myStudent.getGrade() << endl;
}

void Attendence::markAbsences()
{
	system("cls");
	char absent = 'n';
	Node<Data> * pMem = Students.getHeadPtr();
	while (pMem != nullptr) {
		printStudent(*(pMem->getData()));
		cout << endl << "Absent(y/n): ";
		cin >> absent;
		if (absent == 'y') {
			pMem->getData()->addAbsence();
		}
		pMem = pMem->getNextPtr();
		system("cls");
	}
}

void Attendence::generateReport()
{
	system("cls");
	int choice = 0;
	do {
		cout << "GENERATE REPORT" << endl;
		cout << "[1] Generate report for all students" << endl;
		cout << "[2] Generate report from absence threshold" << endl;
		cout << "choice: ";
		cin >> choice;
	} while (choice != 1 && choice != 2);
	if (choice == 1) {
		everyStudnetReport();
	}
	else{
		thresholdReport();
	}
}

void Attendence::everyStudnetReport()
{
	Node<Data> * pMem = Students.getHeadPtr();
	fstream outfile;
	outfile.open("TotalReport.txt");
	outfile << "TOTAL STUDENT REPORT" << endl;
	outfile << "Name | most recent absence" << endl << endl;
	while (pMem != nullptr) {
		outfile << pMem->getData()->printName() << " | " << pMem->getData()->mostRecentAbsence() << endl;
		pMem = pMem->getNextPtr();
	}
	outfile.close();
}

void Attendence::thresholdReport()
{
	Node<Data> *pMem = Students.getHeadPtr();
	fstream outfile;

	int threshold = 0;
	system("cls");
	cout << "Absence threshold: ";
	cin >> threshold;

	outfile.open("ThresholdReport.txt");
	outfile << "THRESHOLD REPORT ABOVE " << threshold << " ABSENCES" << endl;
	outfile << "Name || Total absences" << endl << endl;
	while (pMem != nullptr) {
		if (pMem->getData()->getAbsences() >= threshold)
			outfile << pMem->getData()->printName() << " | " << pMem->getData()->getAbsences();
		pMem = pMem->getNextPtr();
	}
	outfile.close();
}
