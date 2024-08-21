#pragma once

#define DYNAMIC_ARRAY_ERROR(LOG, ...) printf("DynamicArray error: \n"LOG"\n\n", __VA_ARGS__); exit(EXIT_FAILURE)

#define createDynamicArrayStruct(TYPE)\
struct DynamicArray_##TYPE\
{\
	TYPE* array;\
	size_t lenght;\
};\
\
TYPE dynamicArrayGet_##TYPE(struct DynamicArray_##TYPE* array, unsigned int index)\
{\
	if(index >= array->lenght)\
	{\
		DYNAMIC_ARRAY_ERROR("error when getting the index %i because it is out of range", index);\
	}\
	return (array->array)[index];\
}\
\
void dynamicArraySet_##TYPE(struct DynamicArray_##TYPE* array, unsigned int index, TYPE value)\
{\
	if(index >= array->lenght)\
	{\
		DYNAMIC_ARRAY_ERROR("error when setting the index %i because it is out of range", index);\
	}\
	(array->array)[index] = value;\
}\
\
void dynamicArrayAssignAll_##TYPE(struct DynamicArray_##TYPE* array, TYPE* buffer, size_t lenght)\
{\
	if(lenght != array->lenght)\
	{\
		DYNAMIC_ARRAY_ERROR("assignment list size not equals current DynamicArray size"); \
	}\
	\
	for(int i = 0; i < lenght; i++)\
	{\
		(array->array)[i] = buffer[i];\
	}\
}\
\
void dynamicArrayFill_##TYPE(struct DynamicArray_##TYPE* array, TYPE value)\
{\
	for (int i = 0; i < array->lenght; i++)\
	{\
		(array->array)[i] = value;\
	}\
}\
void dynamicArrayPushBack_##TYPE(struct DynamicArray_##TYPE* array, TYPE value)\
{\
	array->array = realloc(array->array, (array->lenght)++ * sizeof(TYPE));\
	(array->array)[array->lenght - 1] = value;\
}\
\
void dynamicArrayPopBack_##TYPE(struct DynamicArray_##TYPE* array)\
{\
	array->array = realloc(array->array, (array->lenght)-- * sizeof(TYPE));\
}\
\
void dynamicArrayFree_##TYPE(struct DynamicArray_##TYPE* array)\
{\
	free(array->array);\
	array->lenght = 0;\
}

#define DynamicArray(TYPE) struct DynamicArray_##TYPE

#define dynamicAlloc(TYPE, AMOUNT) {(TYPE*) malloc(AMOUNT*sizeof(TYPE)), AMOUNT}

#define dynamicArrayGet(TYPE, DYNAMIC_ARRAY_PTR, INDEX) dynamicArrayGet_##TYPE(DYNAMIC_ARRAY_PTR, INDEX)

#define dynamicArraySet(TYPE, DYNAMIC_ARRAY_PTR, INDEX, VALUE) dynamicArraySet_##TYPE(DYNAMIC_ARRAY_PTR, INDEX, VALUE)

#define dynamicArrayAssignAll(TYPE, DYNAMIC_ARRAY_PTR, LIST) dynamicArrayAssignAll_##TYPE(DYNAMIC_ARRAY_PTR, LIST, sizeof(LIST)/sizeof(TYPE))

#define dynamicArrayFill(TYPE, DYNAMIC_ARRAY_PTR, VALUE) dynamicArrayFill_##TYPE(DYNAMIC_ARRAY_PTR, VALUE)

#define dynamicArrayPushBack(TYPE, DYNAMIC_ARRAY_PTR, VALUE) dynamicArrayPushBack_##TYPE(DYNAMIC_ARRAY_PTR, VALUE)

#define dynamicArrayPopBack(TYPE, DYNAMIC_ARRAY_PTR) dynamicArrayPopBack_##TYPE(DYNAMIC_ARRAY_PTR)

#define dynamicArrayFree(DYNAMIC_ARRAY_PTR) dynamicArrayFree_##TYPE(DYNAMIC_ARRAY_PTR)
