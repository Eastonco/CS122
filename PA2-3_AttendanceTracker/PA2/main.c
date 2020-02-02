#include "testMe.h"

int main(void) {
	int choice = 0;
	FILE * infile = NULL, * outfile = NULL;
	Node * pList = NULL;
	infile = fopen("musicPlayList.csv", "r");

	int runOrTest = 0;
	do {
		system("cls");
		printf("(1) Run Program\n");
		printf("(2) Debug/Test Program\n");
		scanf("%d", &runOrTest);
	} while (runOrTest != 1 && runOrTest != 2);

	if (runOrTest == 1) {
		while (choice != 11) {
			choice = displayMenu();
			switch (choice)
			{
			case 1:// load
				loadMusic(&pList, infile);
				fclose(infile);
				infile = fopen("musicPlayList.csv", "r");
				break;
			case 2:  // store
				fclose(infile);
				outfile = fopen("musicPlayList.csv", "w");
				saveAndExit(pList, outfile);
				fclose(outfile);
				infile = fopen("musicPlayList.csv", "r");
				break;
			case 3:  // display
				displayMusic(pList);
				break;
			case 4:  // insert
				pList = insertSong(pList);
				break;
			case 5:  // delete
				deleteSong(pList);
				break;
			case 6:  // edit
				editRecord(pList);
				break;
			case 7:  // sort
				pList = sortSongs(pList); //added &
				break;
			case 8:  // rate
				rateSong(pList);
				break;
			case 9:  // play
				playMusic(pList);
				break;
			case 10: // shuffle
				shuffle(pList); //added &
				break;
			case 11: // exit
				fclose(infile);
				outfile = fopen("musicPlayList.csv", "w");
				saveAndExit(pList, outfile);
				fclose(outfile);
				printf("Goodbye!\n");
				Sleep(1000);
				break;
			}
		}
	}
	else if (runOrTest == 2) {
		insertTest();
		printf("\nEnd of insert test\n\n");
		deleteTest();
		printf("\nEnd of delete test\n\n");
		shuffleTest();
		printf("\nEnd of shuffle test\n");
	}
	
	

	return 0;
}