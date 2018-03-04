#include <stdio.h>
#define STRLEN 100
char *strcat(char *s, char *t) {
  char *ret = s;  // Return variable.

  // Move s to the end of string.
  for (; *s != '\0'; ++s)
    ;

  // Append t to s.
  for (; *t != '\0'; ++s, ++t) {
    *s = *t;
  }

  // Append null terminator.
  *s = '\0';

  return ret;
}

int main() {
  char data[3][2][STRLEN] = {
      {"Hello, ", "World"}, {"Tom", "&Jerry"}, {"George ", "Orwell"}};

  int i;
  for (i = 0; i < 3; i++) {
    printf("\"%s\" + \"%s\" = ", data[i][0], data[i][1]);
    printf("\"%s\"\n", strcat(data[i][0], data[i][1]));
  }
  return 0;
}
