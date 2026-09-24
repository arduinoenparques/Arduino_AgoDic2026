
void lecturabitxbit(){
        valor=analogRead(lectura);// valor del ADC
        voltaje=valor*5/1023;
        voltajecompleto=valor*5/1023;
        a1=bitRead(voltaje,0);
        b1=bitRead(voltaje,1);
        c1=bitRead(voltaje,2);
        d1=bitRead(voltaje,3);
  }

  