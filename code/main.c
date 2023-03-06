# include <stdio.h>
# include <time.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <sqlite3.h>

# define MAX_CHAR 100
# define TOTAL 10
# define MIN_CATALOG 1
# define MAX_CATALOG 1010


sqlite3 *dbHandler;
unsigned short int score = 0;


int randomNumber(unsigned short int max, unsigned short int min){
    return rand() % max + min;
}

void removeSpacesFromEnd(char *str) {
    unsigned short int n = strlen(str)-1;
    while(1){
        if(*(str+n)!=' '){
            *((str+n)+1) = '\0';
            break;
        }
        n--;
    }
}

void titleCase(char *str){
    *str = toupper(*str);
    for(register unsigned short int i=1; *(str+i); ++i)
        *(str+i) = (*str+(i-1)==' ') ? toupper(*(str+i)) : tolower(*(str+i));
}

void hideSomeChar(char *str){
    unsigned short int n = strlen(str);
    unsigned short int index;
	for(register unsigned short int i=0; i<n/2-1; ++i){
        index = randomNumber(n-1, 1);
        if(*(str+index)==' '){
            i--;
            continue;
        }
	    *(str+index) = '_';
	}
}

void closeConnection(){
    sqlite3_close(dbHandler);
    exit(0);
}

int startGame(char *generated){
    char guess[MAX_CHAR];
    char hiddenChar[MAX_CHAR];

    strcpy(hiddenChar, generated);
    hideSomeChar(hiddenChar);

    printf("\n\t--Guess the pokemon--\n");
    printf("\t\t%s\n=> ", hiddenChar);
    scanf(" %[^\n]s", guess);

    removeSpacesFromEnd(guess);
    titleCase(guess);

    if(strcmp(generated, guess)!=0){
        printf("\n   [Boo...wrong idiot! It was: %s]\n\n", generated);
        return 0;
    }
    printf("\n\t  [Correct guess!]\n\n");
    score++;
    return 1;
}

int callback(void *data, int argc, char *argv[], char **azColName){
    startGame(argv[0]);
    return 1;
}

void start(){
    char query[MAX_CHAR];
    char *zErrMsg = 0;

    for(register unsigned short int i=0; i<TOTAL; ++i){
        sprintf(
            query,
            "SELECT Name FROM pokemonData WHERE Catalog='%d';",
            randomNumber(MAX_CATALOG, MIN_CATALOG)
        );
        sqlite3_exec(dbHandler, query, callback, "nothing", &zErrMsg);
    }
    printf("\t  [Your score: %d/%d]\n\n", score, TOTAL);
    score = 0;
}

int main(int argc, char *argv[]){
    time_t seed;
    time(&seed);
    srand(seed);

    printf("\n\t--Guess The Pokemon--\n\n");

    unsigned short int x = sqlite3_open("../database/pokemon.db", &dbHandler);

    if(x!=SQLITE_OK){
        fprintf(stderr, "Error: %s\n", sqlite3_errmsg(dbHandler));
        closeConnection(dbHandler);
    }
    unsigned short int n;
    char query[MAX_CHAR];

    while(1){
        printf("1. play\n2. quit\nenter your choice: ");
        scanf("%hu", &n);
        switch(n){
            case 1:
                start();
                break;
            case 2:
                closeConnection();
                exit(0);
            default:
                printf("\n[enter a valid choice idiot!]\n\n");
        }
    }
    return 0;
}