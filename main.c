#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100000
#define STR_LENGTH 200000
#define LIMIT 20
#define DELTA 100000

#define FAIL_CODE 0
#define MADE_CODE 1
#define STOP_CODE 2

void update_string_by_move(char, char);
void make_trimmed_string();
void print_result(char*);

char current_state[MAX_LENGTH][LIMIT], new_state[MAX_LENGTH][LIMIT];
char input_symbol[MAX_LENGTH], write_symbol[MAX_LENGTH], move[MAX_LENGTH];
char state[LIMIT];
char terminal_state[LIMIT];
char input_string[STR_LENGTH];
char string[STR_LENGTH];
char trimmed_string[STR_LENGTH];

int ops_count = 0;
int head = DELTA;
int new_zero_index;

int main(int argc, char *argv[])
{
    int limit, i, flag;
    FILE *fin;

    fin = fopen(argv[1], "r");
    if (fin == NULL)
    {
        printf("File %s not found\n", argv[1]);
        exit(0);
    }

    fscanf(fin, "%s\n", input_string);
    for (i = 0; i < strlen(input_string); i++)
        string[i + DELTA] = input_string[i];

    fscanf(fin, "%s %s\n", state, terminal_state);

    for (limit = 0; limit < MAX_LENGTH; limit++)
        fscanf(fin, "%s %c -> %s %c %c\n", current_state[limit],
               &input_symbol[limit], new_state[limit], &write_symbol[limit], &move[limit]);

    while(ops_count < 100000)
    {
        flag = FAIL_CODE;
        for (i = 0; i < limit; i++)
        {
            if (!strcmp(state, current_state[i]) && string[head] == input_symbol[i])
            {
                update_string_by_move(write_symbol[i], move[i]);
                strcpy(state, new_state[i]);
                if (!strcmp(state, terminal_state))
                    flag = STOP_CODE;
                else
                    flag = MADE_CODE;
                break;
            }
        }
        if (flag == FAIL_CODE)
        {
            print_result("FAIL after %d transactions\n");
            break;
        }
        ops_count++;
        if (flag == STOP_CODE)
        {
            print_result("STOP after %d transactions\n");
            break;
        }
    }
    if (flag == MADE_CODE)
    {
        print_result("MADE %d transactions\n");
    }
    return 0;
}

void print_result(char* string_format)
{
    make_trimmed_string();
    printf("\n");
    printf(string_format, ops_count);
    printf("%s\n", trimmed_string);
    printf("%s %d\n", state, head - new_zero_index);
}

void make_trimmed_string()
{
    int i, len;
    for (i = 0; i < STR_LENGTH; i++)
        trimmed_string[i] = string[i];
    len = strlen(input_string);

    for (i = 0; i < STR_LENGTH; i++)
        if(!strncmp(&trimmed_string[i], "_", 1))
            trimmed_string[i] = 0;

    new_zero_index = DELTA;
    for (i = 0; i < STR_LENGTH; i++)
        if(trimmed_string[i] != 0)
        {
            new_zero_index = i;
            break;
        }

    if (new_zero_index != 0)
        for(i = 0; i < len + 1; i++)
        {
            trimmed_string[i] = trimmed_string[i + new_zero_index];
            trimmed_string[i + new_zero_index] = 0;
        }
}

void update_string_by_move(char symbol, char current_move)
{
    string[head] = symbol;

    if (current_move == 'R')
        head++;

    else if (current_move == 'L')
        head--;

    if (string[head] == 0)
        string[head] = '_';
}
