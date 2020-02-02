#include "Node.h"

class TransactionNode : public Node
{
public:
	TransactionNode(string newData, int numUnits);
	~TransactionNode();

	void printData();

	void setUnits(int numUnits);
	int getUnits();

private:
	int mUnits;
};

