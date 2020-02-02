#include "header.h"

class Data
{
public:
	Data();
	Data(int RecordNum, int ID, string FirstName, string LastName, 
		 string Email,string Credits, string Major, string Grade);
	~Data();

	void setRecordNum(int newNum);
	void setID(int newID);
	void setFirstName(string newFirstName);
	void setLastName(string newLastName);
	void setEmail(string newEmail);
	void setCredits(string newCredits);
	void setMajor(string newMajor);
	void setGrade(string newGrade);

	void addAbsence();
	void removeAbsence();

	int getRecordNum();
	int getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	string getCredits();
	string getMajor();
	string getGrade();

	string printName();
	string mostRecentAbsence();


	int getAbsences();

private:
	int RecordNum;
	int ID;
	Name name;
	string email;
	string credits;
	string major;
	string grade;

	int numAbsence;
	stack<string> absenceDate;
};

