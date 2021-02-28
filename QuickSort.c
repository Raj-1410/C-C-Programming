#include<stdio.h>
#include<time.h>
#include<math.h>


void quickSort(int arr[], long int,long int);
 void main()  
{  
	int i;
	long int m;    
	clock_t s,e;
	double cpu_time_used;

	int* arr1;

	arr1 = (int*)malloc(sizeof(int)*100);
     
	for(m=0;m<100;m++)
	{ 
		arr1[m] = rand() % 100;		
	}

	int* arr2;

	arr2 = (int*)malloc(sizeof(int)*1000);
     
	for(m=0;m<1000;m++)
	{ 
		arr2[m] = rand() % 100;		
	}

	int* arr3;

	arr3 = (int*)malloc(sizeof(int)*10000);
     
	for(m=0;m<10000;m++)
	{ 
		arr3[m] = rand() % 100;		
	}

	int* arr4;

	arr4 = (int*)malloc(sizeof(int)*100000);
     
	for(m=0;m<100000;m++)
	{ 
		arr4[m] = rand() % 100;		
	}

    	
	printf("\n For 100 elements -------------------------------------------------------------\n");
	
	
	s = clock();	
    	quickSort(arr1,0, 100);
	e = clock();  
	/*printf("Sorted array: \n");  
	for (i = 0; i < 100; i++)  
	{
		printf("%d \n",arr1[i]);
	}*/
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("random to ascending%f \n",cpu_time_used);

	s = clock();	
    	quickSort(arr1, 0,100);
	e = clock(); 
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to ascending%f \n",cpu_time_used);

	s = clock();	
    	rev_quickSort(arr1, 0,100);
	e = clock(); 
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to descending%f \n",cpu_time_used);

	printf("\n For 1000 elements ------------------------------------------------------------\n");

	s = clock();	
	quickSort(arr2, 0, 1000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("random to ascending %f \n",cpu_time_used);

	s = clock();	
	quickSort(arr2, 0,1000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to ascending %f \n",cpu_time_used);

	s = clock();	
	rev_quickSort(arr2, 0, 1000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to descending %f \n",cpu_time_used);
	
	printf("\n For 10000 elements -----------------------------------------------------------\n");

	s = clock();	
	quickSort(arr3, 0, 10000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("random to ascending %f \n",cpu_time_used);

	s = clock();	
	quickSort(arr3, 0, 10000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to ascending %f \n",cpu_time_used);

	s = clock();	
	rev_quickSort(arr3, 0, 10000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to descending %f \n",cpu_time_used);

	printf("\n For 100000 elements ----------------------------------------------------------\n");

	s = clock();	
	quickSort(arr4, 0, 100000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("random to ascending %f \n",cpu_time_used);

	s = clock();	
	quickSort(arr4, 0, 100000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to ascending %f \n",cpu_time_used);

	s = clock();	
	rev_quickSort(arr4, 0, 100000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to descending %f \n",cpu_time_used);
	 
}

 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];     
    int i = (low - 1);  
  
    for (int j = low; j <= high- 1; j++) 
    { 
  
        if (arr[j] >= pivot) 
        { 
            i++;   
            int temp;
	    temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp; 
        } 
    } 
     
	int temp;
	temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
    return (i + 1); 
} 
  

void quickSort(int arr[], long int low, long int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}  

void rev_quickSort(int arr[], long int low, long int high) 
{ 
    if (low > high) 
    { 
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
