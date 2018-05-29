#include <stdio.h>
#include <semaphore.h>

sem_t mutex = 1;
sem_t db = 1;


void reader(void) 
{
	int item;

	while(1 == 1) {
		down(&mutex);
		rc = rc + 1;
		if (rc == 1) down(&db);
		up(&mutex);
		item = read_data_base();
		down(&mutex);
		rc = rc - 1;
		if (rc == 0) up(&db);
		up(&mutex);
		use_data(item);
	}
}

void writer(void) {
	int item;

	while (1 == 1) {
		item = create_data();
		down(&db);
		write_data_base(item);
		up(&db);
	}
}
