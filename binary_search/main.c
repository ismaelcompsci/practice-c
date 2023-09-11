#include <stdio.h>

int binary_search(int *haystack, int needle, int len);
int r_binary_search(int *haystack, int needle, int min, int max);

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // sorted array
    int found = binary_search(numbers, 8, 10);
    int recur = r_binary_search(numbers, 10, 0, 9);

    printf("Found %s\n", found == 0 ? "true" : "false");
    printf("RE Found %s\n", recur == 0 ? "true" : "false");

    return 0;
}

int binary_search(int *haystack, int needle, int len)
{

    int max = len - 1;
    int min = 0;

    while (min < max)
    {
        int mid = min + (max - min) / 2;
        if (haystack[mid] == needle)
            return 0;
        if (haystack[mid] < needle)
            min = mid + 1;
        else
            max = mid - 1;
    };

    return 1;
}

int r_binary_search(int *haystack, int needle, int min, int max)
{
    if (max < min)
        return -1;

    int mid = min + (max - min) / 2;

    if (haystack[mid] < needle)
        return r_binary_search(haystack, needle, mid + 1, max);
    else if (haystack[mid] > needle)
        return r_binary_search(haystack, needle, min, mid - 1);
    return 0;
}
