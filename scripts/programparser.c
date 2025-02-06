#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGHT 512

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  };

  char *inputname = argv[1];
  FILE *input = fopen(inputname, "r");
  char *tk = strtok(inputname, ".");
  char *outputname = strcat(tk, ".c");
  FILE *output = fopen(outputname, "w");

  char line[LINE_LENGHT];
  while (strstr(line, "<Program>") == NULL) {  // Skip until <Program>
    if (fgets(line, sizeof(char) * LINE_LENGHT, input) == NULL) {
      fprintf(stderr, "Error: <Program> not found\n");
      return 1;
    }
  }

  while (input != NULL) {
    if (fgets(line, sizeof(char) * LINE_LENGHT, input) == NULL) {
      fprintf(stderr, "Error: <EndProgram> not found\n");
      return 1;
    }

    if (strstr(line, "<EndProgram>") != NULL) break;

    fprintf(output, "%s", line);
  }
  fclose(output);
  fclose(input);
  return 0;
}