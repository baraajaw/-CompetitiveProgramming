#include <bits/stdc++.h>
#define f(i, x, n) for (int i = x; i < (int)(n); ++i)
#define ll long long
using namespace std;
char matrix [34][84], mark;
int line, max_len;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void DFS(int i , int j){

  f(k , 0, 4){
      int nx = dx[k] + i;
      int ny = dy[k] + j;
      if ( nx < line && nx >= 0 && ny < max_len && ny >= 0 &&  matrix[nx][ny] != 'X' && matrix[nx][ny] != matrix[i][j]){
        matrix[nx][ny] = matrix[i][j];
        DFS(nx, ny);
      }
  }
}
int main() {
  while (gets(matrix[0])){
    line = 1;
    while ( gets(matrix[line]) && matrix[line][0] != '_'){
      int len = strlen(matrix[line]);
      max_len = max (max_len, len);
      line++;
    } 
    f(i, 0, line){
        int len = strlen(matrix[i]);
        f(j, 0, len)
          if (matrix[i][j] != ' ' && matrix[i][j] != 'X')
              DFS(i, j);
          
    }

   f(i, 0, line + 1)
      printf("%s\n", matrix[i] ); 
  }
  return 0;
  
  
}
