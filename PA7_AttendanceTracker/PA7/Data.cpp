#include "Data.h"

void Data::setGrade(string newGrade)
{
	this->grade = newGrade;
}

void Data::addAbsence()
{
	numAbsence++;

	ostringstream str1;
	time_t t = std::time(0);   // get time now
    tm* now = std::localtime(&t);
	str1 << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday;

	string date = str1.str();
	cout << date;
	absenceDate.push(date);
}

void Data::removeAbsence()
{
	numAbsence--;
}

int Data::getRecordNum()
{
	return this->RecordNum;
}

int Data::getID()
{
	return this->ID;
}

string Data::getFirstName()
{
	return this->name.first;
}

string Data::getLastName()
{
	return this->name.last;
}

string Data::getEmail()
{
	return this->email;
}

string Data::getCredits()
{
	return this->credits;
}

string Data::getMajor()
{
	return this->major;
}

string Data::getGrade()
{
	return this->grade;
}

string Data::printName()
{
	ostringstream str1;

	str1 << this->getFirstName() << " " << this->getLastName();

	string name = str1.str();
	return name;
}

string Data::mostRecentAbsence()
{
	string date = "";
	if (!absenceDate.empty())
		date = absenceDate.top();
	else
		date = "No Absences";
	return date;
}

int Data::getAbsences()
{
	return absenceDate.size();
}

Data::Data()
{
	RecordNum = 0;
	ID = 0;
	name.first = "";
	name.last = "";
	email = "";
	credits = "";
	major = "";
	grade = "";
}

Data::Data(int RecordNum, int ID, string FirstName, string LastName, string Email, string Credits, string Major, string Grade)
{
	this->setRecordNum(RecordNum);
	this->setID(ID);
	this->setFirstName(FirstName);
	this->setLastName(LastName);
	this->setEmail(Email);
	this->setCredits(Credits);
	this->setMajor(Major);
	this->setGrade(Grade);
	this->numAbsence = 0;
}

Data::~Data()
{
}

void Data::setRecordNum(int newNum)
{
	this->RecordNum = newNum;
}

void Data::setID(int newID)
{
	this->ID = newID;
}

void Data::setFirstName(string newFirstName)
{
	this->name.first = newFirstName;
}

void Data::setLastName(string newLastName)
{
	this->name.last = newLastName;
}

void Data::setEmail(string newEmail)
{
	this->email = newEmail;
}

void Data::setCredits(string newCredits)
{
	this->credits = newCredits;
}

void Data::setMajor(string newMajor)
{
	this->major = newMajor;
}
