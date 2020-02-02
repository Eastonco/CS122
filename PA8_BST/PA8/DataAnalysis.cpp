#include "DataAnalysis.h"


DataAnalysis::DataAnalysis()
{
}

DataAnalysis::~DataAnalysis()
{
}

void DataAnalysis::runAnalysis()
{
	fillTrees();
	printTrees();

}



void DataAnalysis::fillTrees()
{
	mCsvStream.open("data.csv");
	bool success = mCsvStream.is_open();
	char garbadge[100] = "";
	TransactionNode newTransaction;
	mCsvStream.getline(garbadge, 100);
	char line[100] = "";
	while (!mCsvStream.eof()) {
		mCsvStream.getline(line, 100, ',');
		newTransaction.setUnits(atoi(line));
		mCsvStream.getline(line, 100, ',');
		newTransaction.setmData(line);
		mCsvStream.getline(line, 100, '\n');
		if (!strcmp(line, "Purchased")) {
			mTreePurchased.insert(newTransaction.getmData(), newTransaction.getUnits());
		}
		else {
			mTreeSold.insert(newTransaction.getmData(), newTransaction.getUnits());
		}
	}
}

void DataAnalysis::printTrees()
{
	cout << "Purchased Tree" << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl << endl << "Sold Tree" << endl;
	mTreeSold.inOrderTraversal();
	cout << endl << endl << "Sold the most: ";
	mTreeSold.findLargest();
	cout << endl << "Sold the least: ";
	mTreeSold.findSmallest();
	cout << endl << "Purchased the most: ";
	mTreePurchased.findLargest();
	cout << endl << "Purchased the least: ";
	mTreePurchased.findSmallest();
	cout << endl << endl;
}
