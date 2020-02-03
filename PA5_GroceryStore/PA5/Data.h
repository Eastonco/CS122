#include "Header.h"

class Data
{
public:
	Data(int cNum, int tTime, int line);
	Data(Data const &newData);
	~Data();
	int getCustomerNumber();
	int getTotalTime();
	void setServiceTime(int num);
	int getServiceTime();

private:
	int customerNumber;
	int serviceTime;
	int totalTime;
};
