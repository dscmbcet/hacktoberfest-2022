// Dining Philosopher's Problem solution assuming we have 5 philosophers
// compile using 'gcc filename.c -o filename -pthread'

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t s[5];

void *p(void *n) {
  int philosopher = *(int *)n;
  printf("Philosopher %d wants to eat\n", philosopher + 1);
  printf("Philosopher %d tries to pick left chopstick\n\n", philosopher + 1);
  sem_wait(&s[philosopher]);
  printf("Philosopher %d picks left chopstick\n", philosopher + 1);
  printf("Philosopher %d tries to pick right chopstick\n\n", philosopher + 1);
  sem_wait(&s[(philosopher + 1) % 5]);
  printf("Philosopher %d picks right chopstick\n", philosopher + 1);
  printf("Philosopher %d begins to eat\n\n", philosopher + 1);
  sleep(2);
  printf("Philosopher %d finishes eating\n", philosopher + 1);
  sem_post(&s[(philosopher + 1) % 5]);
  printf("Philosopher %d leaves right chopstick\n", philosopher + 1);
  sem_post(&s[philosopher]);
  printf("Philosopher %d leaves left chopstick\n\n", philosopher + 1);
}

int main() {
  int n[5];
  pthread_t t[5];
  for (int i = 0; i < 5; i++) {
    sem_init(&s[i], 0, 1);
  }

  for (int i = 0; i < 5; i++) {
    n[i] = i;
    pthread_create(&t[i], NULL, p, (void *)&n[i]);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(t[i], NULL);
  }
}