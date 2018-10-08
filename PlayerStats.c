#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <cstddef>

typedef struct PlayerInfo{
	char playername[64];
	float DOC;
	struct PlayerInfo* nextplayer;
} playerinfo;

playerinfo* insertionSort(playerinfo *head,playerinfo *node){
	playerinfo *curr=head->nextplayer;
	playerinfo *prev = head;
	while(curr!=NULL){
		if(curr->DOC<node->DOC||(curr->DOC==node->DOC && strcmp(curr->playername,node->playername)>0)){
			prev->nextplayer = node;
			node->nextplayer = curr;
			return head;
		}else{
			prev = curr;
			curr=curr->nextplayer;
		}
	}
	prev->nextplayer = node;
	return head;
}


main(int argc, char *argv[]){

	FILE *fpointer;
	fpointer = fopen(argv[1],"r");

	playerinfo *head;
	head = (playerinfo *)malloc(sizeof(playerinfo));
	head->nextplayer=NULL;

	char name[64];
	float points;
	float assists;
	float minutes;

	int count=0;

	if (fscanf(fpointer, "%s",name)==EOF){
		printf("PLAYER FILE IS EMPTY");
		free(head);
		fclose(fpointer);
		return EXIT_SUCCESS;
	}

	while (true){
		if (count!=0){

		fscanf(fpointer, "%s",name);
		}

		if (strcmp(name, "DONE") == 0){
			break;
		}
		playerinfo *node;
		node = (playerinfo *)malloc(sizeof(playerinfo));

		strcpy(node->playername, name);

		fscanf(fpointer, "%f",&points);
		fscanf(fpointer,"%f",&assists);
		fscanf(fpointer,"%f",&minutes);
		node->nextplayer = NULL;

		if(minutes != 0){
			node->DOC = (points+assists)/minutes;
		}
		else{
		node->DOC = 0;
		}
		if (head->nextplayer==NULL){
			head->nextplayer=node;
		}else{
			head = insertionSort(head,node);
		}
		count++;
		//printf("%s %f\n", node->playername,node->DOC);

	}

	fclose(fpointer);

	playerinfo *second;
	second = head->nextplayer;
	while(second!=NULL){
		printf("%s %f\n",second->playername,second->DOC);
		second = second->nextplayer;

	}

	while(head!=NULL){
		PlayerInfo* temp = head;
		head = head->nextplayer;
		free(temp);
	}
	return EXIT_SUCCESS;
}


	








