#include "Data.h"


int Data::getCustomerNumber()
{
	return customerNumber;
}

int Data::getTotalTime()
{
	return totalTime;
}

Data::Data(int cNum, int tTime, int line)
{
	customerNumber = cNum;
	if (line == 1)
		serviceTime = rand() % 5 + 1;
	if (line == 2)
		serviceTime = rand() % 6 + 3;
	totalTime = serviceTime + tTime;
}

Data::~Data()
{
}

void Data::setServiceTime(int num) {
	serviceTime = num;
}

int Data::getServiceTime() {
	return serviceTime;
}


Data::Data(Data const & newData)
{
	this->customerNumber = newData.customerNumber;
	this->serviceTime = newData.serviceTime;
	this->totalTime = newData.totalTime;
}