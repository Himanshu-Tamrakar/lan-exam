#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void registration()
{
    FILE* fp;

    struct regs {
        char name[20];
        char clg_name[20];
        char roll_no[15];
        char pass[20];
    };
    char confirm[20];
    struct regs rn;
    printf("\n enter your name");
    gets(rn.name);
    printf("\n enter your collge");
    gets(rn.clg_name);
    printf("\n enter roll no.");
    gets(rn.roll_no);
pass:
    printf("\n eter passward");
    gets(rn.pass);
    printf("\n confirm");
    gets(confirm);
    if (strcmp(rn.pass, confirm) == 0) {
        printf("\n your passward creat");
    }
    else {
        printf("\n passward missmatch plesase enter again pass");
        goto pass;
    }
    fp = fopen("c:\\turboc3\\data.txt", "wb");
    if (fp == NULL) {
        printf("file is not open");
        getch();
        exit(1);
    }
    fwrite(&rn, sizeof(struct regs), 1, fp);
    fclose(fp);
}
