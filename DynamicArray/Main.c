#include <stdio.h>
#include <stdlib.h>

#include "DinamicArray.h"

createDynamicArrayStruct(int);

int main() {
	DynamicArray(int) test = dynamicAlloc(int, 4);
	
	int buffer[4] = { 1, 2, 3, 4 };

	dynamicArrayAssignAll(int, test, buffer);

	printf("\n\ndynamicArrayAssignAll:\n\nsize of the array: %i\n", test.lenght);

	for (int i = 0; i < test.lenght; i++)
		printf("%i: %i\n", i, dynamicArrayGet(int, test, i));

	dynamicArrayFill(int, test, 5);

	printf("\n\ndynamicArrayFill:\n\nsize of the array: %i\n", test.lenght);

	for (int i = 0; i < test.lenght; i++)
		printf("%i: %i\n", i, dynamicArrayGet(int, test, i));

	dynamicArrayPushBack(int, test, 6);

	printf("\n\ndynamicArrayPushBack:\n\nsize of the array: %i\n", test.lenght);

	for(int i = 0; i < test.lenght; i++)
		printf("%i: %i\n", i, dynamicArrayGet(int, test, i));

	dynamicArrayPopBack(int, test);

	printf("\n\ndynamicArrayPopBack:\n\nsize of the array: %i\n", test.lenght);

	for (int i = 0; i < test.lenght; i++)
		printf("%i: %i\n", i, dynamicArrayGet(int, test, i));

	dynamicArraySet(int, test, 3, 4);

	printf("\n\ndynamicArraySet:\n\nsize of the array: %i\n", test.lenght);

	for (int i = 0; i < test.lenght; i++)
		printf("%i: %i\n", i, dynamicArrayGet(int, test, i));
}