#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct person
{
	char *name;
	int age;
	int height;
	int weight;
};

struct person *create(char *name, int age, int height, int weight)
{
	struct person *who = malloc(sizeof(struct person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	
	return who;
}

void destory(struct person* who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void printperson(struct person *who)
{
	printf("name->>%s\n", who->name);
	printf("age->>%d\n", who->age);
	printf("height->>%d\n", who->height);
	printf("weight->>%d\n", who->weight);
}

int main(int argc, char *argv[])
{
	struct person *joe = create("yangpeng", 24, 165, 52);
	printperson(joe);
	destory(joe);
	return 1;
}
