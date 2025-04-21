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
            while (left < right && arr[left] == arr[left + 1]) ++left;
            while (left < right && arr[right] == arr[right - 1]) --right;
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


int B_search(int* arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        if (complement >= arr[i]) {
            if (B_search(arr, i + 1, len - 1, complement) != -1) {
                ++count;
            }
        }
    }
    return count;
}
