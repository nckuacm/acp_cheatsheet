// parsing the testdata, and using existed threshold as measurement
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void helper();
/* basic method - threshold, counter two separated array */
void t_c_detector(const char *str);
/* improved method - wide word and merged array */
// void wideword_mergedarr(const char *str);
/* improved method - chi-square */
// void chi_square(const char *str);
char *append_str(const char *old,const char *new);
char *append_char(const char *old,const char c);

int main(int argc, char *argv[])
{
	// reading parameter from argv, to get input
	if(argc < 2) {
		printf("Error:\n[No input file] Need to specified input filename for me!\n\n");
		helper();
		exit(1);
	}

	char *fin_name = argv[1];

	FILE *fp = fopen(fin_name,"r");

	if(!fp) {
		printf("Error:\n[Invalid input file] Please check your input file!\n\n");
		helper();
		exit(1);
	}

	printf("Input filename: %s\n",fin_name);

	// maintain the table entry size
	int table_size = 128;
	if(argc >= 3) {
		// then it specified the table entry size !
		table_size = atoi(argv[2]);
	}
	printf("Using table size: %d\n", table_size);

	// read it !
	char c , *tmp;
	while((c = fgetc(fp))) {
		// keep reading
		if(c != '\n' && c != EOF) {
			tmp = append_char(tmp,c);
		} else {
			// dealing with tmp
			// printf("%s\n",tmp);
			/*
			    TODO: store them into table

			    - Using Threshold, Counter array to specified the evil packet
			    treat each line read from input file as url (with buffer overflow)
			*/
			t_c_detector(tmp);
			// free
			/* NOTICE:
			    - If we use malloc instead, only using free() to free the memory will cause error
			    - Need to add *tmp = NULL, pointer tmp need to point to NULL space

			    - And change to use calloc as allocator, this problem disappear
			    - I think it need to use the clean memory space
			*/
			free(tmp);
			// *tmp = NULL;
			if(c == EOF) break;
		}
	}

	fclose(fp);
	return 0;
}

void t_c_detector(const char *str)
{
	// get the length
	int length = (int)strlen(str);
	// init table
	int *counter_arr,*threshold_arr;
	counter_arr = calloc(128, sizeof(int));
	// TODO: get threshold array

	for(int i=0; i<length; i++) {
		counter_arr[(int)str[i]]++;
	}

	// print, skip 0~32, and 127
	for(int i=33; i<127; i++) {
		printf("%c | %d\n",(char)i,counter_arr[i]);
	}

	free(counter_arr);
}

char *append_str(const char *old,const char *new)
{
	size_t len = strlen(old) + strlen(new) + 1;

	char *out = malloc(len);

	sprintf(out,"%s%s", old, new);

	return out;
}

char *append_char(const char *old,const char c)
{
	size_t len = strlen(old) + 1 + 1;

	// using calloc, allocate with initialization
	char *out = calloc(len, sizeof(char));


	// As you can see here, if we print out the ptr: "out" here, it will be some useless data inside
	// Then if when the data which ptr point to is big, this error will occur.
	// Test -> using phonebook and specify size 30 (for strlen range upperbound), and then print out nothing!

	/*
	char *out = malloc(len);
	printf("%s\n",out);
	*/

	sprintf(out,"%s%c", old, c);

	return out;
}

void helper()
{
	printf("Helper manual:\n\
    - How to use:\n\
    \t./<execute> <input_filename>\n");
}