#include "Header.h"

int displayMenu(void) {  // displays the main menu
	int choice = 0, attempt = 0;
	do { //loops for valid input
		++attempt;
		system("cls");
		if (attempt > 1) {
			getchar(); // cleans up any garbadge values
			puts("> Invalid user input, please try again");
		}
		printf("(1)  load (only load once to prevent duplicates)\n");
		printf("(2)  store\n");
		printf("(3)  display\n");
		printf("(4)  insert\n");
		printf("(5)  delete\n");
		printf("(6)  edit\n");
		printf("(7)  sort\n");
		printf("(8)  rate\n");
		printf("(9)  play\n");
		printf("(10) shuffle\n");
		printf("(11) exit\n\n");
		printf("input (1-11): ");
		scanf("%d", &choice);

	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 6 && choice != 7 && choice != 8 && choice != 9 && choice != 10 && choice != 11);
	system("cls");
	return choice; //returns choice to main 
}


void deleteSong(Node *pList) {
	system("cls");

	Node * pCur = NULL, *pPrev = NULL, *pNext = NULL;
	bool success = false;
	pCur = pList;
	pNext = pCur->pNext;

	char searchFor[50] = "";
	getchar();
	printf("Enter the song you would like to delete: ");
	scanf("%[^\n]s", &searchFor);
	strcpy(&searchFor, lowercase(&searchFor));
	while (pCur != NULL && success !=true) {
		if (strcmp(searchFor, lowercase(pCur->data.title)) == 0) {
			if (pPrev != NULL) {
				pPrev->pNext = pNext;
			}
			if (pNext != NULL){
				pNext->pPrev = pPrev;
			}
			free(pCur);
			success = true;
			break;
		}
		pPrev = pCur;
		pCur = pCur->pNext;
		pNext = pCur->pNext;

	}
	if (success == true) {
		printf("\nDelted \"%s\" Successfully", &searchFor);
		Sleep(2000);
	}
	else {
		printf("\nFailed to delte song");
		Sleep(2000);
	}

}


void saveAndExit(Node *pList, FILE *outfile) { //saves the current linked list to the file
	char * pPosition= NULL;
	while (pList != NULL) { // loops until end of linked list
		pPosition = strchr(pList->data.artist, ','); //tests if the artist is a multi name artist e.g. Taylor Swift
		if (pPosition != NULL) {
			char name[50] = { '\0' };
			strcpy(name, pList->data.artist);
			char * firstName = strtok(name, ",");
			char * lastName = strtok(NULL, "\0");
			fprintf(outfile, "\"%s, %s\",", lastName, firstName); //prints the name in correct format
		}
		else {
			fprintf(outfile, "%s,", pList->data.artist); // prints single name artists e.g. Drake
		}
		fprintf(outfile, "%s,", pList->data.album); // prints the rest of the data
		fprintf(outfile, "%s,", pList->data.title);
		fprintf(outfile, "%s,", pList->data.genre);
		fprintf(outfile, "%d:%d,", pList->data.length.minutes, pList->data.length.seconds);
		fprintf(outfile, "%d,", pList->data.timesPlayed);
		fprintf(outfile, "%d\n", pList->data.rating);

		pList = pList->pNext;// moves to next pointer
	}
	fprintf(outfile, "\n"); //prints a double \n because I cant i get issues finding EOF with a single \n idk why
	printf("Saved Successfully\n\n");
	Sleep(1000);
}

Node * makeNode(Record newData) { // Creates a new node
	Node * newNode = NULL;
	newNode = (Node *)malloc(sizeof(Node)); // allocates data for a new node
	newNode->pNext = NULL; // initializes variables to NULL
	newNode->pPrev = NULL;
	memcpy(&newNode->data, &newData, sizeof(Record)); // copies data from new Record to node
	return newNode; // returns new node
}
void addToListNode(Node **pList, Node *pNewMem) {
	Node * pMem = NULL, *pCur = *pList, *pPrev = NULL;
	pMem = pNewMem;
 	pMem->pNext = NULL;
	pMem->pPrev = NULL;
	if (pMem != NULL) {
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

bool addToList(Node **pList, Record newData) { //adds a new Record to linked list
	bool success = false;
	Node * pMem = NULL, *pCur = *pList, *pPrev = NULL;
	pMem = makeNode(newData); // calls makeNode() to make new node of newData
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

void playMusic(Node *pList) {
	system("cls");

	char searchFor[50] = ""; //target artist
	char tmpName[50] = "";// multiname artist tmp used for comparing 
	bool match = false;// used for showing if artist match
	bool noMatches = true; // test is no matches in entire list
	bool playing = false;
	getchar(); // grabs any garbadge values
	printf("Enter the name of the song: ");
	scanf("%[^\n]s", &searchFor); //reads in target artist
	strcpy(&searchFor, lowercase(&searchFor));
	system("cls");
	while (pList != NULL) { // loops until end of list
		strcpy(&tmpName, lowercase(pList->data.title));
		if (strcmp(tmpName, searchFor) == 0) { // compares target and tmp artist
			noMatches = false;
			playing = true;
		}
		if (playing == true) { // if record artist match, print rest of data
			system("cls");
			printf("Artist: %s\n", pList->data.artist);
			printf("Album: %s\n", pList->data.album);
			printf("Song Title: %s\n", pList->data.title);
			printf("Genre: %s\n", pList->data.genre);
			printf("Length: %d:%d\n", pList->data.length.minutes, pList->data.length.seconds);
			printf("Times Played: %d\n", pList->data.timesPlayed);
			printf("Rating: %d\n", pList->data.rating);
			Sleep(2000);
			system("cls");
		}
		pList = pList->pNext; // go to next record
	}
	if (noMatches == true) { //if no matches are found, prints this message
		printf("No matches found\n");
		Sleep(2000);
	}

}

bool isInArray(int list[], int target) {
	int i = 0;
	while (list[i] != NULL) {
		if (list[i] == target)
			return true;
		i++;
	}
	return false;
}

void shuffle(Node *pList) {
	Node *pCur = NULL;
	pCur = pList;
	srand(time(NULL));
	int order[100];
	int num = 0;
	for (int i = 0; i < numInList(pList); i++) {
		do {
			num = rand() % numInList(pList);
		} while (isInArray(order, num));
		order[i] = num;
	}
	printf("Shuffleing");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	int current = 0;
	for (int i = 0; i < numInList(pList); i++) {
		while (current != order[i]) {
			pCur = pCur->pNext;
			current++;
		}
		system("cls");
		printf("Artist: %s\n", pCur->data.artist);
		printf("Album: %s\n", pCur->data.album);
		printf("Song Title: %s\n", pCur->data.title);
		printf("Genre: %s\n", pCur->data.genre);
		printf("Length: %d:%d\n", pCur->data.length.minutes, pCur->data.length.seconds);
		printf("Times Played: %d\n", pCur->data.timesPlayed);
		printf("Rating: %d\n", pCur->data.rating);
		Sleep(2000);
		system("cls");
		current = 0;
		pCur = pList;
	}
	


	system("cls");
	printf("Shuffle Successful!\n");
	Sleep(2000);

}


Node * insertSong(Node **pList) {
	system("cls");

	Record mySong = { 0 };
	char inData[50] = "";
	int i = 0;
	while (i < 7) {
		printf("Create a new Record:\n\n");
		switch (i)
		{
		case 0:
			getchar();
			printf("Artist: ");
			scanf("%[^\n]s", &inData);
			strcpy(mySong.artist, inData);
			break;
		case 1:
			getchar();
			printf("Album: ");
			scanf("%[^\n]s", &inData);
			strcpy(mySong.album, inData);
			break;
		case 2:
			getchar();
			printf("Song Title: ");
			scanf("%[^\n]s", &inData);
			strcpy(mySong.title, inData);
			break;
		case 3:
			getchar();
			printf("Genre: ");
			scanf("%[^\n]s", &inData);
			strcpy(mySong.genre, inData);
			break;
		case 4:
			getchar();
			printf("Length: ");
			scanf("%[^\n]s", &inData);
			int minute = atoi(strtok(inData, ":"));
			int second = atoi(strtok(NULL, "\n"));
			mySong.length.minutes = minute;
			mySong.length.seconds = second;
			break;
		case 5:
			do {
				getchar();
				printf("Times Played: ");
				scanf("%[^\n]s", &inData);
				mySong.timesPlayed = atoi(inData);
			} while (mySong.timesPlayed < 0);
			break;
		case 6:
			do {
				getchar();
				printf("Rating: ");
				scanf("%[^\n]s", &inData);
				mySong.rating = atoi(inData);
			} while (mySong.rating != 1 && mySong.rating != 2 && mySong.rating != 3 && mySong.rating != 4 && mySong.rating != 5);
			break;
		}
		i++;
		system("cls");
	}
	Node * pMem = makeNode(mySong);
	(*pList)->pPrev = pMem;
	pMem->pNext = pList;

	return pMem;

}

int numInList(Node *pList) {
	int count = 1;
	Node * pCur = pList;
	while (pCur != NULL && pCur->pNext != NULL) {
		count++;
		pCur = pCur->pNext;
	}
	return count;
}

Node * sortSongs(Node *pList) { //Sort the linked list according to artist, album title, rating, or times played. -- returns a new head pointer to sorted list
	int choice = 0, numChanges = 0;
	Node * pCur = NULL, *pPrev = NULL, *pMin = NULL, *pNext = NULL;
	Node * pNewList = NULL;
	Node *pTmp = pList;
	do { //menu 
		system("cls");
		printf("How would you like to sort your songs?\n");
		printf("(1) By Artist (A-Z)\n");
		printf("(2) By Album title (A-Z)\n");
		printf("(3) By Rating (1-5)\n");
		printf("(4) By times played (most-least)\n");
		printf("Choice: ");
		getchar();
		scanf("%d", &choice);
	} while (choice != 1 && choice != 2 && choice != 3 && choice != 4);
	
	int count = numInList(pList);

	switch (choice)
	{
	case 1: //sorting acording to artist
		for (int i = 0; i < count ; i++) {
			pCur = pTmp;
			pMin = pTmp;
			pNext = pCur->pNext;
			while (pCur != NULL) { //loops to find min arist starting at 'A'
				if (strcmp(pMin->data.artist, pCur->data.artist) > 0) 
					pMin = pCur;
				pPrev = pCur;
				pCur = pCur->pNext;
				if(pCur != NULL)
					pNext = pCur->pNext;
			}
			pCur = pMin; 
			//connects the break in the linked list
			if(pMin->pPrev != NULL) 
				pPrev = pMin->pPrev;
			else {
				pPrev = pMin->pNext;
			}

			if (pMin->pNext != NULL)
				pNext = pMin->pNext;
			if (pPrev != NULL)
				pPrev->pNext = pNext;
			if(pNext != NULL)
				pNext->pPrev = pPrev;
			addToListNode(&pNewList, pMin);
			if (pNext == pPrev) {
				addToListNode(&pNewList, pNext);
				break;
			}
		}
		system("cls");
		printf("Sorted according to artist (A-Z)\n");
		Sleep(2000);
		return pNewList;
	case 2:
		for (int i = 0; i < count; i++) {
			if (pTmp != pMin)
				pCur = pTmp;
			pMin = pCur;
			pNext = pCur->pNext;
			while (pCur != NULL) {
				if (strcmp(pMin->data.album, pCur->data.album) > 0)
					pMin = pCur;
				pPrev = pCur;
				pCur = pCur->pNext;
				if (pCur != NULL)
					pNext = pCur->pNext;
			}
			pCur = pMin;
			if (pMin->pPrev != NULL)
				pPrev = pMin->pPrev;
			else {
				pPrev = NULL;
			}
			if (pMin->pNext != NULL)
				pNext = pMin->pNext;
			if (pPrev != NULL)
				pPrev->pNext = pNext;
			if (pNext != NULL)
				pNext->pPrev = pPrev;
			if (pTmp == pMin && pTmp->pNext != NULL) {
				pTmp = pTmp->pNext;
				pCur = pTmp;
			}
			addToListNode(&pNewList, pMin);
			if (pNext == pPrev) {
				if(pNext != NULL)
					addToListNode(&pNewList, pNext);
				break;
			}
		}
		system("cls");
		printf("Sorted according to album (A-Z)\n");
		Sleep(2000);
		return pNewList;
	case 3:
		for (int i = 0; i < count; i++) {
			if (pTmp != pMin)
				pCur = pTmp;
			pMin = pCur;
			pNext = pCur->pNext;
			while (pCur != NULL) {
				if (pMin->data.rating > pCur->data.rating)
					pMin = pCur;
				pPrev = pCur;
				pCur = pCur->pNext;
				if (pCur != NULL)
					pNext = pCur->pNext;
			}
			pCur = pMin;
			if (pMin->pPrev != NULL)
				pPrev = pMin->pPrev;
			else {
				pPrev = NULL;
			}
			if (pMin->pNext != NULL)
				pNext = pMin->pNext;
			if (pPrev != NULL)
				pPrev->pNext = pNext;
			if (pNext != NULL)
				pNext->pPrev = pPrev;
			if (pTmp == pMin && pTmp->pNext != NULL) {
				pTmp = pTmp->pNext;
				pCur = pTmp;
			}
			addToListNode(&pNewList, pMin);
			if (pNext == pPrev) {
				if (pNext != NULL)
					addToListNode(&pNewList, pNext);
				break;
			}
		}
		system("cls");
		printf("Sorted according to rating (1-5)\n");
		Sleep(2000);
		return pNewList;
	case 4:
		for (int i = 0; i < count; i++) {
			if (pTmp != pMin)
				pCur = pTmp;
			pMin = pCur;
			pNext = pCur->pNext;
			while (pCur != NULL) {
				if (pMin->data.timesPlayed > pCur->data.timesPlayed)
					pMin = pCur;
				pPrev = pCur;
				pCur = pCur->pNext;
				if (pCur != NULL)
					pNext = pCur->pNext;
			}
			pCur = pMin;
			if (pMin->pPrev != NULL)
				pPrev = pMin->pPrev;
			else {
				pPrev = NULL;
			}
			if (pMin->pNext != NULL)
				pNext = pMin->pNext;
			if (pPrev != NULL)
				pPrev->pNext = pNext;
			if (pNext != NULL)
				pNext->pPrev = pPrev;
			if (pTmp == pMin && pTmp->pNext != NULL) {
				pTmp = pTmp->pNext;
				pCur = pTmp;
			}
			addToListNode(&pNewList, pMin);
			if (pNext == pPrev) {
				if (pNext != NULL)
					addToListNode(&pNewList, pNext);
				break;
			}
		}
		system("cls");
		printf("Sorted according to times played (most-least)\n");
		Sleep(2000);
		return pNewList;
	}
	return;
}

void displayMusic(Node *pList) { // passes in a linked list and displays all Records or specific artist
	system("cls");

	int choice = 0, attempt = 0;
	do { //loops for valid input 
		++attempt;
		system("cls");
		if (attempt > 1) {
			getchar(); // cleans up any garbadge values
			puts("> Invalid user input, please try again");
		}
		puts("(1) Print all records");
		puts("(2) Print all records that match artist");
		printf("Choice: ");
		scanf("%d", &choice);

	} while (choice != 1 && choice != 2);
	system("cls");
	char * pPosition = NULL; // varibale used for testing for multi name artists
	if (choice == 1) { // Print all record 
		while (pList != NULL) { // loops to end of list
			pPosition = strchr(pList->data.artist, ','); // mulitname artist name
			if (pPosition != NULL) {
				char name[50] = "";
				strcpy(name, pList->data.artist);
				char * lastName = strtok(name, ",");
				char * firstName = strtok(NULL, "\0");
				printf("Artist: %s %s\n", lastName, firstName);
			}
			else
				printf("Artist: %s\n", pList->data.artist); // prints all data
			printf("Album: %s\n", pList->data.album);
			printf("Song Title: %s\n", pList->data.title);
			printf("Genre: %s\n", pList->data.genre);
			printf("Length: %d:%d\n", pList->data.length.minutes, pList->data.length.seconds);
			printf("Times Played: %d\n", pList->data.timesPlayed);
			printf("Rating: %d\n", pList->data.rating);
			Sleep(2000); // pause
			pList = pList->pNext; //next Record
			system("cls");
		}
	}
	else { // Printing all records to a specifc artist
		char searchFor[50] = ""; //target artist
		char tmpName[50] = "";// multiname artist tmp used for comparing 
		bool match = false;// used for showing if artist match
		bool noMatches = true; // test is no matches in entire list
		pPosition = NULL;
		getchar(); // grabs any garbadge values
		printf("Enter the name of the artist: ");
		scanf("%[^\n]s", &searchFor); //reads in target artist
		strcpy(&searchFor, lowercase(&searchFor));
		system("cls");
		while (pList != NULL) { // loops until end of list
			match = false;
			pPosition = strchr(pList->data.artist, ',');
			if (pPosition != NULL) { // multiname test
				char name[50] = { '\0' };
				strcpy(name, pList->data.artist);
				char * lastName = strtok(name, ',');
				char * firstName = strtok(NULL, "\0");
				strcpy(&tmpName, firstName);
				strcat(&tmpName, " ");
				strcat(&tmpName, lastName);
				strcpy(&tmpName, lowercase(&tmpName));
				if (strcmp(tmpName, searchFor) == 0) { // compares target and tmp artist
					match = true;
					noMatches = false;
					printf("Artist: %s %s\n", lastName, firstName);
				}
			}
			else { // single name test
				strcpy(&tmpName, lowercase(pList->data.artist));
				if (strcmp(tmpName, searchFor) == 0) { // compares target and tmp artist
					printf("Artist: %s\n", pList->data.artist);
					noMatches = false;
					match = true;
				}
			}
			if (match == true) { // if record artist match, print rest of data
				printf("Album: %s\n", pList->data.album);
				printf("Song Title: %s\n", pList->data.title);
				printf("Genre: %s\n", pList->data.genre);
				printf("Length: %d:%d\n", pList->data.length.minutes, pList->data.length.seconds);
				printf("Times Played: %d\n", pList->data.timesPlayed);
				printf("Rating: %d\n", pList->data.rating);
				Sleep(2000);
				system("cls");
			}
			pList = pList->pNext; // go to next record
		}
		if (noMatches == true) { //if no matches are found, prints this message
			printf("No matches found\n");
			Sleep(2000);
		}
	}
}


void editRecord(Node *pList) { // Passes in linked list and gives option to edit records, very similar to displayMusic() above except with option to edit record
	system("cls");

	//a bunch of va
	char searchFor[50] = "";
	char tmpName[50] = "";
	char yesno = '\0';
	bool match = false;
	bool noMatches = true;
	char * pPosition = NULL;


	getchar();
	printf("Enter the name of the artist: ");
	scanf("%[^\n]s", &searchFor);
	strcpy(&searchFor, lowercase(&searchFor));
	system("cls");
	while (pList != NULL) { //loops to end of list
		match = false;
		pPosition = strchr(pList->data.artist, ',');
		if (pPosition != NULL) { // mulitname test
			char name[50] = { '\0' };
			strcpy(name, pList->data.artist);
			char * firstName = strtok(name, ",");
			char * lastName = strtok(NULL, "\0");
			strcpy(&tmpName, firstName);
			strcat(&tmpName, " ");
			strcat(&tmpName, lastName);
			strcpy(&tmpName, lowercase(&tmpName));
			
			if (strcmp(tmpName, searchFor) == 0) {
				match = true;
				noMatches = false;
				printf("Artist: %s %s\n", firstName, lastName);
			}
			*pPosition = ',';

		}

		//you can find all the details of this part in the above function displayMusic()
		else {
			strcpy(&tmpName, lowercase(pList->data.artist));
			if (strcmp(tmpName, searchFor) == 0) {
				printf("Artist: %s\n", pList->data.artist);
				noMatches = false;
				match = true;
			}
		}
		if (match == true) { // prints all data if match
			printf("Album: %s\n", pList->data.album);
			printf("Song Title: %s\n", pList->data.title);
			printf("Genre: %s\n", pList->data.genre);
			printf("Length: %d:%d\n", pList->data.length.minutes, pList->data.length.seconds);
			printf("Times Played: %d\n", pList->data.timesPlayed);
			printf("Rating: %d\n", pList->data.rating);
			printf("\n\nWould you like to edit this record? (y/n): ");
			getchar();
			scanf("%c", &yesno);
			if (yesno == 'y') { //gives option to edit
				system("cls");
				int choice = 0, attempt = 0;
				do { // loop test for exit valuse
					do { // loop test for valid input
						++attempt;
						system("cls");
						if (attempt > 1) { //valid input test
							puts("> Invalid user input, please try again");
							attempt--;
						}


						//you can find all the details of this part in the above function displayMusic()
						pPosition = strchr(pList->data.artist, ',');
						if (pPosition != NULL) { // mulitname test
							char name[50] = { '\0' };
							strcpy(name, pList->data.artist);
							char * lastName = strtok(name, ",");
							char * firstName = strtok(NULL, "\0");
							printf("Artist: %s %s\n", lastName, firstName);
							*pPosition = ',';

						}
						
						else 
							printf("Artist: %s\n", pList->data.artist);
						//prints all data about the record
						printf("Album: %s\n", pList->data.album);
						printf("Song Title: %s\n", pList->data.title);
						printf("Genre: %s\n", pList->data.genre);
						printf("Length: %d:%d\n", pList->data.length.minutes, pList->data.length.seconds);
						printf("Times Played: %d\n", pList->data.timesPlayed);
						printf("Rating: %d\n\n", pList->data.rating);
						//choice of what varible to edit
						printf("Which record detail would you like to edit?\n");
						printf("(1)  Artist\n");
						printf("(2)  Album\n");
						printf("(3)  Song Title\n");
						printf("(4)  Genre\n");
						printf("(5)  Length\n");
						printf("(6)  Times Played\n");
						printf("(7)  Rating\n");
						printf("(8)  Exit\n");
						printf("input (1-8): ");
						getchar();
						scanf("%d", &choice);

					} while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 6 && choice != 7 && choice != 8);
					system("cls"); //clears screan

					char data[50] = "";
					char miniyesno = '\0'; //edit or no edit variable
					attempt--;
					switch (choice) // each of the variables to change
					{
					case 1: //Edit artist
						do {//loops until user is satisfied
							printf("NOTE: if inputing a multiword name, use format: first,last\n\n");
							pPosition = strchr(pList->data.artist, ',');
							if (pPosition != NULL) { // mulitname test
								char * lastName = strtok(pList->data.artist, ",");
								char * firstName = strtok(NULL, "\0");
								printf("Current Artist: %s %s\n", lastName, firstName);
							}

							else
								printf("Current Artist: %s\n", pList->data.artist);
							printf("New Artist: ");
							getchar();
							scanf("%[^\n]s", &data);
							strcpy(&pList->data.artist, &data);
							printf("\n\nCurrent Artist: %s", pList->data.artist);
							printf("\nDone? (y/n): ");
							getchar();
							scanf("%c", &miniyesno);
							system("cls");
						} while (miniyesno != 'y');
						break;
					case 2: //Edit album
						do {
							printf("Current Album: %s\n", pList->data.album);
							printf("New Album: ");
							getchar();
							scanf("%[^\n]s", &data);
							strcpy(pList->data.album, &data);
							printf("\n\nCurrent Artist: %s", pList->data.album);
							printf("\n Done? (y/n): ");
							getchar();
							scanf("%c", &miniyesno);
							system("cls");
						} while (miniyesno != 'y');
						break;
					case 3: //Edit song title
						do {
							printf("Current Song Title: %s\n", pList->data.title);
							printf("New Song Title: ");
							getchar();
							scanf("%[^\n]s", &data);
							strcpy(pList->data.title, &data);
							printf("\n\nCurrent Song Title: %s", pList->data.title);
							printf("\n Done? (y/n): ");
							getchar();
							scanf("%c", &miniyesno);
							system("cls");
						} while (miniyesno != 'y');
						break;
					case 4: //edit Genre
						do {
							printf("Current Genre: %s\n", pList->data.genre);
							printf("New Genre: ");
							getchar();
							scanf("%[^\n]s", &data);
							strcpy(pList->data.genre, &data);
							printf("\n\nCurrent Genre: %s", pList->data.genre);
							printf("\n Done? (y/n): ");
							getchar();
							scanf("%c", &miniyesno);
							system("cls");
						} while (miniyesno != 'y');
						break;
					case 5: //edit length of song 
						do {
							printf("Current Length: %d:%d\n", pList->data.length.minutes, pList->data.length.seconds);
							printf("New Length: ");
							getchar();
							scanf("%[^\n]s", &data);
							int minute = atoi(strtok(data, ":"));
							int second = atoi(strtok(NULL, "\n"));
							pList->data.length.minutes = minute;
							pList->data.length.seconds = second;
							printf("\n\nCurrent Length: %d:%d", pList->data.length.minutes, pList->data.length.seconds);
							printf("\n Done? (y/n): ");
							getchar();
							scanf("%c", &miniyesno);
							system("cls");
						} while (miniyesno != 'y');
						break;
					case 6: //Edit times played
						do {
							printf("Current Times Played: %d\n", pList->data.timesPlayed);
							printf("New Times Played: ");
							getchar();
							scanf("%[^\n]s", &data);
							pList->data.timesPlayed = atoi(data);
							printf("\n\nCurrent Times Played: %d", pList->data.timesPlayed);
							printf("\n Done? (y/n): ");
							getchar();
							scanf("%c", &miniyesno);
							system("cls");
						} while (miniyesno != 'y');
						break;
					case 7: //Edit the rating 
						do {
							printf("Current Rating: %d\n", pList->data.rating);
							printf("New Rating: ");
							getchar();
							scanf("%[^\n]s", &data);
							pList->data.rating = atoi(data);
							printf("\n\nCurrent Times Played: %d", pList->data.rating);
							printf("\n Done? (y/n): ");
							getchar();
							scanf("%c", &miniyesno);
							system("cls");
						} while (miniyesno != 'y');
						break;
					default:
						break;
					}
				}while (choice != 8); //exit choice
			}
			system("cls");
		}
		pList = pList->pNext;
	}
	
	if (noMatches == true) {
		printf("No matches found\n");
		Sleep(2000);
	}
	else {
		printf("No more Records by that artist\n");
		Sleep(2000);
	}
}


void rateSong(Node *pList) { //rates a song
	//varible declaration 
	bool match = false;
	char * pPosition = NULL;
	bool noMatches = true;
	char searchFor[50] = "";
	char tmpName[50] = "";
	char yesno = '\0';

	getchar(); //grabs garbage values
	printf("Enter the name of the artist: ");
	scanf("%[^\n]s", &searchFor); // gets the target artist to rate
	strcpy(&searchFor, lowercase(&searchFor));
	system("cls");

	while (pList != NULL) { //loops until end of linked list 
		match = false;
		pPosition = NULL;
		pPosition = strchr(pList->data.artist, ',');
		if (pPosition != NULL) { //tests for multi name artist
			char name[50] = { '\0' };
			strcpy(name, pList->data.artist);
			char * firstName = strtok(name, ",");
			char * lastName = strtok(NULL, "\0");
			strcpy(&tmpName, firstName);
			strcat(&tmpName, " ");
			strcat(&tmpName, lastName);
			strcpy(&tmpName, lowercase(&tmpName));
			if (strcmp(tmpName, searchFor) == 0) {
				match = true;
				noMatches = false;
				printf("Artist: %s %s\n", lastName, firstName);
			}
		}
		else { //single name artist
			strcpy(&tmpName, lowercase(pList->data.artist));
			if (strcmp(tmpName, searchFor) == 0) {
				printf("Artist: %s\n", pList->data.artist);
				noMatches = false;
				match = true;
			}
		}
		if (match == true) { //if found match, Prints all data about recrod
			printf("Album: %s\n", pList->data.album);
			printf("Song Title: %s\n", pList->data.title);
			printf("Genre: %s\n", pList->data.genre);
			printf("Length: %d:%d\n", pList->data.length.minutes, pList->data.length.seconds);
			printf("Times Played: %d\n", pList->data.timesPlayed);
			printf("Rating: %d\n", pList->data.rating);
			printf("\n\nWould you like to rate this record? (y/n): "); //choice to rate song
			getchar();
			scanf("%c", &yesno);
			if (yesno == 'y') {
				system("cls");
				printf("Old Rating: %d\n\n", pList->data.rating);
				printf("New Rating: ");
				getchar();
				scanf("%d", &pList->data.rating); //rates the song
				system("cls");
			}
			system("cls");
		}
		pList = pList->pNext;
	}

}


char * lowercase(char * mystr) { //converts a string to all lowercase - used to compare strings
	char yourstr[50] = "";
	strcpy(&yourstr, mystr); //copies strinug
	int i = 0;
	while (yourstr[i] != '\0') { //loops until end of string
		yourstr[i] = tolower(yourstr[i]);
		i++;
	}
	return yourstr; //returns lowercase string
}

bool loadMusic(Node **pList, FILE *infile) { // loads the music from the infile into a linked list
	//variable declaration 
	char line[100] = "";
	Record tmpRecord = { '\0' };
	bool success = false;
	char * data;
	char firstName[15] = "";
	char * data2;
	char lastName[15] = "";

	while (!feof(infile)) { //loops until EOF
		fgets(line, 100, infile);
		if (line[0] != '\n') { //checks for new line, if it is it means it's the EOF
			if (line[0] == '\"') { //checks for multi word first name (e.g. Taylor Swift)
				data = strtok(line, ",");
				strcpy(&lastName, data); 
				strcpy(&lastName, &lastName[1]);
				data2 = strtok(NULL, "\",");
				strcpy(&firstName, data2);
				strcpy(&firstName, &firstName[1]);
				strcpy(tmpRecord.artist, firstName);
				strcat(tmpRecord.artist, ",");
				strcat(tmpRecord.artist, lastName);
			}
			else { // checks for single word first name (e.g. Drake)
				data = strtok(line, ","); // 
				strcpy(tmpRecord.artist, data);
			}
			//records rest of data into tmp Record struct
			data = strtok(NULL, ",");
			strcpy(tmpRecord.album, data);
			data = strtok(NULL, ",");
			strcpy(tmpRecord.title, data);
			data = strtok(NULL, ",");
			strcpy(tmpRecord.genre, data);
			data = strtok(NULL, ":");
			tmpRecord.length.minutes = atoi(data);
			data = strtok(NULL, ",");
			tmpRecord.length.seconds = atoi(data);
			data = strtok(NULL, ",");
			tmpRecord.timesPlayed = atoi(data);
			data = strtok(NULL, "\n");
			tmpRecord.rating = atoi(data);

			success = addToList(pList, tmpRecord); //adds the record to the linked list
			if (success == false) break;
		}
		else
			break;
		
	}
	int j = 1;
	for (int i = 0; i < 6; i++){ //Load success message and gif --  i put of lot of effort into this for no reason and i hope someone reads this and enjoys it
		system("cls");
		printf("Songs loaded successfully\n\n");
		if (j == 1) {
			printf("   _[^.^]|");
			j = 2;
			Sleep(150);
		}
		else if (j == 2) {
			printf("   \\[^.^]/");
			j = 3;
			Sleep(150);
		}
		else if (j == 3) {
			printf("   |[^.^]_");
			j = 4;
			Sleep(150);
		}
		else if (j == 4) {
			printf("   \\[^.^]/");
			j = 1;
			Sleep(150);
		}
	}
	return success;
}