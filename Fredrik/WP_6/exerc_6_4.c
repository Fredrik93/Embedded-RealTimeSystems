#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int program_time = 0; // The global time, start value 0
int flag = 1;

void *time_count(void *param);
void *read_inport(void *param);
double get_time_ms();
int get_time_s();

int main()
{

    pthread_t tid1;
    pthread_t tid2;

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    int amountOfSeconds = 5;

    // Start up the thread time_count.
    pthread_create(&tid1, &attr, time_count, NULL);
    //pthread_join(tid1, NULL);

    // Start up the thread read_inport.
    pthread_create(&tid2, &attr, read_inport, NULL);
    // pthread_join(tid2, NULL);

    while (program_time < 50)
    {
    }
}

void *time_count(void *param)
{
    double originTime = get_time_s();
    while (program_time < 50)
    {

        if (originTime < (get_time_s() + 1))
        {
            printf("origin time : %f time in ms : %d  program time : %d\n", originTime, get_time_s(), program_time);
            originTime += 1;
            program_time += 1;
            if (program_time % 5 == 0)
            {
                flag = 1;
            }
            // Check system-time ( get_time_ms())
            // Increase program_time by one every second.
        }
    }

    pthread_exit(0);
}
void *read_inport(void *param)
{
    while (program_time < 50)
    {
        if (program_time > 0 && flag == 1)
        {
            if (program_time % 5 == 0)
            {
                printf("read_inport read ! \n");
                flag = 0;
            }
            // Read Inport every 5 second.( Simulate
            //this just by print out a text : Reading Inport now)
        }
    }
    //  printf("%f read inport\n", get_time_ms());
    pthread_exit(0);
}

// --------Function get_time_ms --------------------
double get_time_ms()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    double result = (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
    return result;
}
int get_time_s()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    int result = t.tv_sec;
    return result;
}