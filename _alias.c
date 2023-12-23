#include "main.h"

/**
 * add_alias - Adds an alias in the shell data structure
 * @datash: Pointer to the data_shell structure
 * @alias_name: Name of the alias
 * @alias_value: Value of the alias
 */
void add_alias(data_shell *datash, char *alias_name, char *alias_value)
{
    /* Check if the alias already exists */
    for (int i = 0; datash->alias_names[i] != NULL; i++)
    {
        if (_alias_strcmp(datash->alias_names[i], alias_name, _strlen(alias_name)) == 0)
        {
            /* Update the existing alias */
            free(datash->alias_values[i]);
            datash->alias_values[i] = (alias_value != NULL) ? _strdup(alias_value) : NULL;
            return;
        }
    }

    /* Add a new alias */
    int count = 0;
    while (datash->alias_names[count] != NULL)
    {
        count++;
    }

    datash->alias_names = _realloc(datash->alias_names, count * sizeof(char *), (count + 2) * sizeof(char *));
    datash->alias_values = _realloc(datash->alias_values, count * sizeof(char *), (count + 2) * sizeof(char *));

    datash->alias_names[count] = _strdup(alias_name);
    datash->alias_values[count] = (alias_value != NULL) ? _strdup(alias_value) : NULL;
    datash->alias_names[count + 1] = NULL;
    datash->alias_values[count + 1] = NULL;

    if (datash->alias_names[count] == NULL || datash->alias_values[count] == NULL)
    {
        /* Handle memory allocation error */
        _printerr("Error allocating memory");
        free(datash->alias_names[count]);
        free(datash->alias_values[count]);
        datash->alias_names[count] = NULL;
        datash->alias_values[count] = NULL;
    }
}

/**
 * parse_alias_command - Parses an alias command and updates alias_names and alias_values
 * @input: Input string containing the alias command
 * @alias_names: Pointer to an array to store alias names
 * @alias_values: Pointer to an array to store alias values
 * Return: 0 on success, 1 on memory allocation error
*/

int parse_alias_command(const char *input, char ***alias_names, char ***alias_values)
{
    /* Skip "alias " part */
    char *alias_cmd = _strdup(input + 5);

    if (alias_cmd == NULL)
        return 1; /* Memory allocation error */

    /* Initialize arrays to store names and values */
    int count = 0;
    *alias_names = NULL;
    *alias_values = NULL;

    char *token = _strtok(alias_cmd, "=");

    while (token != NULL)
    {
        /* Allocate memory for name and value */
        *alias_names = _realloc(*alias_names, count * sizeof(char *), (count + 1) * sizeof(char *));
        *alias_values = _realloc(*alias_values, count * sizeof(char *), (count + 1) * sizeof(char *));

        if (*alias_names == NULL || *alias_values == NULL)
        {
            free(alias_cmd);
            if (token != NULL)
                free(token);
            return 1; /* Memory allocation error */
        }

        /* Set name */
        (*alias_names)[count] = _strdup(token);

        /* Set value, or set it to NULL if not present */
        token = _strtok(NULL, " ");
        (*alias_values)[count] = (token != NULL) ? _strdup(token) : NULL;

        /* Check for memory allocation errors */
        if ((*alias_names)[count] == NULL && (*alias_values)[count] == NULL)
        {

            if (alias_cmd != NULL)
                free(alias_cmd);
            if (token != NULL)
            free(token);

            return 1; /* Memory allocation error */
        }

        /* Move to the next token */
        if (token != NULL)
            count++;

        token = _strtok(NULL, "=");
    }

    /* Null-terminate the arrays */
    *alias_names = _realloc(*alias_names, count * sizeof(char *), (count + 1) * sizeof(char *));
    *alias_values = _realloc(*alias_values, count * sizeof(char *), (count + 1) * sizeof(char *));

    if (*alias_names == NULL || *alias_values == NULL)
    {
        /* Free allocated memory for names and values */
        for (int i = 0; i < count; i++)
        {
            free((*alias_names)[i]);
            free((*alias_values)[i]);
        }
        free(*alias_names);
        free(*alias_values);
        free(alias_cmd);
        if (token != NULL)
            free(token);

        return 1; /* Memory allocation error */
    }

    (*alias_names)[count] = NULL;
    (*alias_values)[count] = NULL;

    /* Free temporary memory */
    if (alias_cmd != NULL)
        free(alias_cmd);
    if (token != NULL)
        free(token);

    return 0; /* Parsing success */
}

/**
 * alias_cmd - Clean alias command
 * @input: Input string to check
 * Return: Modified string with quotes removed
 */
char *alias_cmd(const char *str)
{
    int len = _strlen(str);

    // Allocate memory for the cleaned string (including space for the null terminator)
    char *clean_str = _strdup(str - 1);
    if (clean_str == NULL)
        return NULL;

    char *current = clean_str;
    const char *tail = str;

    while (*tail)
    {
        if (tail[0] == '\'' || tail[len - 1] == '\'' || tail[0] == '\"' || tail[len - 1] == '\"')
        {
            tail++;
        }
        else
        {
            *current++ = *tail++;
        }
    }

    *current = '\0';
    return clean_str;
}