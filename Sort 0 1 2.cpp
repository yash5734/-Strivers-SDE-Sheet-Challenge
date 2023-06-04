#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int start =0;
   int end = n-1;
   int i=0;
   while(i<=end){
      if(arr[i] == 0){
         swap(arr[i++],arr[start++]);
      }
      else if(arr[i]==2){
         swap(arr[i],arr[end--]);
      }
      else if(arr[i]==1){
         i++;
      }
   }

}
