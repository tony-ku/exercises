/*
Reduce Array Size to The Half

You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
 

Constraints:

2 <= arr.length <= 105
arr.length is even.
1 <= arr[i] <= 105
*/

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int minSetSize(int* arr, int arrSize) {
    int lookup[100000+1] = {0};
    int max_freq[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        lookup[arr[i]]++;
    }
    int k = 0;
    for (int i = 0; i < 100000+1; i++)
    {
        if (lookup[i])
            max_freq[k++] = lookup[i];
    }
    
    qsort(max_freq, k, sizeof(int), compare);

     int count = 0;
     int val = 0;
     for (int i = 0; i < k; i++)
     {
         val += max_freq[i];
         count++;
         //printf ("val: %d count: %d\n", val, count);
         if (val >= arrSize/2)
             break;
     }
    return count;
}