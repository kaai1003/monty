#include "monty.h"

void open_file (char *file)
{
    FILE *jv = fopen(file, "r");
    if (file == NULL || jv == NULL)
        err(3, file);
    read_file(jv);
    fclose(jv);
}

/*Betty doc*/

void read_file(FILE *jv)
{
    int line_num, format = 0;
    char *buffer = NULL;
    size_t len = 0;
    for (line_num = 1; getline(&buffer, &len, jv) != -1; line_num++)
    {
        format = parse_line(buffer, line_num, format);
    }
    free(buffer);
}

