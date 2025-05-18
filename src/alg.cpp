// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len - 1; i++)
    for (int j = i + 1; j < len; j++)
      if (arr[i] + arr[j] == value) k++;
  return k;
}

int countPairs2(int* arr, int len, int value) {
  int k = 0;
  int a = len - 1;
  while (a > 0) {
    if (arr[a] > value) {
      a--;
    } else {
      break;
    }
  }
  for (int i = 0; i < len; i++) {
    for (int j = a; j > i; j--) {
      if (arr[i] + arr[j] == value) k++;
    }
  }
  return k;
}

int countPairs3(int* arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; ++i) {
    int a = -1;
    int l = i + 1;
    int r = len - 1;
    int V = value - arr[i];
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (arr[m] >= V) {
        r = m - 1;
        if (arr[m] == V) a = m;
      } else {
        l = m + 1;
      }
    }
    if (a != -1) {
      int b = a;
      r = len - 1;
      l = a;
      
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] <= V) {
          l = m + 1;
          if (arr[m] == V) b = m;
        } else {
          r = m - 1;
        }
      }
      k += b - a + 1;
    }
  }
  return k;
}

