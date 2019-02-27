#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <ctype.h>
char* read_file(const char* filename)
{
    FILE* f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        return NULL;
    }
    struct stat s;
    fstat(fileno(f), &s);
    char* buffer = malloc(s.st_size + 1);
    fread(buffer, s.st_size, 1, f);
    buffer[s.st_size] = '\0';
    fclose(f);
    return buffer;
}


//You also need some way to describe your records. This depends on your records to be honest. If your records are hardcoded, you can index it with enums. If you are writing a lexer definition file, then each record key is probably new and unique. For this you'll need to store it in a string:

typedef struct {
    char* key;
    char* def;
} lex_define;


//Then create a parsing loop to parse each define:
int parse_lexdefines(char* buffer, lex_define* defs, int maxdefs)
{
    int count = 0;
    char* str = buffer, *end;
    while (count < maxdefs && (end = strchr(str, '\n'))) {
        parse_keyval(str, end, &defs[count++]);
        str = end+1;
    }
    return count;
}


//Then you need to tokenize key and def out of the string:
char* trim(char* str, char* end) {
    while (isspace(*str)) ++str;
    while (isspace(*--end));
    end[1] = '\0';
    return str;
}
void parse_keyval(char* str, char* end, lex_define* def)
{
    char* sep = strstr(str, "::=");
    if (!sep) {
        fprintf(stderr, "parse error, missing ::=\n");
        def->key = def->def = NULL;
        return;
    }
    def->key = trim(str, sep);
    def->def = trim(sep + 3, end);
}


//Finally, this is the main entrypoint:
int main(int argc, char** argv)
{
    char* buffer = read_file("lex.txt");
    if (!buffer) return -1;
    lex_define defs[128];
    int count = parse_lexdefines(buffer, defs, 128);

    for (int i = 0; i < count; i++)
        printf("key %10s => def %s\n", defs[i].key, defs[i].def);
    free(buffer);
    return 0;
}
