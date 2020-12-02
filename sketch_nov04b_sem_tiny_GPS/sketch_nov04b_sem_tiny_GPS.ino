//#define GPS_RX 0
//#define GPS_TX 3
#define GPS_Serial_Baud 9600
//#include <SoftwareSerial.h>
//#include <TinyGPS.h>
int estado_btn; //Variavel para ler o status do pushbutton
int cont = 1;
const int Botao = 3; //botao no pino 1
 
void setup() {
  Serial.begin(GPS_Serial_Baud);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Botao, INPUT); //Pino com botão será entrada
  //gpsSerial.begin(GPS_Serial_Baud);
  //pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop() {   
    //bool newData = false;
    //unsigned long chars;
    // For one second we parse GPS data and report some key values
    //for (unsigned long start = millis(); millis() - start < 1000;) {
      /*while (gpsSerial.available()) {
        char c = gpsSerial.read();
        // Serial.write(c); //apague o comentario para mostrar os dados crus
        if (gps.encode(c)) // Atribui true para newData caso novos dados sejam recebidos
          newData = true;
      }*/
      /*while (Serial.available()) {
        char c = Serial.read();
        if (gps.encode(c)) // Atribui true para newData caso novos dados sejam recebidos
          newData = true;
      }*/
    //}
    //if (Serial.available()) {
      estado_btn = digitalRead(Botao); //le o estado do botão - HIGH OU LOW
      if (estado_btn == HIGH){
        cont++;
      }
      if (cont % 2 == 0){ //Se botão estiver pressionado (HIGH)
          digitalWrite(LED_BUILTIN, HIGH); // acende o led do pino 2.
          if (Serial.available()) {
            char c = Serial.read();
            Serial.print(c);
          }
          /*digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
          delay(1000);                       // wait for a second
          digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
          delay(1000);*/
          /*float flat, flon;
          unsigned long age;
          gps.f_get_position(&flat, &flon, &age);
          Serial.print("LAT=");
          Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
          Serial.print(" LON=");
          Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
          Serial.print(" SAT=");
          Serial.print(gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites());
          Serial.print(" PREC=");
          Serial.print(gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop());
          Serial.println();
    
          //Dia e Hora
          int ano;
          long latitude, longitude;
          unsigned long idadeInfo;
          byte mes, dia, hora, minuto, segundo, centesimo;
          gps.crack_datetime(&ano, &mes, &dia, &hora, &minuto, &segundo, &centesimo, &idadeInfo);

          Serial.print("Data (GMT): ");
          Serial.print(dia);
          Serial.print("/");
          Serial.print(mes);
          Serial.print("/");
          Serial.println(ano);

          Serial.print("Horario (GMT): ");
          Serial.print(hora);
          Serial.print(":");
          Serial.print(minuto);
          Serial.print(":");
          Serial.print(segundo);
          Serial.print(":");
          Serial.println(centesimo);
          Serial.println();
          Serial.println();*/
    } else { //se não estiver pressionado (LOW)
          digitalWrite(LED_BUILTIN, LOW); //deixa o led do pino 2 apagado
    }
  //}
}
