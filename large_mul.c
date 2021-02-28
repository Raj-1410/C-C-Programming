#include<stdio.h>
#include<stdlib.h> 
#include<string.h>


void multiply(char *num1, char *num2) 
{ 
	int len1 = strlen(num1); 
	int len2 = strlen(num2); 
	int c = 0;
	int result[len1 + len2]; 
	
	for(int k; k<len1+len2; k++)
	{
		result[k]=0;
	}
	
	int i_n1 = 0; 
	int i_n2 = 0; 	
	
	for (int i=len1-1; i>=0; i--) 
	{ 
		int carry = 0; 
		int n1 = num1[i] - '0'; 

		i_n2 = 0; 
		
		for (int j=len2-1; j>=0; j--) 
		{ 
			int n2 = num2[j] - '0'; 

			int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
			carry = sum/10; 
			result[i_n1 + i_n2] = sum % 10;
			i_n2++; 
		} 

		if (carry > 0) 
			c++;
			result[i_n1 + i_n2] += carry; 
		i_n1++; 
	} 

	for (int j=i_n1+i_n2-c; j>=0; j--) 
	{
		 printf("%d",result[j]);
	}
} 


void main() 
{ 
	char *str1, *str2;	
	str1 = "1234567890"; 
	str2 = "1234567890"; 
	
	multiply(str1, str2); 
	 
}
