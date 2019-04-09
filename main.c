#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 5

int cat();
void sortArray1(int* array, int array_size);
void sortArray2(int* array, int array_size);

void printArray(int* array,int N);
int findElement(int* array,int N, int element);

void ShellsSort(int *array, int N);


int main(void)
{
	srand(time(NULL));
	int size = 5,i;
	int array[size];
	int element;
	
	for(i = 0; i < size; i++)
	{
		array[i] = rand()%10;
	}
	
	printArray(array,size);
	
	printf("Enter element:");
	
	scanf("%d",&element);
	
	sortArray2(array, findElement(array,size,element));
	printArray(array,size);
}

void printArray(int* array,int N)
{
	int i;
	printf("\n");
	for(i = 0; i < N;i++)
	{
		printf("%d\n",array[i]);
	}
	printf("\n");
	
}

int findElement(int* array,int N, int element)
{
	int i;
	for(i = 0; i < N; i++)
	{
		if(array[i] == element)
		{
			return i;
		}
	}
	return N-1;
}

void sortArray1(int* array, int array_size)
{
	int buf, i,j,k;
	/*for(k = 0; k < array_size; k++)
	{
		printf("%d\n",array[k]);
	}*/
//	printf("\n");
	for(i = 0 ; i < array_size - 1; i++) 
	{ 
		for(j = 0 ; j < array_size - i - 1 ; j++) 
		{  
			if(array[j] > array[j+1]) 
			{
			//	printf("i = %d; j = %d; swap: %d %d \n",i,j,j,j+1);           
				buf = array[j+1];
				array[j+1] = array[j];
				array[j] = buf; 
			}
			//for
			/*(k = 0; k < array_size; k++)
			{
			//	printf("i = %d; j = %d; %d\n",i,j,array[k]);
			}
			//printf("\n");*/
		}
    }
}

void sortArray2(int* array, int array_size)
{
	int i, j, k, minIndx = 0, head = 0, buf;
	for(i = 0;i<array_size-1;i++)
	{
		for(j = head; j<array_size; j++)
		{
			if(array[minIndx] > array[j])
			{
				minIndx = j;
			}
		}
		buf = array[minIndx];
		array[minIndx] = array[head];
		array[head] = buf;
		head++;
		minIndx = head;
	}
}

void ShellsSort(int *array, int N)
{
	int i, j, k;
	int t;
	for(k = N / 2; k > 0; k /= 2)
	{
        for(i = k; i < N; i++)
        {
            t = array[i];
            for(j = i; j >= k; j -= k)
            {
                if(t < array[j - k])
                {
                	array[j] = array[j - k];
				}    
                else
                {
              	 	break;
				}
            }
            array[j] = t;
        }
	}
}
