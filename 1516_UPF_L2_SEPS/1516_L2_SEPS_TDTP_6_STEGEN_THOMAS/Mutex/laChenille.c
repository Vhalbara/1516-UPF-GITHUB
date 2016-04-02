#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define SLEEPTIME 3
#define NB_JOB_REFILL 3
#define NB_WORKERS 3

int flag = 0;

typedef struct Job{
	int a;
	int b;
	int jobIndex;
	struct Job *svt;
}Job;

typedef struct{
	Job* pfirst;
	int nbjob;

	pthread_t provider;
	pthread_t worker[NB_WORKERS];
	pthread_mutex_t mutexJob; 
	pthread_cond_t condNbrJob;
	pthread_cond_t condWorker;
}List;

typedef struct{
	int threadIndex;
	List *list;
}Parameters;

int RANDOM(a,b) {
	return rand()%(b-a)+a;
}

Job* createJob(){
	Job *job = (Job*) malloc(sizeof(Job));
	
	job->a = RANDOM(5,2000);
	job->b = RANDOM(5,2000);
	job->jobIndex = 0;
	job->svt = NULL;
	
	return job;
}

Job* createListJobs(int n){
	int i;
	Job *pfirst, *cur;
	pfirst = cur = createJob();
	if(pfirst != NULL){
		cur->jobIndex = 1;
		for(i=1;i<n;++i){
			cur->svt = createJob();
			cur->svt->jobIndex = cur->jobIndex+1;
			cur = cur->svt;
		}
	}
	return pfirst;
}

Job* extractJob(List* list){
	Job *cur = list->pfirst;
	list->pfirst = cur->svt;
	return cur;
}

int makeMyJob(Job* job){
	printf("Job n°%d : %d + %d = %d.\n", job->jobIndex,job->a,job->b,job->a+job->b);
	free(job);
}

void* providerFunction (void* param){
	List *list = (List*) param;
	flag = 1;
	while(1){
		printf("Provider trying to lock Mutex ... ");
		pthread_mutex_lock(&(list->mutexJob));
		printf("Mutex locked by provider.\n");
		pthread_cond_wait(&list->condNbrJob,&list->mutexJob);
		printf("Asking for refill ... Provider activation !\n");
		if (list->pfirst == NULL){
			int refill = RANDOM(NB_JOB_REFILL,2*NB_JOB_REFILL);
			list->pfirst = createListJobs(refill);
			printf("Provider : Added %d jobs to the job list !\n",refill);	
		}

		pthread_cond_signal(&list->condWorker);
		printf("Provider : Notifying workers.\n");
		pthread_mutex_unlock(&list->mutexJob);
		printf("Provider : Releasing Mutex.\n");
	}
}

void* workerFunction (void* param){
	Parameters *parameters = (Parameters*) param ;
	while(1){
		printf("Worker trying to lock Mutex ... ");
		pthread_mutex_lock(&(parameters->list->mutexJob));
		printf("Mutex locked by worker.\n");
		
		if (parameters->list->pfirst == NULL){
			pthread_cond_signal(&parameters->list->condNbrJob);
			pthread_cond_wait(&parameters->list->condWorker,&parameters->list->mutexJob);
		}
		printf("Extracting job...");
		Job * extract = extractJob(parameters->list);
		printf("Job obtained, releasing Mutex\n");
		pthread_mutex_unlock(&parameters->list->mutexJob);
		printf("-----------------------------------------\n");
		printf("Mutex released, processing job:\n");
		makeMyJob(extract);
		printf("-----------------------------------------\n");	
		// Pause de durée aléatoire
		sleep(RANDOM(1,1+SLEEPTIME));
	}
}

int main(int argc, char *argv[]) {
	int ret,i;
	List list;
	list.pfirst = NULL;
	Parameters parameters[NB_WORKERS];
	pthread_mutex_init(&list.mutexJob, NULL);  
	pthread_cond_init(&list.condNbrJob, NULL);
	pthread_cond_init(&list.condWorker, NULL); 
	printf("Creation of provider's thread: \n");
	ret = pthread_create(&list.provider,NULL,&providerFunction, &list);
	
	if(!ret){
		printf("ok \n");
		while(!flag);
		printf("creation of workers thread: \n");
		
		for(i=0;i<NB_WORKERS;++i){
			parameters[i].threadIndex = i+1;
			parameters[i].list = &list;
			printf("Creating worker's thread n%c%d... ",'°',i+1);
			ret = pthread_create(&list.worker[i],NULL,&workerFunction, &parameters[i]);
			if(ret) printf("Error !\n");
			else printf("OK !\n");
		}
	}
	else
		printf("Error creating provider's thread.\n");

	for(i=0;i<NB_WORKERS;++i){
		pthread_join(list.worker[i],NULL);
	}
	pthread_join(list.provider,NULL);
	return EXIT_SUCCESS;
}

