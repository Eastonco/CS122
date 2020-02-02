#ifndef PA2HEAD
#define PA2HEAD

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

typedef struct duration {
	int minutes;
	int seconds;
}Duration;

typedef struct record {
	char artist[50];
	char album[50];
	char title[50];
	char genre[20];
	Duration length;
	int timesPlayed;
	int rating;
}Record;

typedef struct node {
	Record data;
	struct node *pNext;
	struct node *pPrev;
}Node;


int displayMenu(void);
void saveAndExit(Node *pList, FILE *outfile);
bool loadMusic(Node **pList, FILE *infile);
bool addToList(Node **pList, Record newData);
void addToListNode(Node **pList, Node *pNewMem);
void displayMusic(Node *pList);
char * lowercase(char * mystr);
Node * makeNode(Record newData);
void editRecord(Node *pList);
void rateSong(Node *pList);
void playMusic(Node *pList);
void deleteSong(Node *pList);
Node * insertSong(Node *pList);
Node * sortSongs(Node *pList);
int numInList(Node *pList);
void shuffle(Node *pList);
bool isInArray(int list[], int target);
#endif
