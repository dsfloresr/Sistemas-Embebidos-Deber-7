
/*
 * UNIVERSIDAD TECNICA DEL NORTE
 * FACULTAD DE INGENIERIA EN CIENCIAS APLICADAS
 * SISTEMAS EMBEBIDOS
 * STEVEN FLORES
 * 5to Nivel; 
 * Deber 6: Juego con motor
 */
 #include <EEPROM.h>
 int on=0;    //int 0
 int cont=0;    //int 1
 int cad;     //Inicializar variable
 int aux;     //varoable auxiliar
int pass = 4563;    //Contraseña
 String dato;       //Inicio variable auxiliar tipo string
void setup() {
cad=EEPROM.read(0);           //Lee la EEPROM
EEPROM.update(0,4563);        //Actualiza EEPROM
Serial.begin(9600);           //Inicializa comunicacion serial
attachInterrupt(0,activacion,LOW);      //Evento de activación
attachInterrupt(1,contador,LOW);        //Evento de contador
}
void loop() {
    if(on==2){                    //Condicion activación
      if(cont==1){              //Condicion activacion
        if(Serial.available()>0){              //Lectura de datos por cx
          dato=Serial.readString();                       //Obtencion dato cx
          cad=dato.toInt();              //transformar a int
          EEPROM.update(0,cad);              //actualizar
          Serial.println("Contrasenia Guardada");              //Mensaje de confirmacion
        }
      }
      if(cont==0){              //condicion activacion
        if(Serial.available()>0){              //Lectura datos cx
          dato=Serial.readString();              //Obtencion dato cx
          aux=dato.toInt();              //Transformacion dato a int
          if(cad==aux){              //Comparacion contraseña
            Serial.println("Contrasenia Correcta");               //Mensaje confirmacion
          }else{
            Serial.println("Contrasenia Incorrecta");              //Mensaje confirmacion
          }
        }
      }
    }
}
void activacion(){                    //Se activa Interrupción 1 mediante botón
  switch(on){                         //Número de veces de activación
    case 0: 
    Serial.println("INICIO DEL SISTEMA");     //Mensajes
    Serial.println("Ingrese la accion a realizar");              //Mensaje a usuario
    on++;     //Aumento Variable
    break;
    case 1:
      switch(cont){
        case 1:
          Serial.println("Ingrese nueva contrasenia");              //Mensaje a usuario
        break;
        case 0:
          Serial.println("Ingrese contrasenia para verificar");              //Mensaje a usuario
        break;
      }
    on++;               //Aumento variable
    break;
    case 2:
    Serial.println("Presione para volver al Menu Principal");              //Mensaje a usuario
    cont=0;               //Reinicio
    on=0;               //Reincio variable
    break;
  }
}
void contador(){        //Interrupción dos mediante botón
  if(on==1){            //Condición de activación a partir de activación 1
    switch(cont){
      case 0:
        Serial.println("Actualizar contrasenia");              //Mensaje a usuario
        cont=1;               //Seleccion Opcion
      break;
       case 1:
       Serial.println("Verificar contrasenia");              //Mensaje a usuario
        cont=0;               //Seleccion Opcion
       break;
    }
  }
}
