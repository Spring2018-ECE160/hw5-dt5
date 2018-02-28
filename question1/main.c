#include <ctype.h>
#include <stdio.h>

int getfloat(float *pf) {
  char c;
  int sign;

  while (isspace(c = getc(stdin)))  // Skip white spaces.
    ;

  if (!isdigit(c) && c != '+' && c != '-' && c != '.') {
    ungetc(c, stdin);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;

  if (c == '+' || c == '-') c = getc(stdin);

  for (*pf = 0; isdigit(c); c = getc(stdin)) {
    *pf = 10 * *pf + (c - '0');
  }

  if (c == '.') {
    c = getc(stdin);
    float digit;
    for (digit = 0.1; isdigit(c); c = getc(stdin)) {
      *pf += digit * (c - '0');
      digit /= 10.0;
    }
  }

  *pf *= sign;

  ungetc(c, stdin);

  return c;
}

int main() {
  float f;
  while (getfloat(&f)) {
    printf("%f\n", f);
    char c = getc(stdin);
    if (c == EOF) {
      break;
    } else {
      ungetc(c, stdin);
    }
  }
  return 0;
}
