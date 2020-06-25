#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void f1(int, int, int);
void f2(char *);
void f3(char *, int);
void f4(int *, int);
void f5(int, int);

bool isPrime(int);

int main(int argc, char * argv[])
{
  int option = 0;
  int i, j, k;
  int * list;

  if(argc < 2 )
  {
     fprintf(stderr,"Usage: lab1 num [input]\n");
     fprintf(stderr,"num: 1, 2, 3, 4, or 5\n");
     exit(1);
  }

  option = atoi(argv[1]);

  switch(option)
  {
    case 1: if(argc != 5)
	    {
	      fprintf(stderr,"Usage: lab1 1 A B C\n");
	      fprintf(stderr,"A, B, and C: Positive integers where A <= B and C < B \n");
	      exit(1);
	    }
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    k = atoi(argv[4]);

	    f1(i, j, k);

	    break;


    case 2: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 2 filename\n");
	      fprintf(stderr,"filename: the name of the file containing the characters\n");
	      exit(1);
	    }

	    f2(argv[2]);

	    break;


    case 3: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 3 filename gen\n");
	      fprintf(stderr,"filename: the name of the file containing the characters\n");
	      fprintf(stderr,"gen: number of generations nonzero positive integer \n");
	      exit(1);
	    }

	    i = atoi(argv[3]);
	    f3(argv[2], i);

	    break;


    case 4: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 4 num\n");
	      fprintf(stderr,"num: nonzero positive integer = number of elements in the array\n");
	      exit(1);
	    }

	    i = atoi(argv[2]);
	    if(!(list = (int *)malloc(i*sizeof(int))))
	    {
	      fprintf(stderr,"Cannot allocate an integer array of %d elements\n", i);
	      exit(0);
	    }
	    for(j = 0; j < i; j++)
	    {
	      printf("enter element %d: ", j);
	      scanf("%d",&list[j]);
	    }

	    f4(list, i);

	    break;


    case 5: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 5 A B\n");
	      fprintf(stderr,"A B: positive nonzero integers where A <= B\n");
	      exit(1);
	    }

	    i = atoi(argv[2]);
	    j = atoi(argv[3]);

	    f5(i, j);

	    break;



    default: fprintf(stderr, "You entered an invalid option!\n");
	     exit(1);
  }

  return 0;
}

void f1(int start, int end, int incr)
{
    for (int i = start; i < end; i+=incr){
        printf(i);
    }
    printf(end);

}

void f2(char * filename)
{
    File *fptr, *fptr2;
    char *extension = ".reverse";
    char *filename2 = malloc(strlen(filename)+1+8);
    strcopy(filename2, filename);
    strcat(filename2, extension);
    char c;

    fptr = fopen(filename, "r");
    if (fptr == NULL){
        printf("Cannot open file");
        exit(0);
    }

    fptr2 = fopen(filename2, "w");
    if (fptr2 == NULL){
        printf("cannot write to this file");
        exit(0);
    }

    do
    {
        c = fgetchar(fptr);
        if (c >= 'A' && c <= 'Z'){
            tolower(c);
        } else if (c >= 'a' && c <= 'z') {
            toupper(c);
        } else if (isspace(c)) {
            c = ' ';
        }
        fputc(c, fptr2);
    }
    while (c! = EOF);

    fclose(fptr);
    fclose(fptr2);

}

void f3(char *filename, int gen)
{

    FILE * fptr = fopen(filename, "r");

    int array[3][3];
    for (int i=0; i<3; i++){
        for (int j =0; j < 3; j++){
            fscanf(fptr, "%1d", array[i][j]);
        }
    }

    int a[3] = {array[0][0], array[1][0], array[1][1]};
    int b[5] = {array[0][0], array[0][2], array[1][0], array[1][1], array[1][2]};
    int c[3] = {array[0][1], array[1][1], array[1][2]};
    int d[5] = {array[0][0], array[0][1], array[1][1], array[2][0], array[2][1]};
    int e[8] = {array[0][0], array[0][1], array[0][2], array[1][0], array[1][2], array[2][0], array[2][1], array[2][2]};
    int f[5] = {array[0][1], array[0][2], array[1][1], array[2][1], array[2][2]};
    int g[3] = {array[1][0], array[1][1], array[2][1]};
    int h[5] = {array[1][0], array[1][1], array[1][2], array[2][0], array[2][2]};
    int k[3] = {array[1][1], array[1][2], array[2][1]};

    int newArr[3][3];

    for (int i = 0; i < gen; i++){
        for (int i = 0; i < 9; i ++){
            if (i = 0){
                int count = 0;
                for (int j = 0; j < 3; j++){
                    if ((a[j]) == 1){
                        count++;
                    }
                }
                if (count == 2 || count == 3){
                    newArr[0][0] = 1;
                } else {
                    newArr[0][0] = 0;
                }
            }
            if (i = 1){
                int count = 0;
                for (int j = 0; j < 5; j++){
                    if ((b[j]) == 1){
                        count++;
                    }
                }
                if (count == 2 || count == 3){
                    newArr[0][1] = 1;
                } else {
                    newArr[0][1] = 0;
                }
            }
            if (i = 2){
                int count = 0;
                for (int j = 0; j < 3; j++){
                    if ((c[j]) == 1){
                        count++;
                    }
                }
                if (count == 2 || count == 3){
                    newArr[0][2] = 1;
                } else {
                    newArr[0][2] = 0;
                }
            }
            if (i = 3){
                int count = 0;
                for (int j = 0; j < 5; j++){
                    if ((d[j]) == 1){
                        count++;
                    }
                }
                if (count == 2 || count == 3){
                    newArr[1][0] = 1;
                } else {
                    newArr[1][0] = 0;
                }
            }
            if (i = 4){
                int count = 0;
                for (int j = 0; j < 8; j++){
                    if ((e[j]) == 1){
                        count++;
                    }
                }
                if (count == 2 || count == 3){
                    newArr[1][1] = 1;
                } else {
                    newArr[1][1] = 0;
                }
            }
            if (i = 5){
                int count = 0;
                for (int j = 0; j < 5; j++){
                    if ((f[j]) == 1){
                        count++;
                    }
                }
                if (count == 2 || count == 3){
                    newArr[1][2] = 1;
                } else {
                    newArr[1][2] = 0;
                }
            }
            if (i = 6){
                int count = 0;
                for (int j = 0; j < 3; j++){
                    if ((g[j]) == 1){
                        count++;
                    }
                }
                if (count == 2 || count == 3){
                    newArr[2][0] = 1;
                } else {
                    newArr[2][0] = 0;
                }
            }
            if (i = 7){
                int count = 0;
                for (int j = 0; j < 5; j++){
                    if ((h[j]) == 1){
                        count++;
                    }
                }
                if (count == 2 || count == 3){
                    newArr[2][1] = 1;
                } else {
                    newArr[2][1] = 0;
                }
            }
            if (i = 8){
                int count = 0;
                for (int j = 0; j < 3; j++){
                    if ((k[j]) == 1){
                        count++;
                    }
                }
                if (count == 2 || count == 3){
                    newArr[2][2] = 1;
                } else {
                    newArr[2][2] = 0;
                }
            }
        }

        for (row = 0; row < 3; row++){
            for (col = 0; col < 3; col++){
                array[row][col] = newArr[row][col];
            }
        }

    }

    int row, col;
    for (row = 0; row < 3; row++){
        for (col = 0; col < 3; col++){
            printf("%d ", )
        }
    }
}

void f4(int * num, int n)
{
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (num[i] < num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for (int i =0; i<n; i++){
        printf("%d", num[i]);
    }
    printf("\n");

}

void f5(int a, int b)
{
    printf(a);
    for (int i = a+1; i < b; i++){
        if (isPrime(i)){
            printf(i);
        }
    }
    printf(b);
    printf("\n");
}

bool isPrime(int n);
{

    if (n <= 1){
        return false;
    }
    if (n % 2 == 0 && n > 2){
        return false;
    }
    for (int i = 3; i<n/2; i+=2){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}
