/*
 * Code write by STEGEN Thomas - 14-03-2016
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h> 

void* print (void* param) {
    char * phrase = (char *) param;
    while (1){
        sleep(1);
        printf("%s\n", phrase);
    }
    return NULL;
}

int main () {
	int i;
	pthread_t ThreadId[6];
    char parole[][5] = {"Le", "lion", "est", "mort", "ce", "soir"};
    
    for (i = 0; i < 6; ++i)
    {
        pthread_create(&ThreadId[i], NULL, &print,  (void**) &parole[i]);
    }
    
    while (1){
		sleep(1);
        printf("Le lion est mort ce soir!\n");
    }
    return 0;
} 
