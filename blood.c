#include<stdio.h>
#include<stdlib.h>

#define N 8     //Number of vertices in the graph

struct Graph{
	struct node *head[N];     //An array of pointers to node to represent ajacency list
};
struct node{
	int dest,weight;
	struct node *next;
	int RedBloodCells_count;
	int WhiteBloodCells_count;
	int PlateletsBloodCells_count;
};

struct Edge{
	int str,dest,weight;
};

struct RedBloodCells{
	float redbloodcells_amount;
	int redblood_lifespan;
	int redblood_distance;
};
struct WhiteBloodCells{
	float whitebloodcells_amount;
	int whiteblood_lifespan;
	int whiteblood_distance;
};
struct PlateletsBloodCells{
	float platelets_amount;
	int platelets_lifespan;
	int platelets_distance;
};

struct Graph *CreateGraph(struct Edge edges[],int n){
	unsigned i;
	struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));   //Allocate memory for graph data structure
	
	for(i=0;i<N;i++){
		graph->head[i]=NULL;        //initialize head pointer for all vertices
	}
	
	for(i=0;i<n;i++){     //add edges to the directed graph
	    int str=edges[i].str;
		int dest=edges[i].dest;
		int weight=edges[i].weight;
		
		struct node *newnode=(struct node*)malloc(sizeof(struct node)); //Allocate newnode of graph str to dest
		newnode->dest=dest;
		newnode->weight=weight;
		
		newnode->next=graph->head[str];   //point new node to current head
		graph->head[str]=newnode;         //point head pointer to newnode
	}
	return graph;
}
int array[8];
int j=0;
void OrganTraverse(int organ,int value,struct Edge edges[],int n){
	int i=0;
	int difference=0;
	int count=0;
	j=0;
	
	struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
	for(i=1;i<=N;i++){
		graph->head[i]=NULL;
	}
	
	struct node *newnode1=(struct node*)malloc(sizeof(struct node));
	for(i=0;i<n;i++){
		int str=edges[i].str;
		int dest=edges[i].dest;
		int weight=edges[i].weight;
		newnode1->dest=dest;
		newnode1->weight=weight;

	
	if(str==5){
		count++;
	}
	if(str==5 && count==1){
		array[j]=str;
		j++;
	}
	if((j<organ && count>1 && str!=5)||(j<organ && count<1 && str!=5)){
		difference=N-str;
		if(str>5 && difference<=2 && str==organ){
			array[j]=str;
			j++;
			break;
		}
		if(difference>2){
			array[j]=str;
			j++;
		}
	}
	
	if(newnode1->dest==organ){
		if(organ==6){
		printf("\nBrain  Found\n");	
		}
		if(organ==7){
			printf("\nLiver  Found\n");
		}
		if(organ==8){
			printf("\nKidney  Found\n");
		}
		
	}
	newnode1->next=graph->head[str];   //point new node1 to current head
	graph->head[str]=newnode1;         //point head pointer to newnode1
	}
	
	int k=0;
    printf("\nThe Path For Suitable organ:");
    for(i=0;i<j;i++){
	k=array[i];
	//printf("%d",array[i]);
    switch(k){
		case 1:
			printf("Right Atrium ->");
			break;
		case 2:
			printf("Right Ventricle->");
			break;
		case 3:
			printf("Lungs->");
			break;
		case 4:
			printf("Leftt Atrium->");
			break;
		case 5:
			printf("Leftt Ventricle->");
			break;
		case 6:
			printf("Brain->");
			break;
		case 7:
			printf("Liver->");
			break;
		case 8:
			printf("Kidney->");
			break;
	}
	
}
printf("\n");

	
}
void calculation(struct Graph *graph){
	struct RedBloodCells red;
	struct WhiteBloodCells white;
	struct PlateletsBloodCells platelets;
	
	red.redbloodcells_amount=600;//for perday brain,liver,kidney
	white.whitebloodcells_amount=100;
	platelets.platelets_amount=150;
	
	red.redblood_lifespan=110;//days
	white.whiteblood_lifespan=15;
	platelets.platelets_lifespan=9;
	
	red.redblood_distance=400;        // for perday redcells travers distance
	white.whiteblood_distance=50;     // for perday whitecells travers distance
	platelets.platelets_distance=75;  // for perday platelets travers distance
	
	int pathweight[20];
	int sumOfweight=0;
	int organ[10];
	int pathOfBrainweight,pathOfKidneyweight,pathOfLiverweight;
	int k=0;
	int countBrain=0,countKidney=0,countLiver=0;
	int countall=0;
	int i,j,p,u,t;
	
	float numberOfTimesTraverseRedcellsBrain;
	float numberOfTimesTraverseWhitecellsBrain;
	float numberOfTimesTraverseplateletsBrain;
	float numberOfTimesTraverseRedcellsLiver;
	float numberOfTimesTraverseWhitecellsLiver;
	float numberOfTimesTraverseplateletsLiver;
	float numberOfTimesTraverseRedcellsKidney;
	float numberOfTimesTraverseWhitecellsKidney;
	float numberOfTimesTraverseplateletsKidney;
	
	int totalRedcellsDistance=0;
	int totalWhitecellsDistance=0;
	int totalplateletsDistance=0;
	
	p=0;
	for(i=1;i<=N;i++){
		struct node *ptr1=graph->head[i];
		while(ptr1!=NULL){
			if(ptr1->dest>1 && ptr1->dest<6){
				pathweight[k]=ptr1->weight;
				k++;
			}
			if(ptr1->dest==6 ||  ptr1->dest==7 || ptr1->dest==8){
				organ[p]=ptr1->dest;
				sumOfweight=0;
				for(j=0;j<k;j++){
					sumOfweight=sumOfweight+pathweight[j];
				}
				if(ptr1->dest==6){
					pathOfBrainweight=sumOfweight+ptr1->weight;
				}
				if(ptr1->dest==7){
					pathOfLiverweight=sumOfweight+ptr1->weight;
				}
				if(ptr1->dest==8){
					pathOfKidneyweight=sumOfweight+ptr1->weight;
				}
			p++;
				
			}
			if(ptr1->dest==1){
				countall=0;
				for(u=0;u<p;u++){
					if(organ[u]==6 && countBrain==0 && countall==0 && i==6){
						pathOfBrainweight=pathOfBrainweight+ptr1->weight;
						printf("\nThe Total Weight Of Brain:%d\n",pathOfBrainweight);
						countall++;
						countBrain++;
					}
					if(organ[u]==7 && countLiver==0 &&countall==0 && i==7){
						pathOfLiverweight=pathOfLiverweight+ptr1->weight;
						printf("The Total Weight of Liver:%d\n",pathOfLiverweight);
						countall++;
						countLiver++;
					}
					if(organ[u]==8 && countKidney==0 && countall==0 && i==8){
						pathOfKidneyweight=pathOfKidneyweight+ptr1->weight;
						printf("The Total Weight Of Kidney:%d\n",pathOfKidneyweight);
						countall++;	
						countKidney++;	
					}
				}
			}
		ptr1=ptr1->next;	
		}
	}
printf("\n");	
totalRedcellsDistance=red.redblood_distance*red.redblood_lifespan;
printf("Total Traversal Distance Of RedBlood cells In Its Lifespan:%d\n",totalRedcellsDistance);
totalWhitecellsDistance=white.whiteblood_distance*white.whiteblood_lifespan;
printf("Total Traversal Distance Of WhiteBlood cells In Its Lifespan:%d\n",totalWhitecellsDistance);
totalplateletsDistance=platelets.platelets_distance*platelets.platelets_lifespan;
printf("Total Traversal Distance Of WhiteBlood cells In Its Lifespan:%d\n",totalplateletsDistance);

numberOfTimesTraverseRedcellsBrain=(totalRedcellsDistance/pathOfBrainweight); //number of times each cells travers to the organ
numberOfTimesTraverseWhitecellsBrain=(totalWhitecellsDistance/pathOfBrainweight);
numberOfTimesTraverseplateletsBrain=(totalplateletsDistance/pathOfBrainweight);

printf("\n\n----------Number of times each cells traverse to the Brain----------\n\n");
printf("    Red Cells  :%2f\n",numberOfTimesTraverseRedcellsBrain);
printf("    White Cells:%2f\n",numberOfTimesTraverseWhitecellsBrain);
printf("    Platelets  :%2f\n",numberOfTimesTraverseplateletsBrain);

numberOfTimesTraverseRedcellsLiver=(totalRedcellsDistance/pathOfLiverweight); 
numberOfTimesTraverseWhitecellsLiver=(totalWhitecellsDistance/pathOfLiverweight);
numberOfTimesTraverseplateletsLiver=(totalplateletsDistance/pathOfLiverweight);	

printf("\n\n----------Number of times each cells traverse to the Liver----------\n\n");
printf("    Red Cells  :%2f\n",numberOfTimesTraverseRedcellsLiver);
printf("    White Cells:%2f\n",numberOfTimesTraverseWhitecellsLiver);
printf("    Platelets  :%2f\n",numberOfTimesTraverseplateletsLiver);

numberOfTimesTraverseRedcellsKidney=(totalRedcellsDistance/pathOfKidneyweight); 
numberOfTimesTraverseWhitecellsKidney=(totalWhitecellsDistance/pathOfKidneyweight);
numberOfTimesTraverseplateletsKidney=(totalplateletsDistance/pathOfKidneyweight);

printf("\n\n----------Number of times each cells traverse to the Kidney----------\n\n");
printf("    Red Cells  :%2f\n",numberOfTimesTraverseRedcellsKidney);
printf("    White Cells:%2f\n",numberOfTimesTraverseWhitecellsKidney);
printf("    Platelets  :%2f\n",numberOfTimesTraverseplateletsKidney);

float outOfblood=5;  //liters
float storebloodBrain=2;
float storebloodLiver=2;
float storebloodKidney=1;
float BrainProbability;
float LiverProbability;
float KidneyProbability;

float numberOfRedcellsBrain;
float numberOfWhitecellsBrain;
float numberOfPlateletsBrain;

float numberOfRedcellsLiver;
float numberOfWhitecellsLiver;
float numberOfPlateletsLiver;

float numberOfRedcellsKidney;
float numberOfWhitecellsKidney;
float numberOfPlateletsKidney;

BrainProbability=(storebloodBrain/outOfblood)*100;
LiverProbability=(storebloodLiver/outOfblood)*100;
KidneyProbability=(storebloodKidney/outOfblood)*100;

printf("\nProbability of the blood store in the Brain : %2f ",BrainProbability);
printf("\nProbability of the blood store in the Liver : %2f ",LiverProbability);
printf("\nProbability of the blood store in the Kidney: %2f ",KidneyProbability);

numberOfRedcellsBrain=(red.redbloodcells_amount*storebloodBrain)/outOfblood;
printf("\n\nNumber of RedBlood Cells in Brain : %2f ",numberOfRedcellsBrain);
numberOfWhitecellsBrain=(white.whitebloodcells_amount*storebloodBrain)/outOfblood;
printf("\nNumber of whiteBlood Cells in Brain :%2f ",numberOfWhitecellsBrain);
numberOfPlateletsBrain=(platelets.platelets_amount*storebloodBrain)/outOfblood;
printf("\nNumber of platelets in Brain        :%2f",numberOfPlateletsBrain);

numberOfRedcellsLiver=(red.redbloodcells_amount*storebloodLiver)/outOfblood;
printf("\n\nNumber of RedBlood Cells in Liver :%2f ",numberOfRedcellsLiver);
numberOfWhitecellsLiver=(white.whitebloodcells_amount*storebloodLiver)/outOfblood;
printf("\nNumber of whiteBlood Cells in Liver :%2f ",numberOfWhitecellsLiver);
numberOfPlateletsLiver=(platelets.platelets_amount*storebloodLiver)/outOfblood;
printf("\nNumber of platelets in Liver        :%2f ",numberOfPlateletsLiver);

numberOfRedcellsKidney=(red.redbloodcells_amount*storebloodKidney)/outOfblood;
printf("\n\nNumber of RedBlood Cells in Kidney :%2f ",numberOfRedcellsKidney);
numberOfWhitecellsKidney=(white.whitebloodcells_amount*storebloodKidney)/outOfblood;
printf("\nNumber of whiteBlood Cells in Kidney :%2f ",numberOfWhitecellsKidney);
numberOfPlateletsKidney=(platelets.platelets_amount*storebloodKidney)/outOfblood;
printf("\nNumber of platelets in Kidney        :%2f ",numberOfPlateletsKidney);



}
void PrintList(struct Graph *graph){
	int i;
	struct node *ptr;
	for(i=1;i<=N;i++){
		ptr=graph->head[i];
	//	printf("%d ->",i);
		while(ptr!=NULL){
			//printf("%d (%d)\t",ptr->dest,ptr->weight);
		   // ptr=ptr->next;
		   switch(i){
		   	case 1:
				printf("Right Atrium-> Right Ventricle:%d",ptr->weight);
			    ptr=ptr->next;
			    printf("\n");
				break;	
			case 2:
			    printf("Right Ventricle->Lungs:%d",ptr->weight);
			    ptr=ptr->next;
			    printf("\n");
			    break;
			case 3:
			    printf("Lungs->Left Atrium:%d",ptr->weight);
			    ptr=ptr->next;
			    printf("\n");
			    break;
			case 4:
			    printf("Left Atrium->Left Ventricle:%d",ptr->weight);
			    ptr=ptr->next;
			    printf("\n");
			    break;
			case 5:
			    	
			    if(ptr->dest==6){
			    	printf("Left Ventricle->Brain:%d",ptr->weight);
			        ptr=ptr->next;
			        printf("\n");
			        break;
			            
				}
				if(ptr->dest==7){
					printf("Left Ventricle->Liver:%d",ptr->weight);
			        ptr=ptr->next;
			        printf("\n");
			        break;
			           
				}
				if(ptr->dest==8){
				    printf("Left Ventricle->Kidney:%d",ptr->weight);
			        ptr=ptr->next;
			        printf("\n");
			        break;
				}
					
				case 6:
				    printf("Brain->Right Atrium:%d",ptr->weight);
			        ptr=ptr->next;
			        printf("\n");
			        break;
			    case 7:
			    	printf("Liver->Right Atrium:%d",ptr->weight);
			        ptr=ptr->next;
			        printf("\n");
			        break;
			    case 8:
			    	printf("Kidney->Right Atrium:%d",ptr->weight);
			        ptr=ptr->next;
			        printf("\n");
			        break;
		    }
	    }
	    printf("\n");
	}
}

int main(){
	printf("four chambers of heart and other vital organs in the body\n");
	printf("___________________________\n");
	printf("| 1    \t| Right Atrium    |\n");
	printf("| 2    \t| Right Ventricle |\n");
	printf("| 3    \t| Lungs           |\n");
	printf("| 4    \t| Left Atrium     |\n");
	printf("| 5    \t| Left Ventricle  |\n");
	printf("| 6    \t| Brain           |\n");
	printf("| 7    \t| Liver           |\n");
	printf("| 8    \t| Kidney          |\n");
	printf("|_______|_________________|\n");
	printf("\n");
	struct Edge edges[]=
	{
	    {1,2,10},{2,3,12},{3,4,15},{4,5,18},{5,6,20},{5,7,25},{5,8,32},{6,1,35},{7,1,38},{8,1,33}
	};

	int organ;
	int n=sizeof(edges)/sizeof(edges[0]);        //calculate number of edges
	struct Graph *graph=CreateGraph(edges,n);
	PrintList(graph);
	do{
		printf("\nEnter Blood Circulation Vital Organ\n");
	    printf("Press Enter 6 -> Brain\n");
	    printf("Press Enter 7 -> Liver\n");
	    printf("Press Enter 8 -> Kidney\n");
	    printf("Press Enter 0 -> Display\n");
	    printf("\nEnter Your Vital Organ Number:");
	    scanf("%d",&organ);
	    if(organ>5 && organ<9 || organ==0){
	    	if(organ!=0){
	    		OrganTraverse(organ,1,edges,n);
			}
		   
	    }else{
		    printf("Invalid Organ Number!!!\n");
	    }
	}while(organ!=0);
	calculation(graph);
	return 0;
	
}
