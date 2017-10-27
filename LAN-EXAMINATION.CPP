#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>
#include "registration.h"
void grap(int, int);
void open(int, int*);
void detect(int**, int);
void opengraphic();


void main()
{
    REGS in, out;
    struct regss {
        char name[20];
        char clg_name[20];
        char roll[15];
        char pass[20];
    };
    int choice, check = 0, count = 0;
    ;
    int ans[5] = { 10, 10, 10, 10, 10 };
    FILE* f;
    clrscr();
    registration();
    getch();
    clrscr();
    printf("\n INstruction\n for next Question press-> or |^\n for privious Question press <- ok");
    printf("\n there is no minuss marking in examination");
    printf("\n u must have to ans each Question");
    printf("\n enter your choice\n");
    printf("\n press (1) for conduct examand to exit press ESC");
    scanf("%d", &choice);
    clrscr();
    struct regss n, r;

    printf("\n enter your name");
    fflush(stdin);
    gets(n.name);
    printf("\n enter your collge");
    gets(n.clg_name);
    printf("\n enter roll no.");
    gets(n.roll);

    printf("\n eter passward");
    gets(n.pass);
    f = fopen("c:\\turboc3\\data.txt", "rb");
    if (f == NULL) {
        printf("\nfile not open");
        getch();
        exit(1);
    }
    fread(&r, sizeof(struct regss), 1, f);
    if ((strcmp(r.name, n.name)) == 0 && (strcmp(r.clg_name, n.clg_name) == 0) && (strcmp(r.roll, n.roll) == 0) && (strcmp(r.pass, n.pass) == 0)) {
        printf("\n data match \n you can appear in exam");
    }
    else {
        printf("\nyou are not appear inexam");
        getch();
        exit(1);
    }
    fclose(f);
    while (1) {
        switch (choice) {
        case 1: {
            open(check, ans);
            break;
        }
        default: {
            printf("\n u not interested to do exam \n thank u");
            getch();
            exit(1);
        }
        }
        closegraph();
        printf("\npress ->or<- key for next questionand esc for exit exam");
    hello:
        in.h.ah = 0;
        int86(22, &in, &out);
        if (out.h.ah == 72 || out.h.ah == 77) {
            if (check != 4)
                check++;
        }
        else if (out.h.ah == 75 || out.h.ah == 80) {
            if (check != 1)
                --check;
        }
        else if (out.h.ah == 1) {
            printf("\n  enter for result");

            getch();
            if (ans[0] == 10) {
                printf("\nQ.1 you not answered");
                count++;
            }
            if (ans[1] == 10) {
                printf("\nQ.2 not answered");
                count++;
            }
            if (ans[2] == 10) {
                printf("\n Q.3 not answered");
                count++;
            }
            if (ans[3] == 10) {
                printf("\n Q.4 not answered");
                count++;
            }
            printf("\n total %d you answered %d ", 4, 4 - count);
            printf("\n do u want to know your ans press y/n");
            if (getch() == 'y') {

                if (ans[0] != 10)
                    printf("\nQ1 st ans is %d", ans[0]);
                if (ans[1] != 10)
                    printf("\nQ2 nd ans is %d", ans[1]);
                if (ans[2] != 10)
                    printf("\nQ3rd ans is %d", ans[2]);
                if (ans[3] != 10)
                    printf("\nQ4 th ans is %d\n thank u", ans[3]);
            }

            getch();
            exit(1);
        }
        else {
            outtextxy(300, 300, "please please follow instruction");
            goto hello;
        }
    }
}

/*void grap(int r,int c)
{
union REGS in,out;
in.h.ah=0x02;
in.h.bh=0;
in.h.dh=r;
in.h.dl=c;
int86(16,&in,&out);
} */
void opengraphic()
{
    int gd = DETECT, gm;
    int result;
    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    result = graphresult();
    if (result != 0) {
        printf("%s", grapherrormsg(result));
        getch();
        exit(1);
    }
}

void open(int check, int* p)
{

    FILE* fp;

    char ch;
    switch (check) {
    case 0: {
        opengraphic();

        fp = fopen("AA.cpp", "r");
        while ((ch = fgetc(fp)) != EOF) {

            printf("%c", ch);
        }
        fclose(fp);
        detect(&p, check);

        break;
    }
    case 1: {

        opengraphic();
        fp = fopen("BB.cpp", "r");
        while ((ch = fgetc(fp)) != EOF) {

            printf("%c", ch);
        }
        fclose(fp);
        detect(&p, check);
        break;
    }
    case 2: {
        opengraphic();
        fp = fopen("CC.cpp", "r");
        while ((ch = fgetc(fp)) != EOF) {

            printf("%c", ch);
        }
        fclose(fp);
        detect(&p, check);
        break;
    }
    case 3: {

        opengraphic();
        fp = fopen("DD.cpp", "r");
        while ((ch = fgetc(fp)) != EOF) {

            printf("%c", ch);
        }
        fclose(fp);
        detect(&p, check);
        break;
    }

    default: {
        break;
    }
    }
}

void detect(int** q, int check)
{
    char arr[20];
    int r;
    union REGS in, out;

    outtextxy(20, getmaxy() - 200, "1.");
    circle(getmaxx() - 600, getmaxy() - 200, 4);
    outtextxy(20, getmaxy() - 150, "2.");
    circle(getmaxx() - 600, getmaxy() - 150, 4);
    outtextxy(20, getmaxy() - 100, "3.");
    circle(getmaxx() - 600, getmaxy() - 100, 4);

    in.x.ax = 0;

    int86(0x33, &in, &out);
    if (out.x.ax == 0) {
        outtextxy(400, 400, "fail to initialize");
        return;
    }
    else {
    him:
        in.x.ax = 1;
        int86(0x33, &in, &out);
        while (1) {
            in.x.ax = 3;
            int86(0x33, &in, &out);

            if (out.x.bx == 1) {
                if ((out.x.cx >= 35 && out.x.cx <= 43) && (out.x.dx >= 275 && out.x.dx <= 283)) {
                    *(*q + check) = 1;
                    return;
                }
                else if ((out.x.cx >= 35 && out.x.cx <= 43) && (out.x.dx >= 325 && out.x.dx <= 333)) {
                    *(*q + check) = 2;
                    return;
                }
                else if ((out.x.cx >= 35 && out.x.cx <= 43) && (out.x.dx >= 375 && out.x.dx <= 383)) {
                    *(*q + check) = 3;
                    return;
                }
                else {
                    outtextxy(390, 300, "please select inside circle");
                    goto him;
                }
            }
            delay(100);
        }
    }
}
