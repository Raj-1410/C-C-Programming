#include <stdio.h> 
#include <string.h> 
#include <limits.h> 
#define R 4 
#define C 5 
  
int arrSum(int* arr, int* start, int* finish, int n) 
{ 
    int sum = 0, maxSum = INT_MIN, i; 
  
    *flag = -1; 
  
    int local_start = 0; 
  
    for (i = 0; i < n; ++i) 
    { 
        sum += arr[i]; 
        if (sum < 0) 
        { 
            sum = 0; 
            local_start = i+1; 
        } 
        else if (sum > maxSum) 
        { 
            maxSum = sum; 
            *start = local_start; 
            *flag = i; 
        } 
    } 
  
   if (*flag != -1) 
        return maxSum; 
  
    maxSum = arr[0]; 
    *start = *flag = 0; 
  
    for (i = 1; i < n; i++) 
    { 
        if (arr[i] > maxSum) 
        { 
            maxSum = arr[i]; 
            *start = *flag = i; 
        } 
    } 
    return maxSum; 
} 
  

void maxSum(int M[][C]) 
{ 
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom; 
  
    int left, right, i; 
    int temp[R], sum, start, finish; 
  
    for (left = 0; left < C; ++left) 
    { 
        memset(temp, 0, sizeof(temp)); 
  
        for (right = left; right < C; ++right) 
        { 
           for (i = 0; i < R; ++i) 
                temp[i] += M[i][right]; 
  
            sum = arrSum(temp, &start, &finish, R); 
  
            if (sum > maxSum) 
            { 
                maxSum = sum; 
                finalLeft = left; 
                finalRight = right; 
                finalTop = start; 
                finalBottom = finish; 
            } 
        } 
    } 
  
  printf("Max sum is: %d\n", maxSum); 
} 
  
int main() 
{ 
    int M[R][C] = {{5, 3, -3, -5, -17}, 
                       {-6, -1, 8, 13, 11}, 
                       {13, 8, 11, -1, 9}, 
                       {-8, -2, 13, 3, -4} 
                      }; 
  
    maxSum(M); 
  
    return 0; 
} 
