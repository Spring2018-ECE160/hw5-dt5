#include <stdio.h>
#define STRLEN 100

int strend(char *s, char *t) {
  int si, ti;

  // Find the end of s.
  for (si = 0; s[si] != '\0'; si++)
    ;
  // Find the end of t.
  for (ti = 0; t[ti] != '\0'; ti++)
    ;

  // Compare.
  while (1) {
    if (s[si] != t[ti]) {
      return 0;
    } else if (ti == 0) {
      return 1;
    } else if (si == 0) {
      break;
    }

    si--;
    ti--;
  }

  return 0;
}

int main() {
  char data[3][2][STRLEN] = {
      {"Corruption", "ion"}, {"Software", "tare"}, {"chrome", "monochrome"}};

  int i;
  for (i = 0; i < 3; i++) {
    printf("\"%s\" %s \"%s\".\n", data[i][0],
           strend(data[i][0], data[i][1]) ? "ends with" : "does not end with",
           data[i][1]);
  }
}
