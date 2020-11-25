/*
 * memorymanager.cpp
 *
 *  Created on: Oct 31, 2020
 *      Author: keith
 */

//TODO organize includes
#include "../includes/memorymanager.h"
#include "../includes/constants.h"
#include "../includes/utilities.h"

using namespace std;

/**
 * this will hold the list of structs
 */
 data *list_data=0;
 int mem_allocated = 0;

/**
 * create a linked list of  structs.
 * NOTE: be sure you do not leak memory if you call this function twice!
 *       IOW deallocate any existing list before reallocating
 *
 * \param total_memory: the maximum memory to use
 * \return if a positive number, then its the number of structs created
 *         if 0, then there is not enough memory to allocate a struct
 * 		   if MEM_ALREADY_ALLOCATED  if memory has already been allocated by this function.
 * 		   						     You can tell if memory has already been allocated
 * 		   						     by whether list_data points to null or not.
 */
int create_list(int total_memory) {
	int memory = how_many_structs_can_fit_in_memory(total_memory);

	if(mem_allocated > 0) {
		return MEM_ALREADY_ALLOCATED;
	}
	else if(memory == 0) {
		return 0;
	}

	list_data = new data;
	data *tmp = list_data;
	mem_allocated++;

	int i = 1;
	while(i<memory) {
		tmp->p_next = new data;
		tmp = tmp->p_next;
		mem_allocated++;
		i++;
	}
	return mem_allocated;

}

/**
 * deallocate the list of structs, easiest way is to start at the beginning
 * and delete as you go, don't forget to set list_data to null when done
 *
 * \return SUCCESS if memory deallocated
 *         NO_STRUCTS_TO_DEALLOCATE if no memory allocated
 */
int destroy_list() {
	if(list_data == NULL) {
		return NO_STRUCTS_TO_DEALLOCATE;
	}

	data *tmp = new data;
	tmp = list_data;

	if(tmp) {

		list_data = list_data->p_next;
		delete tmp;

		tmp = list_data;
	}

	list_data = NULL;
	mem_allocated = 0;
	return SUCCESS;
}

/**
 * How many structs are available in list_data
 *
 * \return number structs available
  */
int numb_available_structs() {
	int available_structs = 0;
	data *tmp = list_data;

	while(tmp != NULL) {
		tmp = tmp->p_next;
		available_structs++;
	}
	return available_structs;
}

/**
 *returns the list for client use
 *
 * \return 	pointer to list
 * 			0 if the list his empty
 *
 */
data*  get_list() {
	return list_data;
}
