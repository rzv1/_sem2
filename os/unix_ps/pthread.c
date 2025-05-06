#include <pthread.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define N         8
#define MAX_STEAL 50

int valori[N];
atomic_int castigator = ATOMIC_VAR_INIT(-1);
pthread_mutex_t mtx[N];

static inline int min(int a, int b) { return a < b ? a : b; }

void *worker(void *arg)
{
    int id = (intptr_t)arg;
    unsigned int seed = time(NULL) ^ id;

    while (atomic_load_explicit(&castigator, memory_order_acquire) == -1) {
        int victim = id;
        while (victim == id)
            victim = rand_r(&seed) % N;

        int x = 1 + rand_r(&seed) % MAX_STEAL;

        /* lock-urile în ordine canonică pentru dead-lock-free */
        int first = id < victim ? id : victim;
        int second = id ^ victim ^ first;

        pthread_mutex_lock(&mtx[first]);
        pthread_mutex_lock(&mtx[second]);

        if (atomic_load_explicit(&castigator, memory_order_relaxed) != -1) {
            pthread_mutex_unlock(&mtx[second]);
            pthread_mutex_unlock(&mtx[first]);
            break;
        }

        int steal = min(x, valori[victim]);
        valori[victim] -= steal;
        valori[id]     += steal;

        if (valori[victim] == 0 &&
            atomic_load_explicit(&castigator, memory_order_relaxed) == -1)
            atomic_store_explicit(&castigator, victim, memory_order_release);

        pthread_mutex_unlock(&mtx[second]);
        pthread_mutex_unlock(&mtx[first]);
    }
    return NULL;
}

int main(void)
{
    for (int i = 0; i < N; ++i) {
        valori[i] = 100;
        pthread_mutex_init(&mtx[i], NULL);
    }

    pthread_t th[N];
    for (int i = 0; i < N; ++i)
        pthread_create(&th[i], NULL, worker, (void *)(intptr_t)i);

    for (int i = 0; i < N; ++i)
        pthread_join(th[i], NULL);

    printf("Primul la 0: thread %d\n", atomic_load(&castigator));
    return 0;
}
