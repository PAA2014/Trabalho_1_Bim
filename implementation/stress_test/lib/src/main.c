#include <locale.h>

#include "struct.c"
#include "../stress_test.h"
#include "../parameter_checker.h"

#define ERROR -1
#define SUCCESS_END_OF_PROGRAM 0
#define BRAZILIAN_LOCALE "pt_BR.utf8"

environment_configurations configurations;

void set_numeric_locale(String locale);

int main(int parameter_count, String * parameter_values){
	
	set_numeric_locale(BRAZILIAN_LOCALE);
	
	if(are_valid_parameters(parameter_count, parameter_values)){
		set_environment_configuration_from_parameters(parameter_count, parameter_values);
		execute_stress_test();
	} else {
		printf("ERROR : INVALID PARAMETERS\n\n");
		return ERROR;
	}
	
	return SUCCESS_END_OF_PROGRAM;
}

/**
	To print groups sepparated by '.' or ',' when ''' is used.
		Ex : int number = 1234567
			printf("%d",number);
				-> 1234567
			printf("%'d",number);
				-> 1.234.567
*/
void set_numeric_locale(String locale){
	setlocale(LC_NUMERIC, locale);
}
