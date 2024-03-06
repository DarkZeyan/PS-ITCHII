int DHpin = 8; // input/output pin
int buzzer = 9;
byte dat[5];
byte read_data()
{
    byte i = 0;
    byte result = 0;
    for (i = 0; i < 8; i++)
    {
        while (digitalRead(DHpin) == LOW)
            ;                  // Esperar 30 microsegundos
        delayMicroseconds(30); // Se evalua la duracion del HIGH para determinar si el bit recibido es 0 o 1
        if (digitalRead(DHpin) == HIGH)
            result |= (1 << (8 - i)); // High en el alto, low en bajo
        while (digitalRead(DHpin) == HIGH)
            ; // Bit recibido "1" , esperando al siguiente bit de recepcion,
    }
    return result;
}
void start_test()
{
    digitalWrite(DHpin, LOW); // Se baja el bus para mandar la señal de inicio
    delay(30);                // El retraso es superior a 18 ms para que el DHT 11 pueda detectar la señal de inicio.
    digitalWrite(DHpin, HIGH);
    delayMicroseconds(40); // Esperar a que DHT11 responda
    pinMode(DHpin, INPUT);
    while (digitalRead(DHpin) == HIGH)
        ;
    delayMicroseconds(80); // El DHT11 respponde bajando el bus por 80 microsegundos

    if (digitalRead(DHpin) == LOW)
        delayMicroseconds(80);  // El DHT11 sube el bus despues de 80 microsegundos para empezar a enviar datos
    for (int i = 0; i < 5; i++) // Recibiendo informacion de temperatura y humedad, los bits de check no se consideran
        dat[i] = read_data();
    pinMode(DHpin, OUTPUT);
    digitalWrite(DHpin, HIGH); // Despues de completarse la liberacion del bus de datos, se espera al host para el inicio de la siguiente señal
}

void playWord(String word)
{
    for (int i = 0; i < word.length(); i++)
    {
        playLetter(word.charAt(i));
        delay(500);
    }
}
void playLetter(char letter)
{
    int frequency;
    switch (letter)
    {
     case '0':
      frequency = 523;
      break;
    case '1':
      frequency = 587;
      break;
    case '2':
      frequency = 659;
      break;
    case '3':
      frequency = 698;
      break;
    case '4':
      frequency = 783;
      break;
    case '5':
      frequency = 880;
      break;
    case '6':
      frequency = 988;
      break;
    case '7':
      frequency = 1047;
      break;
    case '8':
      frequency = 1175;
      break;
    case '9':
      frequency = 1319;
      break;
    default:
      frequency = 0;  // Si el caracter no está definido, no hace ningún sonido
      break;
    }

    if(frequency>0){
        tone(buzzer, frequency, 200);
        delay(20);
        noTone(buzzer);
    }
}

void setup()
{
    Serial.begin(9600);
    pinMode(DHpin, OUTPUT);
    pinMode(buzzer, OUTPUT);
}
void loop()
{
    start_test();
    Serial.print("Humedad = ");
    Serial.print(dat[0], DEC); // Se muestran los bits de los enteros de la humedad;
    Serial.print('.');
    Serial.print(dat[1], DEC); // Se muestran los bits de los decimales de la humedad;
    Serial.println('%');
    Serial.print("Temperatura = ");
    Serial.print(dat[2], DEC); // Se muestran los bits de los enteros de la temperatura;
    Serial.print('.');
    Serial.print(dat[3], DEC); // Se muestran los bits de los decimales de la temperatura;
    Serial.println('C');
    byte checksum = dat[0] + dat[1] + dat[2] + dat[3];
    if (dat[4] != checksum)
        Serial.println("-- Checksum Error!");
    else
        Serial.println("-- OK");
    if (dat[2] > -1)
    {
        playWord(String(dat[2]));
    }
    else
    {
        noTone(buzzer);
    }
    delay(1000);
}