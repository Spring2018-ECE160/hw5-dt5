#include <stdio.h>
#define STRLEN 100

char *strncpy(char *s, const char *t, size_t n) {
  int i;
  int terminated = 0;
  for (i = 0; i < n; i++) {
    // Check if t is terminated.
    if (t[i] == '\0') terminated = 1;

    // Copy.
    s[i] = terminated ? 0 : t[i];
  }
  return s;
}

int main() {
  char source[STRLEN] = "CARTHAGO DELENDA A EST";
  printf("Source: %s\n", source);

  // Same length.
  char trial1[STRLEN];
  strncpy(trial1, source, STRLEN);
  printf("Length %d: %s\n", STRLEN, strncpy(trial1, source, STRLEN));

  // Length 3.
  char trial2[STRLEN];
  strncpy(trial2, source, 3);
  trial2[3] = '\0';
  printf("Length 3: %s\n", trial2);

  // Length 12.
  char trial3[STRLEN];
  strncpy(trial3, source, 12);
  trial3[12] = '\0';
  printf("Length 12: %s\n", trial3);

  return 0;
}
