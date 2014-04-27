#ifndef PARAMETER_CHECKER_H
#define PARAMETER_CHECKER_H

#include <stdio.h>
#include <stdlib.h>
#include "src/struct.c"

boolean are_valid_parameters(int parameter_count, String * parameter_values);

boolean has_no_parameters(int parameter_count);

boolean has_less_than_minimum_number_parameters(int parameter_count);

boolean validate_parameters(int parameter_count, String * parameter_values);

boolean is_not_valid_parameter(String parameter);

boolean validate_actual_parameter(String actual_definition_parameter, int actual_position, String * parameter_values);

String get_parameter(String * parameter_values, int actual_position);

boolean is_optional_parameter(String definition_parameter);

boolean is_mandatory_parameter(String definition_parameter);

boolean is_numeric_parameter(String definition_parameter);

boolean is_flag_parameter(String definition_parameter);

boolean is_string_parameter(String definition_parameter);

boolean is_valid_next_numeric_value_parameter(int actual_position ,String * parameter_values);

boolean is_valid_number(int value);

int recovery_number_from_next_value_parameter(String * parameter_values, int actual_position);

boolean is_valid_next_string_value_parameter(int actual_position ,String * parameter_values);

String recovery_string_from_next_value_parameter(String * parameter_values, int actual_position);

boolean is_valid_string(String value);

int convert_string_to_int(String value);

String get_next_parameter(String * parameter_values, int actual_position);

void set_environment_configuration_from_parameters(int parameter_count, String * parameter_values);

void init_optinional_parameters();

void set_file_path(String value);

void set_debug(int value);

boolean is_parameter_file_path(String parameter);

boolean is_parameter_debug(String parameter);

boolean are_equal_strings(String string1, String string2);

#endif
