#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 10
#define MAX_QUERY 5

/// @author Wilfredo Joel Solano
/// @date 27/04/23 inicio
/// @date 29/04/23 version actual

void freeMatrix(int**, int);

/// @brief For show the matrix
/// @param matrix int**
/// @param row int
/// @param col int
void showMatrix(int**, int, int);

/// @brief This function allows initiaze the matrix
/// @param matrix int**
/// @param row int
/// @param col int
/// @return int** 
int** initMatrix(int**, int, int);

/// @brief It is used to obtain the transverse matrix of the matrix entered as a parameter
/// @param matrix 
/// @param row 
/// @param col 
/// @return int** transver matrix
int** gettransverseMatrix(int**, int, int);

/// @brief It is used to obtain the transposed matrix of the matrix entered as a parameter
/// @param matrix int**
/// @param row int
/// @param col int
/// @return int** transposed matrix
int** getTranposedMatrix(int**, int, int);

/// @brief This function use getAddProd and getCol for obtain the product matrix
/// @param matrixA 
/// @param matrixB 
/// @param row row to matrix A
/// @param col col to matrix B
/// @param n col to matrix A = row to matrix B
/// @return int** product to matrixA x matrixB
int** prodMatrix(int**, int**, int, int, int);

/// @brief This function allows obtaining the sum of the matrices entered
/// @param matrixA 
/// @param matrixB 
/// @param row
/// @param col 
/// @return int** summation to matrixA + matrixB
int** addMatrix(int**, int**, int, int);

/// @brief This function allows obtaining the type that the matrix will have 
/// @param matrix 
/// @param row 
/// @param col 
/// @param format can be [-tv trasverse 3] [-tp tranposed 2] [-nor normal 1]
/// @return 
int** matrixFormat(int**, int, int, int);

/// @brief It is used to obtain the column of the matrix 
/// @param matrix
/// @param col is for the column you want to get
/// @param size is for the size of the matrix
/// @return int* column that you request
int* getCol(int**, int, int);

/// @brief It is used to obtain the summation of the products to the rows and colums
/// @param rowA
/// @param colB
/// @param n size to the arrow and column 
/// @return int summation of the products to the rows and colums 
int getAddProd(int*, int*, int);

/// @brief It is used to obtain the task that need do
/// @param strQuery char*
/// @param pos int
/// @return int
int getTypeQuery(char*, int);

/// @brief This function going to be calculate the determinant of matrix
/// @param  
/// @param  
/// @param  
/// @return 
int getDeterminantToMatrix(int**, int, int);

/// @brief Is used when the operations going to make with the same matrix
/// @param matrixA 
/// @param rowA 
/// @param colA 
/// @param task 
void actTask(int**, int, int, int, int);

/// @brief Is used when for to make the operations is need to read other matrix
/// @param matrixA 
/// @param rowA 
/// @param colA 
/// @param matrixB 
/// @param rowB 
/// @param colB 
/// @param task 
void sigTask(int**, int, int, int**, int, int, int, int, int);

/// @brief function that order the operations
/// @param file 
void getTaskToMake(FILE *);

int main()
{
  FILE *file = fopen("./inMatrices", "r");
  if (file == NULL)
  {
    printf("error");
    return 1;
  }
  getTaskToMake(file);
  return 0;
}

void freeMatrix(int** matrix, int row)
{
  for (int i=0; i<row; i++)
    free(matrix[i]);
  free(matrix);
}

void showMatrix(int** matrix, int row, int col)
{
  for (int i=0; i < row; i++)
  {
    for (int j=0; j < col; j++)
      printf("[%d]\t", matrix[i][j]);
    printf("\n");
  }
}

int** initMatrix(int** matrix, int row, int col)
{
  matrix = (int**) malloc(row * sizeof(int*));
    for (int i=0; i < row; i++)
      matrix[i] = (int*) malloc(col * sizeof(int));

  return matrix;
}

int** gettransverseMatrix(int** matrix, int row, int col)
{
  int** tvmatrix = initMatrix(tvmatrix, row, col);
  
  for (int i=0; i < row; i++)
    for (int j=0; j < col; j++)
      tvmatrix[i][j] = (-1) * matrix[i][j];

  return tvmatrix;
}

int** getTranposedMatrix(int** matrix, int row, int col)
{
  int** tmatrix = initMatrix(tmatrix, row, col);
  
  for (int i=0; i < row; i++)
    for (int j=0; j < col; j++)
      tmatrix[i][j] = matrix[j][i];

  return tmatrix;
}

int** prodMatrix(int** matrixA, int** matrixB, int row, int col, int n)
{
  int** matrixC = initMatrix(matrixC, row, col);

  for (int i=0; i < row; i++)
    for (int j=0; j < col; j++)
    {
      int total = 0;
      for (int k = 0; k < n; k++)
        total += (matrixA[i][k] * matrixB[k][j]);
      
      matrixC[i][j] = total;
    }

  return matrixC; 
}

int** addMatrix(int** matrixA, int** matrixB, int row, int col)
{
  int** matrixC = initMatrix(matrixC, row, col);

  for (int i=0; i < row; i++)
    for (int j=0; j < col; j++)
      matrixC[i][j] = (matrixA[i][j] + matrixB[i][j]);

  return matrixC;
}

int** matrixFormat(int** matrix, int row, int col, int format)
{
  if (format == 1) return matrix;
  if (format == 2) return getTranposedMatrix(matrix, col, row);
  if (format == 3) return gettransverseMatrix(matrix, row, col);
  return matrix;
}

int getTypeQuery(char* strQuery, int pos)
{
  int n = 0;
  //printf("\t%s\n", strQuery);
  switch (pos)
  {
  case 1:
    {
      if (strcmp(strQuery, "-n") == 0) n = 1;
      if (strcmp(strQuery, "-tp") == 0) n = 2;
      if (strcmp(strQuery, "-tv") == 0) n = 3;
    }
    break;
  
  case 2:
    {
      if (strcmp(strQuery, "-act") == 0) n = 1;
      if (strcmp(strQuery, "-sig") == 0) n = 2;
    }
    break;
  
  case 3:
    {
      if (strcmp(strQuery, "-det") == 0) n = 1;
      if (strcmp(strQuery, "-sum") == 0) n = 2;
      if (strcmp(strQuery, "-pro") == 0) n = 3;
    }
    break;
  
  case 4:
    {
      if (strcmp(strQuery, "-n") == 0) n = 1;
      if (strcmp(strQuery, "-tp") == 0) n = 2;
      if (strcmp(strQuery, "-tv") == 0) n = 3;
    }
    break;

  case 5:
    {
      if (strcmp(strQuery, "1") == 0) n = 1;
      if (strcmp(strQuery, "0") == 0) n = 0;
    }

  default:
    n = 0;
    break;
  }
  
  return n;
}

void actTask(int** matrixA, int rowA, int colA, int format, int task)
{
  switch (task)
  {
  case 1:
    {
      printf("programando");
    }
    break;
  
  case 2:
    {
      printf("Suma resultante");
      if (format == 2)
        showMatrix(addMatrix(matrixFormat(matrixA, rowA, colA, format), matrixFormat(matrixA, rowA, colA, format), colA, rowA), colA, rowA);
      else 
        showMatrix(addMatrix(matrixA, matrixFormat(matrixA, rowA, colA, format), rowA, colA), rowA, colA);
    }
    break;

  case 3:
    {
      printf("Producto resultante");
      if (format == 2)
        showMatrix(prodMatrix(matrixFormat(matrixA, rowA, colA, format), matrixA, colA, colA, rowA), colA, colA);
      else
      {
        int rowT = colA, colT = rowA;
        int **temp = initMatrix(temp, rowT, colT);
        temp = getTranposedMatrix(matrixFormat(matrixA, rowA, colA, format), rowT, colT);
        showMatrix(temp, rowT, colT);
        showMatrix(matrixA, rowA, colA);
        showMatrix(prodMatrix(matrixA, temp, rowA, rowA, colA), rowA, rowA);
      }
    }
    break;
  
  default:
    break;
  }
}

void sigTask(int** matrixA, int rowA, int colA, int** matrixB, int rowB, int colB, int formatA, int formatB, int task)
{
  switch (task)
  {
  case 1: // determinante
    {
      printf("programando");
    }
    break;
  
  case 2: // suma
    {
      if (formatA == 2)
      {
        printf("Matrix: \n");
        showMatrix(getTranposedMatrix(matrixA, colA, rowA), colA, rowA);
        printf("\n");
      }
      else
      {
        printf("Matrix: \n");
        showMatrix(matrixA, rowA, colA);
        printf("\n");
      }
      
      if (formatB == 2)
      {
        printf("Matrix: \n");
        showMatrix(getTranposedMatrix(matrixB, colB, rowB), colB, rowB);
        printf("\n");
      }
      else
      {
        printf("Matrix: \n");
        showMatrix(matrixB, rowB, colB);
        printf("\n");
      }

      printf("Suma resultante:\n");
      if (rowA == rowB && colA == colB && formatA != 2 && formatB != 2)
        showMatrix(addMatrix(matrixFormat(matrixA, rowA, colA, formatA), matrixFormat(matrixB, rowB, colB, formatB), rowA, colA), rowA, colA);
      else if (rowA == colB && colA == rowB && ((formatA == 2) ^ (formatB == 2)))
        showMatrix(addMatrix(matrixFormat(matrixA, rowA, colA, formatA), matrixFormat(matrixB, rowB, colB, formatB), colA, rowA), colA, rowA);
      else if (rowA == rowB && colA == colB && formatA == 2 && formatB == 2)
        showMatrix(addMatrix(matrixFormat(matrixA, rowA, colA, formatA), matrixFormat(matrixB, rowB, colB, formatB), colA, rowA), colA, rowA);
      else
        printf("matrixA format %i: %ix%i\t matrixB format %i: %ix%i\nNo se pueden sumar\n", formatA, rowA, colA, formatB, rowB, colB);
    }
    break;

  case 3: // producto
    {
      if (formatA == 2)
      {
        printf("Matrix: \n");
        showMatrix(getTranposedMatrix(matrixA, colA, rowA), colA, rowA);
        printf("\n");
      }
      else
      {
        printf("Matrix: \n");
        showMatrix(matrixA, rowA, colA);
        printf("\n");
      }

      if (formatB == 2)
      {
        printf("Matrix: \n");
        showMatrix(getTranposedMatrix(matrixB, colB, rowB), colB, rowB);
        printf("\n");
      }
      else
      {
        printf("Matrix: \n");
        showMatrix(matrixB, rowB, colB);
        printf("\n");
      }

      printf("Producto resultante:\n");
      if (rowA == rowB && formatA == 2 && formatB != 2)
      {
        showMatrix(prodMatrix(matrixFormat(matrixA, rowA, colA, formatA), matrixFormat(matrixB, rowB, colB, formatB), colA, colB, rowA), colA, colB);
      }
      else if (colA == colB && formatA != 2 && formatB == 2)
      {
        showMatrix(prodMatrix(matrixFormat(matrixA, rowA, colA, formatA), matrixFormat(matrixB, rowB, colB, formatB), rowA, rowB, colA), rowA, rowB);
      }
      else if (colA == rowB && formatA != 2 && formatB != 2)
      {
        showMatrix(prodMatrix(matrixFormat(matrixA, rowA, colA, formatA), matrixFormat(matrixB, rowB, colB, formatB), rowA, colB, colA), rowA, colB);
      }
      else if (formatA == 2 && formatB == 2 && rowA == colB)
      {
        showMatrix(prodMatrix(matrixFormat(matrixA, rowA, colA, formatA), matrixFormat(matrixB, rowB, colB, formatB), colA, rowB, rowA), colA, rowB);
      }
      else
        printf("matrixA format %i: %ix%i\t matrixB format %i: %ix%i\nNo se pueden multiplicar\n", formatA, rowA, colA, formatB, rowB, colB);
    }
    break;
  
  default:
    break;
  }
}

void getTaskToMake(FILE *file)
{
  int **matrixA;

  char **input;
  input = (char**) malloc(MAX_QUERY * sizeof(char*));
  for (int i=0; i < MAX_QUERY; i++)
    input[i] = (char*) malloc(MAX_LEN * sizeof(char));
  int *inValue;
  inValue = (int*) malloc(MAX_QUERY * sizeof(int));

  bool exe = true;

  int rowA, colA;

  while (exe)
  {
    fscanf(file, "%s %s %s %s %s", input[0], input[1], input[2], input[3], input[4]);
    
    for (int i=0; i < MAX_QUERY; i++)
      inValue[i] = getTypeQuery(input[i], i+1);

    fscanf(file, "%i %i", &rowA, &colA);
    matrixA = initMatrix(matrixA, rowA, colA);

    for (int i=0; i<rowA; i++)
      for (int j=0; j<colA; j++)
        fscanf(file, "%d", &matrixA[i][j]);

    if (inValue[1] == 1) // operaciones con matriz actual
    {
      actTask(matrixA, rowA, colA, inValue[0], inValue[2]);
    }
    else if (inValue[1] == 2) // operaciones con matriz siguiente
    {
      int rowB, colB;
      fscanf(file, "%i %i", &rowB, &colB);
      int **matrixB = initMatrix(matrixB, rowB, colB);
      for (int i=0; i<rowB; i++)
        for (int j=0; j<colB; j++)
          fscanf(file, "%d", &matrixB[i][j]);

      sigTask(matrixA, rowA, colA, matrixB, rowB, colB, inValue[0], inValue[3], inValue[2]);
    }
    else
    {
      printf("parametros ingresados de manera incorrecta. . .");
      exe = false;
    }

    freeMatrix(matrixA, rowA);
    for(int i=0; i<MAX_QUERY; i++)
    {
      free(input[i]);
    }
    free(inValue);
    free(input);

    if (inValue[4] == 0) exe = false;
  }
}