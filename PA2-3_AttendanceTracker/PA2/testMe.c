#include "testMe.h"

void insertTest() {
	Node *pList = NULL;
	Record newRecord = { 0 };
	strcpy(newRecord.artist, "Perry,Katy");
	strcpy(newRecord.album, "Witness");
	strcpy(newRecord.title, "Chained to the Rythm");
	strcpy(newRecord.genre, "pop");
	newRecord.length.minutes = 4;
	newRecord.length.seconds = 36;
	newRecord.timesPlayed = -1;
	newRecord.rating = 6;
	if (newRecord.timesPlayed < 0)
		printf("ERROR: num played < 0\n");
	else if (newRecord.rating > 5 && newRecord.rating < 0)
		printf("ERROR: rating is out of range [0,5]\n");
	else
		printf("SUCCESS! Record looks good!\n");
	addToList(&pList, newRecord);
	if (pList == NULL)
		printf("ERROR: record not inserted\n");
	else
		printf("SUCCESS! record inserted successfully\n");
	return;
}

void deleteTest() {
	Node *pList = NULL;
	Record newRecord = { 0 };
	strcpy(newRecord.artist, "Perry,Katy");
	strcpy(newRecord.album, "Witness");
	strcpy(newRecord.title, "Chained to the Rythm");
	strcpy(newRecord.genre, "pop");
	newRecord.length.minutes = 4;
	newRecord.length.seconds = 36;
	newRecord.timesPlayed = 4;
	newRecord.rating = 5;

	addToList(&pList, newRecord);
	Node * pMem = pList;
	pList->pNext = pList;
	free(pMem);
	pMem = NULL;
	pList = NULL;
	

	if (pList != NULL)
		printf("ERROR: pList != NULL\n");
	if (pMem != NULL)
		printf("ERROR: memory not released\n");
	return;
}

void shuffleTest() {
	NodeTest *pList = NULL;
	addToListNodeTest(&pList, 1);
	addToListNodeTest(&pList, 2);
	addToListNodeTest(&pList, 3);

	NodeTest *pCur = NULL;

	srand(time(NULL));
	int order[3] = { 3,1,2 };
	pCur = pList;
	for (int i = 0; i < numInListNodeTest(pList); i++) {
		while (pCur->num != order[i]) {
			pCur = pCur->pNext;
		}
		printf("%d, ", pCur->num);
		pCur = pList;

	}
	printf("\nExpected result: 3, 1, 2, ");


}

NodeTest * makeNodeTest(int num) { // Creates a new node
	NodeTest * newNode = NULL;
	newNode = (NodeTest *)malloc(sizeof(NodeTest)); // allocates data for a new node
	newNode->num = num;
	newNode->pNext = NULL; // initializes variables to NULL
	newNode->pPrev = NULL;
	return newNode; // returns new node
}

bool addToListNodeTest(NodeTest **pList, int num) { //adds a new Record to linked list
	bool success = false;
	NodeTest * pMem = NULL, *pCur = *pList, *pPrev = NULL;
	pMem = makeNodeTest(num); // calls makeNode() to make new node of newData
	if (pMem != NULL) {
		success = true; // shows success if allocation was sucessful
		if (*pList == NULL) //empty list
			*pList = pMem;
		else {
			while (pCur != NULL) { // loops to end of linked list
				pPrev = pCur;
				pCur = pCur->pNext;
			}
			if (pPrev != NULL) { // at the end of the list
				pPrev->pNext = pMem;
				pMem->pNext = pCur;
				pMem->pPrev = pPrev;
			}
			else {
				pMem->pNext = pCur; // places at the start of the list
				*pList = pMem;
			}
		}
	}
}

int numInListNodeTest(NodeTest *pList) {
	int count = 1;
	NodeTest * pCur = pList;
	while (pCur != NULL && pCur->pNext != NULL) {
		count++;
		pCur = pCur->pNext;
	}
	return count;
}