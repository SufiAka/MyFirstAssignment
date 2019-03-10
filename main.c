#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateNumberOfOperations(FILE *f);

int main(int argc, char *argv[])
{
    FILE *f;

    if(argc == 3)
    {
        f = fopen(argv[1], "w");

        if(f == NULL) {
        printf("Error! Can't open the file %s", argv[1]);
        return 1;
        }
        fprintf(f, "1756130\n");

        int n;
        sscanf(argv[2], "%d", &n);

        for(int i = 0; i<n; i++)
        {
            int res = generateNumberOfOperations(f);
            fprintf(f, " = %d\n", res);
        }
    }
    fclose(f);

    return 0;
}


int generateNumberOfOperations(FILE *f){
    int number = rand()%2 + 3;
    int c = 0;


    for(int i = 0; i < number; i++){
        int operation = rand()%4 + 1;
        int a = rand()%101;
        int b = rand()%101;

        switch(operation)
        {
        case 1:
            if(i == 0)
            {
                fprintf(f, "%d + %d", a, b);
            }
           if(i != 0){
            a = c;
            fprintf(f, " + %d", b);}
            c=a+b;
            break;
        case 2:
            if(i == 0)
            {
                fprintf(f, "%d - %d", a, b);
            }
           if(i != 0){
            a = c;
            fprintf(f, " - %d",b);}
            c=a-b;
            break;
        case 3:
            if(i == 0)
            {
                fprintf(f, "%d * %d", a, b);
            }
           if(i != 0){
            a = c;
            fprintf(f, " * %d", b);}
            c=a*b;
            break;
        case 4:
             if(i == 0)
            {
                fprintf(f, "%d / %d", a, b);
            }
           if(i != 0){
            a = c;
            fprintf(f, " / %d", b);}
            c=a/b;
            break;
        default:
            break;
        }
    }

    return c;
}
