 if (myTime % 1000 == 0  && myTime != 0) {
    comida[0] = 'R';
    comida[1] = 'E';
    comida[2] = 'A';
    comida[3] = 'D';
    comida[4] = 'Y';
    for (int i = 5 ; i < 10 ; i ++) { // limpeza do array
    comida[i] = '\0';
   }
    Serial.write(comida,10);
 }