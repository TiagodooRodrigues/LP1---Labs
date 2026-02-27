  int main (int argc, char * argv[]) {
  int numero = 10;  
  int *pNum = &numero;
  printf("%d\n",*pNum);
  *pNum = 15; // alterar o valor do numero atraves de ponteiro
  printf("%d\n",*pNum);
  return 0;  
}