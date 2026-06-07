#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "stack.h"

bool validate_expr(char* expr, int size)
{
    bool is_valid = true;
    stack_t* stack = initialize(30);

    for(int i = 0; i < size; i++)
    {
        char c = expr[i];

        if(c == '{' || c == '[' || c == '(')
        {
            push(stack, c);
        }
        else if(c == '}' || c == ']' || c == ')')
        {
            if(is_empty(stack))
            {
                is_valid = false;
                break;
            }
            char popped_char;
            pop(stack, &popped_char);
            
            if(c == '}' && popped_char != '{')
            {
                is_valid = false;
                break;
            }
            else if(c == ']' && popped_char != '[')
            {
                is_valid = false;
                break;
            }
            else if(c == ')' && popped_char != '(')
            {
                is_valid = false;
                break;
            }
        }
    }

    if(!is_empty(stack))
    {
        is_valid = false;
    }

    deinitialize(stack);
    return is_valid;
}

int main()
{
    
    char* expression = "(a + b){c}]";
    int size = strlen(expression);
    
    bool is_valid = validate_expr(expression, size);
    if(is_valid)
    {
        printf("\nExpression is valid!");
    }
    else
    {
        printf("\nExpression is invalid!");
    }

    return 0;
}