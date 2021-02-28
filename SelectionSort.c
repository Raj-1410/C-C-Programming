#include<stdio.h>
#include<time.h>
#include<math.h>


void selectionSort(int arr[], long int n);
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
		arr1[m] = rand() % 100;		
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
    	selectionSort(arr1, 100);
	e = clock();  
	/*printf("Sorted array: \n");  
	for (i = 0; i < 100; i++)  
	{
		printf("%d \n",arr1[i]);
	}*/
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("random to ascending%f \n",cpu_time_used);

	s = clock();	
    	selectionSort(arr1, 100);
	e = clock(); 
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to ascending%f \n",cpu_time_used);

	s = clock();	
    	rev_selectionSort(arr1, 100);
	e = clock(); 
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to descending%f \n",cpu_time_used);

	printf("\n For 1000 elements ------------------------------------------------------------\n");

	s = clock();	
	selectionSort(arr2, 1000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("random to ascending %f \n",cpu_time_used);

	s = clock();	
	selectionSort(arr2, 1000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to ascending %f \n",cpu_time_used);

	s = clock();	
	rev_selectionSort(arr2, 1000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to descending %f \n",cpu_time_used);
	
	printf("\n For 10000 elements -----------------------------------------------------------\n");

	s = clock();	
	selectionSort(arr3, 10000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("random to ascending %f \n",cpu_time_used);

	s = clock();	
	selectionSort(arr3, 10000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to ascending %f \n",cpu_time_used);

	s = clock();	
	rev_selectionSort(arr3, 10000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to descending %f \n",cpu_time_used);

	printf("\n For 100000 elements ----------------------------------------------------------\n");

	s = clock();	
	selectionSort(arr4, 100000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("random to ascending %f \n",cpu_time_used);

	s = clock();	
	selectionSort(arr4, 100000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to ascending %f \n",cpu_time_used);

	s = clock();	
	rev_selectionSort(arr4, 100000);
	e = clock();  
	cpu_time_used = ((double)(e-s))/CLOCKS_PER_SEC;
	printf("ascending to descending %f \n",cpu_time_used);
	 
}


void selectionSort(int a[] , long int n)
{
	int i,j,min;
	   	
	for(i=0;i<n;i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min = j;				
				
			}
		}

	  
		int temp;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;	
	}
}

void rev_selectionSort(int a[] , long int n)
{
	int i,j,max;
	   	
	for(i=0;i<n;i++)
	{
		max = i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]>a[max])
			{
				max = j;				
				
			}
		}

	  
		int temp;
		temp = a[i];
		a[i] = a[max];
		a[max] = temp;	
	}
}
