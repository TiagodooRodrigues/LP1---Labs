# include <stdio.h>
int main (void)
{
  int decimal;
  unsigned int hexadecimal, octal; 
  int decimalnegativo, hexadecimalnegativo ,octalnegativo;
  printf("Wellcome to number informer v1\n");
  printf("Please insert Number 1 in Decimal:\n");
  scanf("%d", &decimal);
  printf("Please insert Number 2 in Hexadecimal:\n");
  scanf("%x", &hexadecimal);
  printf("Please insert Number 3 in Octal:\n");
  scanf("%o",&octal);
  decimalnegativo = decimal * -1;
  hexadecimalnegativo = hexadecimal * -1;
  octalnegativo = octal * -1;
  printf("+-----+--------+------+--------+--------+------+--------+\n");
  printf("| Nr. | Dec    | Hex  | Oct    | -Dec   | -Hex | -Oct   |\n");
  printf("+-----+--------+------+--------+--------+------+--------+\n");
  printf("| 1   | %06hd | %04hX | %06ho | %06hd | %04hx | %06ho |\n",decimal,decimal,decimal,decimalnegativo,decimalnegativo,decimalnegativo);
  printf("| 2   | %06hd | %04hX | %06ho | %06hd | %04hx | %06ho |\n",hexadecimal,hexadecimal,hexadecimal,hexadecimalnegativo,hexadecimalnegativo,hexadecimalnegativo);
  printf("| 3   | %06hd | %04hX | %06ho | %06hd | %04hx | %06ho |\n",octal,octal,octal,octalnegativo,octalnegativo,octalnegativo);
  printf("+-----+--------+------+--------+--------+------+--------+\n");
 return 0;
}
