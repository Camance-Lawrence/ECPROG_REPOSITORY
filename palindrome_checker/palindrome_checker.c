#include <stdio.h>


int isPalindrome(int *arr, int size)
{  
    int left = 0;
    int right=size-1;

    while (left < right)
    {
        if(arr[left] != arr[right])
        {
            return 0;
        }

        else
        {
            left++;
            right--;
        }
    }

    return 1;
}


int main()
{
    int size = 5;  
    int val = 0;
    int palarr1[5]={1,0,0,3,1};
    // int palarr2[5]={1,2,3,2,1};
    // int palarr3[5]={1,0,0,3,1};
    // int palarr4[5]={4,5,6,5,4};
    // int palarr5[5]={9,9,9,9,9};


    if(isPalindrome(palarr1, size))
    {
        printf("Palindrome\n");
    }

    else
    {
        printf("Not Palindrome\n");
    }



    return 0;
}