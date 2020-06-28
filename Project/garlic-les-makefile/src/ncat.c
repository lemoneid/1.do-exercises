#include <stdio.h>
#include "roman.h"
#include <stdio.h>

int main(int argc, char *argv[]){
    if (argc == 1) return 0;
    int type  = (argv[1][1] == 'd');
    FILE *in_fp =stdin;
    FILE *out_fp = stdout;
    if (argc >= 3) {
        in_fp = fopen(argv[2],"r");
    }
    if (argc == 4) {
        out_fp = fopen(argv[3], "w");
    }
    char str[1000];
    int line_num = 1;
    while (fscanf(in_fp, "%[^\n]s", str) != EOF) {
        fgetc(in_fp);
        if (type) {
            fprintf(out_fp, "%d\t%s\n", line_num, str);
            line_num += 1;
        } else {
            char dst[25];
            to_roman_numeral(dst, line_num);
            fprintf(out_fp, "%s\t%s\n", dst, str);
            line_num += 1;
        }
        str[0] = 0;
    }
    fclose(in_fp);
    fclose(out_fp);
	return 0;
}

