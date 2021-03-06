#include "../stress_test.h"

environment_configurations configurations;

// Init of Get Functions
clock_t get_actual_time(){
	return clock();
}

cicle ** new_cicle_array(int long long num_cicles){
	return (cicle **) malloc(sizeof(cicle*) * num_cicles);
}

cicle * new_cicle(){
	return (cicle *) malloc(sizeof(cicle) * 1);
}
// End of Get Functions

// Init of Calculate Functions
double calculate_total_time(cicle ** cicles, int long long num_cicles){
	int actual_position;
	double total_time = 0;

	for(actual_position=0; actual_position<num_cicles; actual_position++)
		total_time += cicles[actual_position]->time_spent;
		
	return total_time;
}

double calculate_time_spent(cicle * actual_cicle){
	return ((actual_cicle->end_time - actual_cicle->start_time) / (double)CLOCKS_PER_SEC);
}

double calculate_avarage_time(double total_time, int long long num_cicles){
	return total_time / num_cicles;
}

double calculate_instructions_per_seccond(int long long num_instructions, double avarage_time ){
	return num_instructions / avarage_time;
}
// End of Calculate Functions

// Execute Functions
void execute_stress_test(){

	int actual_position;
	double total_time;
	double avarage_time;
	double instructions_per_seccond;
	cicle ** cicles;
	
	total_time = 0;
	cicles = new_cicle_array(configurations.num_cicles);

	for(actual_position=0; actual_position< configurations.num_cicles; actual_position++){
		cicles[actual_position] = new_cicle();
		
		execute_cicle_test(cicles[actual_position], configurations.num_instructions);
		cicles[actual_position]->time_spent = calculate_time_spent(cicles[actual_position]);
		
		if(configurations.debug == TRUE)
			print_debug(actual_position, cicles[actual_position]);
	}
	
	total_time = calculate_total_time(cicles, configurations.num_cicles);
	avarage_time = calculate_avarage_time(total_time, configurations.num_cicles);
	instructions_per_seccond = calculate_instructions_per_seccond(configurations.num_instructions, avarage_time);
	
	print_results(avarage_time, instructions_per_seccond);
}

void execute_cicle_test(cicle * actual_cicle, int long long num_instructions){
	actual_cicle->start_time = get_actual_time();
	execute_instructions_per_seccond_test(num_instructions);
	actual_cicle->end_time = get_actual_time();	
}

inline void execute_instructions_per_seccond_test(int long long num_instructions){
	int long long aux_num_instructions = num_instructions;

	while(aux_num_instructions--);
}
// End of Execute Functions

// Init of Print Functions
void print_debug(int position_cicle, cicle * actual_cicle){
	printf("Cicle_%02d : %'.4f seconds\n", position_cicle+1, actual_cicle->time_spent);
}

void print_results(double avarage_time, double instructions_per_seccond){
	printf("\n################### Results ###################\n\n");
	printf("Avarage Time : %'.4f seconds\n",avarage_time);
	printf("Instructions Per Second : %'.4f instructions/second\n", instructions_per_seccond);

	// Just to do not confuse with the console's prints
	printf("\n");
}

// Enf of Print Functions
