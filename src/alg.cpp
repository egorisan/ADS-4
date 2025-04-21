// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value)
{
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }
    return count;
}
int countPairs2(int* arr, int len, int value)
{
    int count = 0;
    int left = 0, right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            ++count;
            ++left;
            --right;
        }
        else if (sum < value) {
            ++left;
        }
        else {
            --right;
        }
    }

    return count;
}


int B_search(int* data, int low, int high, int target) {
    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (data[mid] == target) {
            return mid;
        }
        else if (data[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1; 
        }
    }
    return -1;
}

int countPairs3(int* arr, int size, int targetSum)
{
    int pairCount = 0;

    for (int index = 0; index < size; ++index) {
        int complement = targetSum - arr[index];
        if (complement >= arr[index]) {
            if (B_search(arr, index + 1, size - 1, complement) != -1) {
                ++pairCount;
        }
    }
}

    return pairCount;
}
