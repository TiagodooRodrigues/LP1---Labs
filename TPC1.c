#include <stdio.h>
#include <string.h>
int main (void) {
 char letter;
 char zodac[20];
 int day,month,year,currentday,currentmoth,currentyear;
 int age;
 scanf(" %c %d %d %d %d %d %d",&letter,&day,&month,&year,&currentday,&currentmoth,&currentyear);
 if ((year < 1900 || year > 2020) || (day < 1 || day > 31) || ( month < 1 || month > 12)) {
   puts("Data de nascimento invalida");
   return 0;
 }
 if ((currentmoth == 4 || month == 4) || (currentmoth == 6 || month == 6) || (currentmoth==9 || month==9) || (currentmoth==11 || month==11)) {
   if (day == 31 ) {
     puts("Data de nascimento invalida");
     return 0;
   }
   if (currentday == 31) {
    puts ("Data actual invalida");
    return 0;
   }
 }

 if (month == 2 || currentmoth == 2) {
   if (day > 29 ) {
     puts("Data de nascimento invalida");
     return 0;
   }
   if (currentday > 29) {
     puts("Data actual invalida");
     return 0;
   }
   if (day == 29 || currentday== 29) {
   if (((month % 4 != 0) && (month % 100 == 0 )) || (month % 400 != 0 )) {
     puts("Data de nascimento invalida");
     return 0;
   }
   if ((currentmoth % 4 != 0) || (month % 100 == 0) || (month % 400 != 0)) {
     puts("Data actual invalida");
     return 0;
   }
   }
} 
 if ((currentyear < 1900 || currentyear > 2020) || (currentday < 1 || currentday > 31) || ( currentmoth < 1 || currentmoth > 12)) { 
   puts("Data actual invalida");
   return 0;
 }
if ((year > currentyear) || (year == currentyear && month > currentmoth) || (year == currentyear && month==currentmoth && day > currentday)) {
  puts("Data actual inferior a data de nascimento");
  return 0;
}
if (currentmoth > month) {
  age = currentyear - year;
}
if (currentmoth < month) {
  age = currentyear - year - 1 ;
  if (age < 0) {
    age++;
  }
}
if (currentmoth == month) {
  if (currentday < day) {
    age = currentyear - year -1 ;
  }
}
if (letter == 'a' || letter == 't') {
 printf("%d anos \n",age);
}

 if((month == 12 && day >= 22) || (month == 1 && day <= 19)){
  strcpy(zodac,"Capricornio");
 }
 if((month == 1 && day >= 20) || (month == 2 && day <= 18)){
  strcpy(zodac,"Aquario");
 }
 if ((month==2 && day >= 19) || (month==3 && day <= 20)) {
  strcpy(zodac,"Peixes");
 }
 if ((month== 3 && day >= 21) || (month==4 && day <= 19)){
  strcpy(zodac,"Carneiro");
 }
 if ((month==4 && day >= 20) || (month==5 && day<=20)){
  strcpy(zodac,"Touro");
 }
if ((month==5 && day >= 21) || (month==6 && day<=20)){
  strcpy(zodac,"Gemeos");
 } 
 if ((month==6 && day >= 21) || (month==7 && day<=22)){
  strcpy(zodac,"Carangueijo");
 }
 if ((month==7 && day >= 23) || (month==8 && day<=22)){
  strcpy(zodac,"Leao");
 }
 if ((month==8 && day >= 23) || (month==9 && day<=22)){
  strcpy(zodac,"Virgem");
 }
 if ((month==9 && day >= 23) || (month==10 && day<=22)){
  strcpy(zodac,"Balanca");
 }
 if ((month==10 && day >= 23) || (month==11 && day<=21)){
  strcpy(zodac,"Escorpiao");
 }
 if ((month==11 && day >= 22) || (month==12 && day<=21)){
  strcpy(zodac,"Sagitario");
 }
if (letter == 'z'|| letter == 't') {
  puts(zodac);
}

if (letter == 'r' || letter == 't') {
if (age >= 16 && age < 66.5) {
 puts("Apto para trabalhar"); 
}
if (age >= 66.5) {
 puts("Elegivel para reforma"); 
}
if (age < 16) {
 puts("Nao tem idade para trabalhar");
}
}
return 0;
}