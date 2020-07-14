#include <stdio.h>
#include <stdlib.h>

static FILE *open_file (char *file_name, char *mode) {
    FILE *fp = fopen(file_name, mode);
    if (fp == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

void confirm_args(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <readfile> <writefile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
}

int read_int(char *file_name) {
    int num = 0;
    FILE *in = open_file(file_name, "rb");
    for (int i = 0; i < 4; i++) {
        num |= (unsigned int) getc(in) << (i * 8);
    }

    fclose(in);
    return num;
}

void copy_file_content(char *src_file, char *dest_file) {
    int ch;
    FILE *in;
    FILE *out;

    in = open_file(src_file, "r");
    out = open_file(dest_file, "w");
    
    while((ch = fgetc(in)) != EOF) {
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
}

void sprintf_sscanf() {
    char name[20], new_sentence[50], sentence[] = "lilo is 12 years old";
    int age, char_number;

    sscanf(sentence, "%s %*s %d", name, &age);
    char_number = sprintf(new_sentence, "%s age is %d.", name, age);
    printf("[%s] is a %d char long string\n", new_sentence, char_number);
}

int main(int argc, char *argv[]) {
    confirm_args(argc, argv);
    copy_file_content(argv[1], argv[2]);
    printf("%x\n", read_int(argv[1]));
    sprintf_sscanf();
    return EXIT_SUCCESS;
}
