/*
Project Title: Advanced Scientific Calculator


Project started in 4 Dey 1402



Project Overview:
This project involves the development of an advanced scientific calculator implemented in the C programming language.
The calculator aims to provide a wide range of mathematical functions and capabilities suitable for scientific and
engineering applications. It will support basic arithmetic operations, advanced mathematical functions, trigonometric
calculations, logarithmic functions, and more.

Team Arrangment:

Soroush Haghighi
Moein Jaffaraghaei
Nima Asadi
Hossein Hosseinzadeh


Deliverables:
Fully functional scientific calculator coded in C.
Code documentation for clarity and ease of understanding.
User manual providing instructions on how to use the calculator.
Presentation materials for the final project submission.



Submission Details:
The completed project will be submitted to Professor Alizadeh at the end of the first semester.
The submission will include the source code, documentation, user manual, and any additional
materials required by the professor.
*/







/*
 * Mathematical Functions Explanation:
 *
 * In this section, we utilize various math.h functions to perform
 * complex mathematical operations in our advanced scientific calculator.
 * Each function is carefully chosen to enhance the calculator's capabilities.
 *
 * 1. log(x):
 *    - Description: Computes the logarithm of 'x'.
 *    - Example: log(10.0) returns the logarithm of 10.0.
 *
 * 2. ln(x):
 *    - Description: Computes the natural logarithm of 'x'.
 *    - Example: ln(10.0) returns the natural logarithm of 10.0.
 *
 *    - Description: Computes the square root of 'x'.
 * 3. sqrt(x):
 *    - Example: sqrt(25.0) returns 5.0.
 *
 * 4. sin(x), cos(x), tan(x) and cot(x):
 *    - Description: Trigonometric functions to calculate sine, cosine, tangent and cotangent of 'x' (in radians).
 *    - Example: sin(30.0) returns the sine of 30 degrees.
 *
 * 5. sinh(x), cosh(x), tanh(x) and coth(x):
 *    - Description: Hyperbolic functions to calculate hyperbolic sine, cosine, tangent and cotangent of 'x'.
 *    - Example: sinh(2.0) returns the hyperbolic sine of 2.0.
 *
 * 6. asin(x), acos(x), atan(x) and acot(x):
 *    - Description: Inverse trigonometric functions to calculate arc-sine, arc-cosine, arc-tangent and arc-cotangent of 'x' (in radians).
 *    - Example: asin(0.5) returns the arc-sine of 0.5.
 *
 * 7. asinh(x), acosh(x), atanh(x) and acoth(x):
 *    - Description: Inverse hyperbolic functions to calculate arc-sinh, arc-cosh, arc-tanh and arc-coth of 'x'.
 *    - Example: asinh(2.0) returns the arc-sinh of 2.0.
 *
 * 8. pow(x, y):
 *    - Description: Raises 'x' to the power of 'y'.
 *    - Example: pow(2.0, 3.0) returns 8.0.
 *
 * 9. exp(x):
 *    - Description: Computes the exponential function of 'x' (e^x).
 *    - Example: exp(1.0) returns the value of Euler's number (e).
 *
 * 10. fabs(x) and abs(x):
 *    - Description: Returns the absolute value of 'x'.
 *    - Example: fabs(-5.0) returns 5.0.
 *
 * 11. rnd(x):
 *    - Description: Rounds 'x' to the nearest integer.
 *    - Example: rnd(4.3) returns 4.0, rnd(4.7) returns 5.0.
 *
 * 12. ceil(x) and floor(x):
 *    - Description: Rounds 'x' to the nearest integer, either upwards (ceil) or downwards (floor).
 *    - Example: ceil(4.3) returns 5.0, floor(4.7) returns 4.0.
 *
 * Note: Ensure that angles for trigonometric functions are provided in radians
 *       unless specified otherwise in your calculator.
 */










#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <stddef.h>
#define MAX_PRECISION 18
#define pi 3.141592653589793238462643383279502884197
#define nepper 2.718281828459045
#define MAX_FORMULA_LENGTH 1500
#define MAX_TOKEN_LEN 5
#define MAX_ROWS 1000
#define MAX_COLUMNS 1000
#define MAX_SUB_EXPR_LENGTH 1500 // Define maximum sub-expression length
#define MAX_EXPRESSION_LENGTH 2000



 // Structure to represent a cell in the table
typedef struct
{
    long double value;
    char cellrow;
    char cellcolumn;
    char formula[1000];  // Max length for a formula
} cell;





// Function prototypes
cell** initializeTable(int rows, int columns);
void freeTable(int rows, cell** table);
void printTable(int rows, int columns, cell** table);
void printTableCellsName(int rows, int columns, cell** table);
void enterCellData(int rows, int columns, cell** table);
void evaluateFormulas(int rows, int columns, cell** table);
void saveTableToFile(int rows, int columns, cell** table, char* filename);
void loadTableFromFile(int* rows, int* columns, cell*** table, char* filename);
void addExtensionIfNeeded(char* filename, const char* extension);
void formulaMenu(int rows, int columns, cell** table);
void enterFormula(int rows, int columns, cell** table);
void displayFormulas(int rows, int columns, cell** table);
long double evaluateCellFormula(int rows, int columns, cell** table, int i, int j);
void printDecorativeLine(char symbol, int length);
void printMenu();





// Function prototypes for formula evaluation
void calculatorPlayground(int rows, int columns, cell** table);
void clearInputBuffer();




//Token functions
char** tokenizeExpression(char* expression, int* numTokens);
void freeTokens(char** tokens, int numTokens);
void printTokens(char** tokens, int numTokens);
void evaluateToken(char** tokens, int numToken, cell** table);
long double evaluateFunction(char* functionName, long double argument, long double base);
int isOperator(char* token);
int isFunction(char* token);
void freeTokens(char** tokens, int numTokens);
void evaluateParentheses(char** tokens, int* numTokens, int start);
void performOperation(char** tokens, int index, int* numTokens);
int isCellReference(char* token);
void extractCellIndices(char* token, int* rowIndex, int* columnIndex);
int getPrecedence(char* oper);
void formatLongDouble(long double num, int precision);
int isNumeric(const char* str);


char filename[260];
int rows, columns, x;
cell** table = NULL; // Declare table here for global scope


int main() {
    printf("  +-------------------------------------------------+\n");
    printf("  |  Welcome to Advanced Scientific Calculator Pro  |\n");
    printf("  +-------------------------------------------------+\n\n");

    char response;
    bool validResponse = false;
    do {
        printf("  +-------------------------------------------------+\n");
        printf("  |        Do you have a saved file? (Y/N):         |\n");
        printf("  +-------------------------------------------------+\n\n\n\n");
        printf("\n\n-------------)>  ");
        scanf(" %c", &response);
        printf("\n");
        if (response == 'Y' || response == 'y') {
            validResponse = true;
            printf("  +-------------------------------------------------+\n");
            printf("  |  Please enter the name of the file:             |\n");
            printf("  +-------------------------------------------------+\n");
            printf("\n\n-------------)>  ");
            scanf("%s", filename);
            printf("\n");
            printf("  +--------------------------------------------------+\n");
            printf("  |  Loading data from file: %s.txt                       \n", filename);
            printf("  +--------------------------------------------------+\n\n\n");
            loadTableFromFile(&rows, &columns, &table, filename);
            // Load data using 'filename'...
        }
        else if (response == 'N' || response == 'n') {
            validResponse = true;
            printf("  +---------------------------------------------+\n");
            printf("  |  Let's create a table for you.              |\n");
            printf("  +---------------------------------------------+\n");

            do {
                printf("  +---------------------------------------------+\n");
                printf("  |  Enter the number of rows for your table:   |\n");
                printf("  +---------------------------------------------+\n");
                printf("\n\n-------------)>  ");
                if (scanf("%d", &rows) != 1) {
                    printf("\n");
                    printf("  +---------------------------------------------+\n");
                    printf("  |  Invalid input. Please enter a number.      |\n");
                    printf("  +---------------------------------------------+\n");
                    clearInputBuffer();
                }
                else {
                    printf("\n");
                    break;
                }
            } while (1);

            do {
                printf("\n");
                printf("  +---------------------------------------------------+\n");
                printf("  |  Enter the number of columns for your table:      |\n");
                printf("  +---------------------------------------------------+\n");
                printf("\n\n-------------)>  ");
                if (scanf("%d", &columns) != 1) {
                    printf("\n");
                    printf("  +---------------------------------------------+\n");
                    printf("  |  Invalid input. Please enter a number.      |\n");
                    printf("  +---------------------------------------------+\n");
                    clearInputBuffer();
                }
                else {
                    break;
                }
            } while (1);
            printf("\n");
            printf("  +------------------------------------------------------+\n");
            printf("  |  Initializing table with %d rows and %d columns!     |\n", rows, columns);
            printf("  +------------------------------------------------------+\n");
            table = initializeTable(rows, columns);
            printTableCellsName(rows, columns, table);
            //Perform initialization tasks...
        }
        else {
            printf("  +------------------------------------------------------+\n");
            printf("  |  Invalid input. Please enter a valid choice!         |\n");
            printf("  +------------------------------------------------------+\n");
        }
    } while (!validResponse);


    int option;

    do {
        printf("\n\n\n");
        printMenu();
        printf("Please choose an option (1 - 9): ");
        if (scanf("%d", &option) != 1 || option < 1 || option > 10) {
            printf("Invalid input. Please choose a valid option (1 - 9).\n");
            clearInputBuffer();
        }
        else {
            printf("You chose option %d\n", option);

            switch (option) {
            case 1:
                printf("Entering data into a cell...\n");
                enterCellData(rows, columns, table);
                break;
            case 2:
                printf("Displaying the current table...\n");
                printTable(rows, columns, table);
                break;
            case 3:
                printf("Evaluating formulas and updating the table...\n");
                evaluateFormulas(rows, columns, table);
                break;
            case 4:
                printf("Saving table data to a file...\n");
                printf("\nPlease enter the name of the file that data will be stored to:");
                char filename[260];
                scanf("%s", filename);
                saveTableToFile(rows, columns, table, filename);
                break;
            case 5:
                printf("Loading table data from a file...\n");
                printf("\nPlease enter the name of the file that data will be restored from:");
                char loadFilename[260];
                scanf("%s", loadFilename);
                loadTableFromFile(&rows, &columns, &table, loadFilename);
                break;
            case 6:
                printf("Entering the calculator playground...\n");
                calculatorPlayground(rows, columns, table);
                break;
            case 7:
                printf("Entering the formula menu...\n");
                formulaMenu(rows, columns, table);
                break;
            case 8:
                printf("Restarting the program...\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
                main();
                break;
            case 9:
                printf("Exiting the program...\n");
                exit(0); // Exit the program with a status code 0 (indicating successful termination)
                break;
            default:
                printf("Invalid option. Please choose a valid option.\n");
                break;
            }
        }
    } while (option != 10);

    freeTable(rows, table);
    return 0;
}













// Function to print a decorative line
void printDecorativeLine(char symbol, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%c", symbol);
    }
    printf("\n");
}

// Function to print the main menu
void printMenu() {
    printDecorativeLine('*', 49); // Title decoration
    printf("* Welcome to Advanced Scientific Calculator Pro *\n");
    printDecorativeLine('*', 49); // Title decoration

    printf("Choose an option:\n");
    printf("* 1. Enter data into a cell\n");
    printf("* 2. Display the current table\n");
    printf("* 3. Evaluate formulas and update the table\n");
    printf("* 4. Save table data to a file\n");
    printf("* 5. Load table data from a file\n");
    printf("* 6. Calculator Playground\n");
    printf("* 7. Formula Menu\n");
    printf("* 8. Restart the program\n");
    printf("* 9. Exit\n");
    printDecorativeLine('*', 49); // End of menu
}

// prints help for calculator playground
void printHelp() {
    printf("  +---------------------------------------------------------+\n");
    printf("  |            Welcome to the Calculator Playground         |\n");
    printf("  +---------------------------------------------------------+\n\n");
    printf("  Supported Functions:\n");
    printf("  +---------------------------+-----------------------------+\n");
    printf("  | Trigonometric functions:  | Hyperbolic functions:       |\n");
    printf("  | +--------------+----------+ +--------------+------------+\n");
    printf("  | | sin, cos,    |          | | sinh, cosh,  |            |\n");
    printf("  | | tan, cot     |          | | tanh, coth   |            |\n");
    printf("  | | asin, acos,  |          | | asinh, acosh |            |\n");
    printf("  | | atan, acot   |          | | atanh, acoth |            |\n");
    printf("  | +--------------+          | +--------------+            |\n");
    printf("  | Exponential function:     | | Square root:              |\n");
    printf("  | +--------------+----------+ +--------------+------------+\n");
    printf("  | | exp          |          | | sqrt         |            |\n");
    printf("  | +--------------+          | +--------------+            |\n");
    printf("  | Ceiling:                  | |Flooring:                  |\n");
    printf("  | +--------------+----------+ +--------------+------------+\n");
    printf("  | | ceil         |          | | floor        |            |\n");
    printf("  | +--------------+          | +--------------+            |\n");
    printf("  | Factorial:                | Logarithms:                 |\n");
    printf("  | +--------------+----------+ +--------------+------------+\n");
    printf("  | | !            |          | | ln           |            |\n");
    printf("  | +--------------+          | | log          |            |\n");
    printf("  |                           | | log2         |            |\n");
    printf("  |                           | | logb         |            |\n");
    printf("  |                           | +--------------+            |\n");
    printf("  | Miscellaneous:            |                             |\n");
    printf("  | +--------------+----------+                             |\n");
    printf("  | | abs, fabs    |                                        |\n");
    printf("  | | round        |                                        |\n");
    printf("  +----------------+----------------------------------------+\n\n");
    printf("  Usage example: sin ( 30 ) + log2 ( 8 ) * ceil ( 4.5 )\n\n");
    printf("  Enter your mathematical expression for calculation.\n");
    printf("  +---------------------------------------------------------+\n");
}

// Initialize the table
cell** initializeTable(int rows, int columns)
{
    cell** table = (cell**)malloc(rows * sizeof(cell*));
    for (int i = 0; i < rows; i++)
    {
        table[i] = (cell*)malloc(columns * sizeof(cell));
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            table[i][j].value = 0;
            table[i][j].cellrow = j + 65;
            table[i][j].cellcolumn = i + 1;
            strcpy(table[i][j].formula, "");
        }
    }

    return table;
}

// Free memory allocated for the table
void freeTable(int rows, cell** table)
{
    for (int i = 0; i < rows; i++)
    {
        free(table[i]);
    }
    free(table);
}

// Function to print cell values with user-defined precision
void printTable(int rows, int columns, cell** table) {
    int i = 0, j = 0;
    int precision = 0;
    char term;

    // Ask the user for the desired precision
    printf("Enter the number of decimal places for precision (maximum %d): ", MAX_PRECISION);

    // Validate precision input
    while (scanf("%d%c", &precision, &term) != 2 || term != '\n') {
        printf("Invalid input. Please enter an integer value: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    if (precision < 0 || precision > MAX_PRECISION) {
        printf("Invalid precision input. Setting precision to maximum (%d).\n", MAX_PRECISION);
        precision = MAX_PRECISION;
    }
    // Calculate the width needed for each cell based on the precision
    int cellWidth = precision + 2; // Precision + width of other characters (including spaces and a decimal point)

    // Printing the content of the table with user-defined precision for values
    // Print headers
    for (j = 0; j < columns; j++) {
        printf("%*.c   ", cellWidth, 'A' + j); // Adjust width for each cell
    }
    printf("\n");

    // Print separator line for headers
    printf("   +");
    for (j = 0; j < columns; j++) {
        for (int k = 0; k < cellWidth + 2; ++k) {
            printf("-");
        }
        printf("+");
    }
    printf("\n");

    // Printing the table rows
    for (i = 0; i < rows; i++) {
        printf("%2d |", i + 1); // Print row index

        // Print each cell's value with the specified precision
        for (j = 0; j < columns; j++) {
            printf(" %.*Lf |", precision, table[i][j].value); // Adjust precision for each cell
        }
        printf("\n");

        // Print separator line between rows
        printf("   +");
        for (j = 0; j < columns; j++) {
            for (int k = 0; k < cellWidth + 2; ++k) {
                printf("-");
            }
            printf("+");
        }
        printf("\n");
    }
}

// Print the names of cells in the current table
void printTableCellsName(int rows, int columns, cell** table)
{
    int i, j;
    int maxCellIndexWidth = 2; // Assuming a maximum of two digits for row indices

    // Print the header row with column indices
    printf("    ");
    for (j = 0; j < columns; j++)
        printf("  %-*c    ", maxCellIndexWidth, 'A' + j); // Adjust spacing based on the maximum cell index width
    printf("\n");

    // Print the separator line for the header row
    printf("  ");
    for (j = 0; j < columns; j++)
        printf("+%*s", maxCellIndexWidth + 2, "-------");
    printf("+\n");

    // Printing the content of the table with row indices
    for (i = 0; i < rows; i++)
    {
        printf("%-*d", maxCellIndexWidth, i + 1); // Print row index with adjusted width
        for (j = 0; j < columns; j++)
        {
            printf("|  %c%-2d  ", table[i][j].cellrow, table[i][j].cellcolumn);
        }
        printf("|\n");

        // Printing the separator line between rows
        printf("  ");
        for (j = 0; j < columns; j++)
            printf("+%*s", maxCellIndexWidth + 2, "-------");
        printf("+\n");
    }
}

// Save table data to a file
void saveTableToFile(int rows, int columns, cell** table, char* filename) {
    FILE* file;
    char extension[] = ".txt";

    char* dot = strrchr(filename, '.');
    if (dot == NULL || dot == filename) {
        size_t len = strlen(filename);
        char* temp = (char*)malloc(len + strlen(extension) + 1);
        if (temp != NULL) {
            strcpy(temp, filename);
            strcat(temp, extension);
            file = fopen(temp, "w");
            free(temp);
        }
        else {
            printf("Memory allocation error.\n");
            return;
        }
    }
    else {
        file = fopen(filename, "w");
    }

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%d_%d_", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            fprintf(file, "%Lf\n", table[i][j].value);
            fprintf(file, "%s\n", table[i][j].formula);
        }
    }

    fclose(file);
    printf("Table data saved to %s.\n", filename);
}

// loading table data from a file
void loadTableFromFile(int* rows, int* columns, cell*** table, char* filename) {
    FILE* file = NULL; // Initialize the file pointer

    char extension[] = ".txt";
    char* dot = strrchr(filename, '.');

    if (dot == NULL || dot == filename) {
        size_t len = strlen(filename);
        char* temp = (char*)malloc(len + strlen(extension) + 1);
        if (temp != NULL) {
            strcpy(temp, filename);
            strcat(temp, extension);
            file = fopen(temp, "r");
            if (file == NULL) {
                printf("Error opening file for reading.\n");
                free(temp);
                return;
            }
            free(temp);
        }
    }
    else {
        // If the file has an extension, open it directly
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening file for reading.\n");
            return;
        }
    }

    int loadedRows, loadedColumns;
    fscanf(file, "%d_%d_", &loadedRows, &loadedColumns);

    cell** loadedTable = initializeTable(loadedRows, loadedColumns);

    for (int i = 0; i < loadedRows; i++) {
        for (int j = 0; j < loadedColumns; j++) {
            fscanf(file, "%Lf", &loadedTable[i][j].value);
            fgets(loadedTable[i][j].formula, MAX_FORMULA_LENGTH, file);
            size_t length = strlen(loadedTable[i][j].formula);
            if (length > 0 && loadedTable[i][j].formula[length - 1] == '\n') {
                loadedTable[i][j].formula[length - 1] = '\0'; // Remove newline if present
            }
        }
    }

    fclose(file);

    freeTable(*rows, *table);

    *rows = loadedRows;
    *columns = loadedColumns;
    *table = loadedTable;

    printf("Table data loaded from %s.\n", filename);
}

// add extention if it was needed!
void addExtensionIfNeeded(char* filename, const char* extension) {
    char* dot = strrchr(filename, '.');
    if (dot == NULL || dot == filename) {
        strcat(filename, extension);
    }
}

// Formula menu
void formulaMenu(int rows, int columns, cell** table)
{
    int formulaOption = 1;
    do
    {
        // Formula menu
        printf("\nFormula Functions:\n");
        printf("\n********************************\n");
        printf("*      Enter Cell Formula      *\n");
        printf("********************************\n");
        printf("* Format: [Column][Row]        *\n");
        printf("* Columns: A - %c               *\n", 'A' + columns - 1);
        printf("* Rows: 1 - %d                  *\n", rows);
        printf("********************************\n");
        printf("0. Exit Formula Menu\n");
        printf("1. Enter Formula\n2. Display Formulas\n");

        printf("Please choose a formula function (0 to exit): ");
        scanf("%d", &formulaOption);

        if (formulaOption == 1)
        {
            enterFormula(rows, columns, table);
        }
        else if (formulaOption == 2)
        {
            displayFormulas(rows, columns, table);
        }
        else if (formulaOption != 0)
        {
            printf("Invalid formula option. Please choose a valid option.\n");
        }

    } while (formulaOption != 0);
}

// Enter formula into a specific cell
void enterFormula(int rows, int columns, cell** table)
{
    char column;
    int row;

    printf("\nEnter the cell location: ");
    clearInputBuffer();
    scanf("%c%d", &column, &row);

    // Validate the column input
    if (column < 'A' || column > 'A' + columns - 1 || row < 1 || row > rows) {
        printf("Invalid input. Please enter a valid cell location.\n");
        return;
    }

    // Calculate array indices
    int rowIndex = row - 1;
    int columnIndex = column - 'A';


    printf("Please enter the formula for the cell %c%d: ", column, row);
    clearInputBuffer();
    fgets(table[rowIndex][columnIndex].formula, MAX_FORMULA_LENGTH, stdin);

    // Remove newline character at the end of the formula, if it exists
    size_t length = strlen(table[rowIndex][columnIndex].formula);
    if (length > 0 && table[rowIndex][columnIndex].formula[length - 1] == '\n') {
        table[rowIndex][columnIndex].formula[length - 1] = '\0'; // Replace newline with null terminator
    }

    table[rowIndex][columnIndex].value = evaluateCellFormula(rows, columns, table, rowIndex, columnIndex);
    printf("\nFormula entered successfully into cell %c%d.\n", column, row);
}

// Display all formulas in the table
void displayFormulas(int rows, int columns, cell** table)
{
    printf("\nFormulas in the table:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (strlen(table[i][j].formula) > 1)
            {
                printf("Cell %c%d Formula: %s\n", table[i][j].cellrow, table[i][j].cellcolumn, table[i][j].formula);
            }
        }
    }
}


void evaluateFormulas(int rows, int columns, cell** table)
{
    // Iterate through each cell and evaluate formulas
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (strlen(table[i][j].formula) > 4)
            {
                table[i][j].value = evaluateCellFormula(rows, columns, table, i, j);
            }
        }
    }

    printf("Formulas evaluated and table updated successfully.\n");
}

// Implementation of new formula evaluation functions
long double evaluateCellFormula(int rows, int columns, cell** table, int rowIndex, int columnIndex)
{
    char formula[MAX_FORMULA_LENGTH];
    strncpy(formula, table[rowIndex][columnIndex].formula, MAX_FORMULA_LENGTH - 1);
    formula[MAX_FORMULA_LENGTH - 1] = '\0'; // Ensure null-termination

    // Check if the formula is empty or contains only spaces
    int i;
    for (i = 0; formula[i] != '\0'; i++) {
        if (!isspace(formula[i])) {
            break;
        }
    }

    if (formula[i] == '\0' || (strcmp(formula, " ") == 0)) {
        // Formula is empty or contains only spaces, return without evaluating
        return 1.0; // Or any appropriate default value
    }

    // Rest of the evaluation logic
    int tokenNum = 0;
    long double result = 0;
    char** formulaTokens = tokenizeExpression(formula, &tokenNum);

    evaluateToken(formulaTokens, tokenNum, table);
    result = atof(formulaTokens[0]);

    free(formulaTokens); // Free the allocated memory
    return result;
}


void enterCellData(int rows, int columns, cell** table) {
    printf("\n********************************\n");
    printf("*       Enter Cell Data        *\n");
    printf("********************************\n");
    printf("* Format: [Column][Row]        *\n");
    printf("* Columns: A - %c               *\n", 'A' + columns - 1);
    printf("* Rows: 1 - %d                  *\n", rows);
    printf("********************************\n");

    char column;
    int row;

    printf("\nEnter the cell location: ");
    scanf(" %c%d", &column, &row);

    // Validate the column input
    if (column < 'A' || column > 'A' + columns - 1 || row < 1 || row > rows) {
        printf("Invalid input. Please enter a valid cell location.\n");
        return;
    }

    // Calculate array indices
    int rowIndex = row - 1;
    int columnIndex = column - 'A';

    printf("Enter the value for cell %c%d: ", column, row);
    scanf("%Lf", &table[rowIndex][columnIndex].value);
    printf("\n********************************\n");
    printf("* Data entered successfully    *\n");
    printf("* into cell %c%d.               *\n", column, row);
    printf("********************************\n");
}


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}


void freeTokens(char** tokens, int numTokens) {
    if (tokens != NULL) {
        for (int i = 0; i < numTokens; i++) {
            if (tokens[i] != NULL) {
                free(tokens[i]);
                tokens[i] = NULL; // Set freed pointers to NULL for safety
            }
        }
        free(tokens);
        tokens = NULL; // Set the main pointer to NULL after freeing
    }
}

// It's a place that all of your calculation would have answer :)
void calculatorPlayground(int rows, int columns, cell** table) {
    printHelp();
    // Buffer to store the user's mathematical expression
    char expression[MAX_EXPRESSION_LENGTH];
    clearInputBuffer();
    // Clear input buffer and prompt the user for an expression
    printf("\nPlease enter your mathematical expression for us to calculate: ");
    // Read the user's input expression
    if (fgets(expression, MAX_EXPRESSION_LENGTH, stdin)) {
        // Remove newline character from the entered expression
        size_t len = strlen(expression);
        if (len > 0 && expression[len - 1] == '\n') {
            expression[len - 1] = '\0';
        }

        int numTokens = 0;
        // Tokenize the expression to obtain individual elements
        char** tokens = tokenizeExpression(expression, &numTokens);

        if (numTokens == 1 || numTokens == 2 || numTokens == 0) {
            printf("Invalid Input!\nPlease press any key and then press enter\n");
            calculatorPlayground(rows, columns, table);
        }
        // Evaluate the expression tokens to obtain the result
        evaluateToken(tokens, numTokens, table);

        // Fetch the result and display it to the user
        long double result = atof(tokens[0]);
        printf("Result: %.18Lf\n", result);

        // Free memory allocated for tokens
        free(tokens);
    }
    else {
        printf("Error reading input.\n");
    }
}

// function to tokenize Expressions
char** tokenizeExpression(char* expression, int* numTokens) {
    char delim[] = " ";
    char* token = strtok(expression, delim);
    char** tokens = NULL;
    int size = 0;

    while (token != NULL) {
        char** temp = (char**)realloc(tokens, (size + 1) * sizeof(char*));
        if (temp == NULL) {
            freeTokens(tokens, size); // Free allocated memory
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        tokens = temp;

        tokens[size] = (char*)malloc((strlen(token) + 1) * sizeof(char));
        if (tokens[size] == NULL) {
            freeTokens(tokens, size + 1); // Free allocated memory
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }

        strcpy(tokens[size], token);
        size++;
        (*numTokens)++;

        token = strtok(NULL, delim);
    }

    return tokens;
}

// Function to evaluate the function operators
long double evaluateFunction(char* function, long double argument, long double base) {
    argument = (double)argument;
    base = (double)base;
    if (strcmp(function, "sin") == 0) {
        return sin(argument / 57.2957795);
    }
    else if (strcmp(function, "cos") == 0) {
        return cos(argument / 57.2957795);
    }
    else if (strcmp(function, "tan") == 0) {
        return tan(argument / 57.2957795);
    }
    else if (strcmp(function, "cot") == 0) {
        return 1.0 / tan(argument / 57.2957795);
    }
    else if (strcmp(function, "csc") == 0) {
        return 1.0 / sin(argument / 57.2957795);
    }
    else if (strcmp(function, "sec") == 0) {
        return 1.0 / cos(argument / 57.2957795);
    }
    else if (strcmp(function, "asin") == 0) {
        return asin(argument / 57.2957795);
    }
    else if (strcmp(function, "acos") == 0) {
        return acos(argument / 57.2957795);
    }
    else if (strcmp(function, "atan") == 0) {
        return atan(argument / 57.2957795);
    }
    else if (strcmp(function, "acot") == 0) {
        return atan(1.0 / (argument / 57.2957795));
    }
    else if (strcmp(function, "asec") == 0) {
        return acos(1.0 / (argument / 57.2957795));
    }
    else if (strcmp(function, "acsc") == 0) {
        return asin(1.0 / (argument / 57.2957795));
    }
    else if (strcmp(function, "sinh") == 0) {
        return sinh(argument / 57.2957795);
    }
    else if (strcmp(function, "cosh") == 0) {
        return cosh(argument / 57.2957795);
    }
    else if (strcmp(function, "tanh") == 0) {
        return tanh(argument / 57.2957795);
    }
    else if (strcmp(function, "coth") == 0) {
        return 1.0 / tanh(argument / 57.2957795);
    }
    else if (strcmp(function, "csch") == 0) {
        return 1.0 / sinh(argument / 57.2957795);
    }
    else if (strcmp(function, "sech") == 0) {
        return 1.0 / cosh(argument / 57.2957795);
    }
    else if (strcmp(function, "asinh") == 0) {
        return asinh(argument / 57.2957795);
    }
    else if (strcmp(function, "acosh") == 0) {
        return acosh(argument / 57.2957795);
    }
    else if (strcmp(function, "atanh") == 0) {
        return atanh(argument / 57.2957795);
    }
    else if (strcmp(function, "acoth") == 0) {
        return atanh(1.0 / (argument / 57.2957795));
    }
    else if (strcmp(function, "acsch") == 0) {
        return asinh(1.0 / (argument / 57.2957795));
    }
    else if (strcmp(function, "asech") == 0) {
        return acosh(1.0 / (argument / 57.2957795));
    }
    else if (strcmp(function, "sqrt") == 0) {
        return sqrt(argument);
    }
    else if (strcmp(function, "ceil") == 0) {
        return ceil(argument);
    }
    else if (strcmp(function, "floor") == 0) {
        return floor(argument);
    }
    else if (strcmp(function, "exp") == 0) {
        return exp(argument);
    }
    else if (strcmp(function, "!") == 0) {
        // Calculate factorial manually
        if (argument < 0 || argument != (int)argument) {
            printf("Error: Factorial is defined for non-negative integers only.\n");
            exit(EXIT_FAILURE);
        }
        long double result = 1.0;
        for (int i = 2; i <= (int)argument; ++i) {
            result *= i;
        }
        return result;
    }
    else if (strcmp(function, "ln") == 0) {
        return log(argument); // Natural logarithm
    }
    else if (strcmp(function, "log") == 0) {
        return log10(argument); // Base-10 logarithm
    }
    else if (strcmp(function, "log2") == 0) {
        return log2(argument); // Base-2 logarithm
    }
    else if (strcmp(function, "logb") == 0) {
        return log(argument) / log(2); // Base-b logarithm (defaulting to base 2)
    }
    else if (strcmp(function, "log10") == 0) {
        return log10(argument); // Base-10 logarithm
    }
    else if (strcmp(function, "logn") == 0) {
        return log(argument) / log(base); // log_n(x) = log(x) / log(base)
    }
    else if (strcmp(function, "abs") == 0 || strcmp(function, "fabs") == 0) {
        return fabs(argument); // Absolute value
    }
    else if (strcmp(function, "round") == 0) {
        return round(argument); // Round to the nearest integer
    }
    else {
        // Handle other functions accordingly
        printf("Error: Unsupported function: %s\n", function);
        exit(EXIT_FAILURE);
    }
}


void performOperation(char** tokens, int index, int* numTokens) {
    // Perform the operation indicated by the operator at index 'index'
    // Example: Assuming the operator is at index 'index' in 'tokens'

    // Fetch the operator and its surrounding numbers
    char* operator1 = tokens[index];
    long double number1 = atof(tokens[index - 1]);
    long double number2 = atof(tokens[index + 1]);
    long double result = 0.0;

    // Perform operation based on the operator
    switch (getPrecedence(operator1)) {
    case 4: // Exponentiation (^)
        result = 1;
        for (int asd = 0; asd < number2; asd++) {
            result *= number1;
        }
        break;
    case 3: // Multiplication (*) and Division (/)
        if (strcmp(operator1, "*") == 0) {
            if (number2 == 0 || number1 == 0) {
                result = 0;
                break;
            }
            result = number1 * number2;
        }
        else if (strcmp(operator1, "/") == 0) {
            if (number2 != 0) {
                result = number1 / number2;
            }
            else {
                fprintf(stderr, "Error: Division by zero is not allowed!\n");
                return; // Error handling - division by zero
            }
        }
        break;
    case 2: // Addition (+) and Subtraction (-)
        if (strcmp(operator1, "+") == 0) {
            result = number1 + number2;
        }
        else if (strcmp(operator1, "-") == 0) {
            result = number1 - number2;
            printf("%Lf", result);
        }
        break;
    default:
        fprintf(stderr, "Error: Invalid operator encountered!\n");
        return; // Error handling - invalid operator
    }

    // Update tokens with the result and adjust the number of tokens
    sprintf(tokens[index - 1], "%.18Lf", result);

    // Shift remaining tokens to the left
    for (int j = index; j < *numTokens - 2; j++) {
        strcpy(tokens[j], tokens[j + 2]);
    }

    *numTokens -= 2; // Update the number of tokens
}


void evaluateToken(char** tokens, int numTokens, cell** table) {

    // Evaluate cell references in the expression
    int row, column;
    for (int i = 0; i < numTokens; i++) {
        char* token = tokens[i];
        if (isCellReference(token)) {
            // Extract cell indices from the token and replace with cell value
            extractCellIndices(token, &row, &column);
            sprintf(tokens[i], "%Lf", table[row][column].value);
        }
    }

    // Evaluate functions and expressions within parentheses
    for (int i = 0; i < numTokens; i++) {
        char* token = tokens[i];
        if (isOperator(token)) {
            continue; // Skip if the token is an operator
        }
        if ((strcmp(token, "(") == 0) && i != 0) {
            int functionStart = i - 1;
            char* functionName = tokens[functionStart];

            // Check if it's a function
            if (functionStart >= 0 && isFunction(functionName)) {
                // Find the end of the function argument
                int functionEnd = i + 1;
                int openParenthesesCount = 1;
                while (openParenthesesCount > 0 && functionEnd < numTokens) {
                    if (strcmp(tokens[functionEnd], "(") == 0) {
                        openParenthesesCount++;
                    }
                    else if (strcmp(tokens[functionEnd], ")") == 0) {
                        openParenthesesCount--;
                    }
                    functionEnd++;
                }

                // Extract the function argument tokens
                int argumentStart = i + 1;
                int argumentEnd = functionEnd - 1;
                int argumentLength = argumentEnd - argumentStart + 1;

                // Allocate memory for the array of argument tokens
                char** argumentTokens = (char**)malloc((argumentLength + 1) * sizeof(char*));

                // Copy each argument token separately
                for (int j = 0; j < argumentLength; j++) {
                    argumentTokens[j] = (char*)malloc((strlen(tokens[argumentStart + j]) + 1) * sizeof(char));
                    strcpy(argumentTokens[j], tokens[argumentStart + j]);
                }

                // Evaluate the function argument recursively
                evaluateToken(argumentTokens, argumentLength, table);
                long double argumentResult = atof(argumentTokens[0]); // Assuming result is in the first token

                // Evaluate the function with the computed argument
                long double result = evaluateFunction(functionName, argumentResult, 10);

                // Replace the function token and its argument tokens with the result
                sprintf(tokens[functionStart], "%.18Lf", result);
                for (int j = functionStart + 1; j <= functionEnd - 1; j++) {
                    strcpy(tokens[j], ""); // Clear tokens within the function arguments
                }

                // Update the number of tokens after removing evaluated function and arguments
                int tokensToRemove = functionEnd - functionStart + 2;
                numTokens -= tokensToRemove;

                // Shift tokens to remove empty elements from the array
                for (int j = i; j < numTokens; j++) {
                    strcpy(tokens[j], tokens[j + tokensToRemove]);
                }
                printf("\n\n"); printTokens(tokens, numTokens);printf("\n\n\n");
                i--; // Revisit the current position for new evaluation

                free(argumentTokens); // Free memory allocated for argumentTokens
            }
        }
    }

    // Evaluate expressions within parentheses
    for (int i = 0; i < numTokens; i++) {
        char* token = tokens[i];
        if (strcmp(token, "(") == 0) {
            // Recursively evaluate the sub-expression within parentheses
            evaluateParentheses(tokens, &numTokens, i);
            i--; // Revisit the current position for new evaluation
        }
    }

    // Evaluate operators by precedence
    for (int precedence = 4; precedence >= 1; precedence--) {
        for (int i = 0; i < numTokens; i++) {
            char* token = tokens[i];
            if (isOperator(token) && getPrecedence(token) == precedence) {
                // Perform the operation indicated by the operator
                performOperation(tokens, i, &numTokens);
                i--; // Revisit the current position for new evaluation
            }
        }
    }
}


void evaluateParentheses(char** tokens, int* numTokens, int start) {
    int i;
    int parenthesisCount = 1;
    int j;


    // Find the matching closing parenthesis
    for (i = start + 1; i < *numTokens; i++) {
        if (strcmp(tokens[i], "(") == 0) {
            parenthesisCount++;
        }
        else if (strcmp(tokens[i], ")") == 0) {
            parenthesisCount--;
            if (parenthesisCount == 0) {
                break; // Found the matching closing parenthesis
            }
        }
    }

    // Calculate the length of the sub-expression
    int subExpressionLength = i - start - 1;
    printf("%d", subExpressionLength);
    // Allocate memory for the sub-expression
    char** subExpression = (char**)malloc((subExpressionLength + 1) * sizeof(char*));
    if (subExpression == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Copy tokens of the sub-expression to evaluate
    for (j = 0; j < subExpressionLength + 1; j++) {
        subExpression[j] = (char*)malloc((strlen(tokens[start + j + 1]) + 1) * sizeof(char));
        if (subExpression[j] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(subExpression[j], tokens[start + j + 1]);
    }

    // Evaluate the sub-expression recursively
    evaluateToken(subExpression, subExpressionLength, table);

    // Remove the tokens inside the parentheses
    for (j = start + 1; j <= i; j++) {
        tokens[j] = NULL;
    }

    // Shift the remaining tokens to accommodate the evaluated result
    int shiftAmount = subExpressionLength + 1; // Including '(' and ')'
    for (j = i ; j < *numTokens; j++) {
        tokens[j - shiftAmount] = tokens[j];
    }

    // Copy the evaluated sub-expression result to the start position
    for (j = 0; j < subExpressionLength; j++) {
        tokens[start + j] = subExpression[j];
    }

    *numTokens -= shiftAmount; // Update the number of tokens

    subExpression = NULL;
    printf("\n\n\n\n\n"); printTokens(tokens, *numTokens); printf("\n\n\n\n\n\n");
}


int isNumeric(const char* str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return 0; // Not a numeric character
        }
        str++;
    }
    return 1; // Entire string is numeric
}


void formatLongDouble(long double num, int precision) {
    char formatted[50]; // Adjust size according to your needs
    int numChars = snprintf(formatted, sizeof(formatted), "%.*Lf", precision, num);

    int separatorCount = (numChars - 1) / 3; // Calculate the number of separators needed
    int formattedLen = numChars + separatorCount; // Adjusted length with separators

    char* result = (char*)malloc((formattedLen + 1) * sizeof(char)); // Dynamically allocate memory for the formatted output
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    result[formattedLen] = '\0'; // Null-terminate the string

    int resultIndex = formattedLen - 1; // Index for the formatted string
    int count = 0; // Counter for adding separators

    for (int i = numChars - 1; i >= 0; i--) {
        if (count > 0 && count % 3 == 0) {
            memmove(result + resultIndex - 1, result + resultIndex, strlen(result + resultIndex) + 1); // Shift characters to make space for a separator
            result[resultIndex - 1] = ' '; // Add a space as a separator
            resultIndex--; // Move the index back due to the added space
            count = 0; // Reset the counter for the next separator
        }

        result[resultIndex--] = formatted[i]; // Copy characters from the original formatted string
        count++;
    }

    printf("%s\n", result); // Print the formatted string with spaces as separators

    free(result); // Free dynamically allocated memory
}

// Function to check if a token is a cell reference
int isCellReference(char* token) {
    if (token == NULL || strlen(token) < 2) {
        return 0; // Cell reference should have at least two characters (e.g., "A1")
    }

    // Check if the first character is a letter (A-Z)
    if (!isalpha(token[0])) {
        return 0;
    }

    // Check if the remaining characters are digits (0-9)
    for (size_t i = 1; i < strlen(token); ++i) {
        if (!isdigit(token[i])) {
            return 0;
        }
    }

    return 1; // Token resembles a cell reference (e.g., "A1")
}

// Function to extract cell indices from a token
void extractCellIndices(char* token, int* row, int* column) {
    if (token == NULL || strlen(token) < 2) {
        *row = -1; // Invalid token, set row index to -1 (or handle error accordingly)
        *column = -1;
        return;
    }

    // Assuming cell references start with a letter (A-Z) followed by digits (0-9)
    // Convert the alphabetical part to a column index
    *column = toupper(token[0]) - 'A';

    // Convert the numeric part to a row index
    *row = atoi(token + 1) - 1; // Assuming the row number starts from 1
}

// function to print the tokens
void printTokens(char** tokens, int numTokens) {
    printf("Tokens:\n");
    for (int i = 0; i < numTokens; ++i) {
        printf("%s\n", tokens[i]);
    }
}

// Function to check if token is an operator
int isOperator(char* token) {
    return (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 ||
        strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || strcmp(token, "^") == 0);
}

// Function to check if a token is a function
int isFunction(char* token) {
    if (
        // Trigonometric functions
        strcmp(token, "sin") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tan") == 0 || strcmp(token, "cot") == 0 ||
        strcmp(token, "csc") == 0 || strcmp(token, "sec") == 0 || strcmp(token, "asin") == 0 || strcmp(token, "acos") == 0 ||
        strcmp(token, "atan") == 0 || strcmp(token, "acot") == 0 || strcmp(token, "acsc") == 0 || strcmp(token, "asec") == 0 ||
        // Hyperbolic functions
        strcmp(token, "sinh") == 0 || strcmp(token, "cosh") == 0 || strcmp(token, "tanh") == 0 || strcmp(token, "coth") == 0 ||
        strcmp(token, "csch") == 0 || strcmp(token, "sech") == 0 || strcmp(token, "asinh") == 0 || strcmp(token, "acosh") == 0 ||
        strcmp(token, "atanh") == 0 || strcmp(token, "acoth") == 0 || strcmp(token, "acsch") == 0 || strcmp(token, "asech") == 0 ||
        // Other functions
        strcmp(token, "sqrt") == 0 || strcmp(token, "ceil") == 0 || strcmp(token, "floor") == 0 || strcmp(token, "factorial") == 0 ||
        strcmp(token, "ln") == 0 || strcmp(token, "log") == 0 || strcmp(token, "exp") == 0 || strcmp(token, "abs") == 0 ||
        strcmp(token, "fabs") == 0 || strcmp(token, "round") == 0
        ) {
        return 1; // Token matches a supported function
    }
    return 0; // Token does not match any supported function
}

// Function to determine the precedence of operators
int getPrecedence(char* oper) {
    if (strcmp(oper, "^") == 0) {
        return 4; // Highest in normal mathematical operations precedence for exponentiation
    }
    else if (isFunction(oper)) {
        return 5; // Assign a higher precedence value for functions
    }
    else if (strcmp(oper, "*") == 0 || strcmp(oper, "/") == 0) {
        return 3; // Higher precedence for multiplication and division
    }
    else if (strcmp(oper, "+") == 0 || strcmp(oper, "-") == 0) {
        return 2; // Lower precedence for addition and subtraction
    }
    else {
        return 1; // Default precedence
    }
}