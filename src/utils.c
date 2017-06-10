

int utils_int_max(int * list, int len) {
  int max = list[0];

  for (int i = 1; i < len; i ++) {
    if (max < list[i]) {
      max = list[i];
    }
  }

  return max;
}

int utils_strlen_max(const char **list, int len) {
  int max = strlen(list[0]);

  for (int i = 1; i < len; i ++) {
    int slen = strlen(list[i]);

    if (max < slen) {
      max = slen;
    }
  }

  return max;
}

int utils_max(int left, int right) {
  return left > right ? left : right;
}