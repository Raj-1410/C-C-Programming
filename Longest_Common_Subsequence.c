#include<stdio.h> 
#include<string.h>
  
int max(int a, int b); 
void lcs( char *X, char *Y, int m, int n ); 
int len( char *X, char *Y, int m, int n );   

void main() 
{ 
  char X[] = "GXTXAYB"; 
  char Y[] = "AGGTAB"; 
  //char X[] = "ACH"; 
  //char Y[] = "ABCH";   

  int m = strlen(X); 
  int n = strlen(Y); 
  lcs( X, Y, m, n ); 
  int l = len( X, Y, m, n );
  printf("\nLength = %d",l);
} 

void lcs( char *X, char *Y, int m, int n ) 
{
	int Z[m+1][n+1];
	for(int i=0;i<m+1;i++)
	{//printf("\n");
		for(int j=0; j<n+1; j++)
		{
			Z[i][j]=0;
		}
	}

	
     		
	for(int i=0;i<m;i++)
	{	for(int j=0; j<n; j++)
		{
			if(X[i] == Y[j])
			{
					
				Z[i+1][j+1] = 1 + Z[i][j];
			}
			else
			{
				Z[i+1][j+1] = max(Z[i+1][j],Z[i][j+1]);

			}

		}
	}


	/*for(int i=0;i<m+1;i++)
	{printf("\n");
		for(int j=0; j<n+1; j++)
		{
			printf("%d",Z[i][j]);
		}
	}*/

			printf("LCS is : ");

	for(int i=m-1;i>=0;i--)
	{
		for(int j=n-1; j>=0; j--)
		{
			if(X[i]==Y[j])
				{
					printf("%c",X[i]);
					i=i-1;
					
				}
			else
			{
				if(Z[i+1][j+1]==Z[i+1][j])
				{continue;}
				else
				{i=i-1; 
				 j=j+1;
				}
			}
	
		}
	}

}


int len( char *X, char *Y, int m, int n ) 
{ 
   if (m == 0 || n == 0) 
	    {
     return 0; }
   if (X[m-1] == Y[n-1]) 
     return 1 + len(X, Y, m-1, n-1);
	 
   else
     {
     return max(len(X, Y, m, n-1), len(X, Y, m-1, n)); }
} 
  

int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  


