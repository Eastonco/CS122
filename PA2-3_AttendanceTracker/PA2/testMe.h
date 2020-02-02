#ifndef TEST_ME
#define TEST_ME

#include "Header.h"

typedef struct nodetest {
	int num;
	struct nodetest *pNext;
	struct nodetest *pPrev;
}NodeTest;

void insertTest(void);
void deleteTest(void);
void shuffleTest(void);
NodeTest * makeNodeTest(int num);
bool addToListNodeTest(NodeTest **pList, int num);
int numInListNodeTest(NodeTest *pList);
#endif
