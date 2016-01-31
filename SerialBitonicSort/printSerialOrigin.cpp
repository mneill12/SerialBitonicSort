
#include<stdio.h>
#include<stdlib.h>

const int sizeOfArray = 8;
const int up = 1;
const int down = 0;
const int randMax = 100;
int amountOfMerges = 0;
 int recursiveExecution = 0;

void populateArray(int *elements);
void merge(int firstElement, int size, int direction, int *elements);
void bitonicSplit(int firstElement, int size, int direction, int *elements);
void sort(int *elements);
void printArray(int *elements);
bool isSorted(int *sorted);


int main() {

	//Creater pointer array using malloc and populate it.
	int *elements;
	elements = (int*)malloc(sizeOfArray*sizeof(int));
	printf("\nPopulating array\n");

	for (int i = 0; i < sizeOfArray; ++i){
		elements[i] = rand() % randMax;
	}

	//Sort them
	sort(elements);

	if (isSorted(elements)){
		printf("\nArray Sorted \n");
	}

	else{
		printf("Not sorted \n");
	}

	printf("Final sequence ");
	for (int i = 0; i < sizeOfArray; i++){
		printf(" %d,", elements[i]);
	}

	free(elements);
	getchar();
	return 0;
}

void printArray(int *elements){

	for (int i = 0; i < sizeOfArray; ++i){
		printf("%d ,",elements[i] );
	}
	printf("\n");
}

bool isSorted(int *elements){

	bool sorted = true;
	for (int i = 0; i < (sizeOfArray-1); ++i){
		if (elements[i] > elements[i + 1]){
			sorted = false;
		}
	}
	return sorted;
}

void compare(int i, int j, int direction, int *elements) {

	//Swap if the elements in the sorting network are contradictory to the direction of that swap
	printf("\nValues being compared: %d & %d\n", elements[i], elements[j]);
	if (direction == elements[i] > elements[j]){
		int temp = elements[i];
		elements[i] = elements[j];
		elements[j] = temp;

		printf("\nSwaped Elements");
	}
}

void merge(int firstElement, int size, int direction, int *elements) {
	if (size>1) {
		char* stirngDirection = "Assending";

		if (!direction)
		{
			stirngDirection = "Descending";
		}
	
		printf("\nMerge in recursive execution %d in %s direction Started \n", recursiveExecution, stirngDirection);
		int k = size / 2;
		amountOfMerges++;
		printf("Size during merge: %d", k);
		printf("\n");
		

		printf("Comparing elements of index: %d and %d", firstElement, firstElement + k);
		for (int i = firstElement; i < firstElement + k; i++){

			compare(i, i + k, direction, elements);
		}
		
		merge(firstElement, k, direction, elements);
		merge(firstElement + k, k, direction, elements);
	}
}


//Recursivly create bitonic sequence.  
void bitonicSplit(int firstElement, int size, int direction, int *elements) {
	if (size>1) {
		int k = size / 2;

		char* stirngDirection = "Assending";

		if (!direction)
		{
			stirngDirection = "Descending";
		}
		
		recursiveExecution++;
		printf("\n!!!!!Recursive Execution  %d Started for %s Direction!!!!\n", recursiveExecution, stirngDirection);

		bitonicSplit(firstElement, k, up, elements);
		bitonicSplit(firstElement + k, k, down, elements);

		if (size == sizeOfArray)
		{
			printf("\nSequence before last merge\n");
			printArray(elements);
		}
		
		merge(firstElement, size, direction, elements);
	
		printf("\n!!!Recursive Execution  %d Ended for direction %s!!!\n", recursiveExecution, stirngDirection);
		recursiveExecution--;
	}
}

void sort(int  *elements) {
	bitonicSplit(0, sizeOfArray, up, elements);
}