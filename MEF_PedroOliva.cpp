#define button 10
#define RETARDO 40
#define LED_UP 9
#define LED_DOWN 8
int cuenta=0;
const byte numero[16]={
  B01000001,
  B11110011,
  B10001001,
  B10100001,
  B00110011,
  B00100101,
  B00000101,
  B11110001,
  B00000001,
  B00100001,
  B00010001,
  B00000111,
  B10001111,
  B10000011,
  B00001101,
  B00011101};


void debounceFSM_init(void);
void debounceFSM_update(void);

void buttonPressed(void);
void buttonReleased(void);

typedef enum{
  BUTTON_UP,
  BUTTON_FALLING,
  BUTTON_DOWN,
  BUTTON_RAISING,
} debounceState_t;
debounceState_t estadoAC;

unsigned long tiempo;

void setup()
{
   DDRD = B11111110;
    pinMode(LED_DOWN, OUTPUT);
    pinMode(LED_UP, OUTPUT);
    pinMode(button, INPUT);
    //Serial.begin(9600);
    tiempo = millis();
    debounceFSM_init();
}
//Función que carga el estado inicial
void debounceFSM_init(){
  estadoAC = BUTTON_UP;
  buttonReleased();
}
void actualizarNumero(int valor){
  /*Función que define los leds a encenderse y actualiza los
  pines digitales al valor de output que corresponda*/
  PORTD=numero[valor];
}
/*Función que lee las entradas, transiciona los estados y
actualiza las salidas*/
void debounceFSM_update(){
  switch(estadoAC){
    case BUTTON_UP:
      buttonReleased();
      //Serial.println("EL BOTON ESTÁ UP");
      if(!digitalRead(button)){
        estadoAC = BUTTON_FALLING;
          tiempo = millis();
        }
        break;
    
    case BUTTON_FALLING:
      //Serial.println("EL BOTON ESTÁ FALLING");
      if(millis()-tiempo > RETARDO){
          if(!digitalRead(button)){
            estadoAC = BUTTON_DOWN;
      }else{
          estadoAC = BUTTON_UP;
        }
      }
      break;

  case BUTTON_DOWN:
      buttonPressed(); 
      //Serial.println("EL BOTON ESTÁ DOWN");     
      if(digitalRead(button)){
      estadoAC = BUTTON_RAISING;
        tiempo = millis();
      }
      break;

    case BUTTON_RAISING:
      //Serial.println("EL BOTON ESTÁ RISING");
      if(millis()-tiempo > RETARDO){
          if(digitalRead(button)){
      cuenta++;
            if(cuenta>=16)cuenta=0;
          estadoAC = BUTTON_UP;
            
      }else{
          estadoAC = BUTTON_DOWN;
        }
      }
      break;

    default:
      buttonReleased();
      break;
  }
}
//Funciones que controlan a los LED
void buttonPressed(){
  //Serial.println("el boton está apretado");
  digitalWrite(LED_UP, LOW);
  digitalWrite(LED_DOWN, HIGH);
}
void buttonReleased(){
    //Serial.println("el boton no está apretado");
    digitalWrite(LED_UP, HIGH);
    digitalWrite(LED_DOWN, LOW);
}

//Loop
void loop()
{
  debounceFSM_update();
    actualizarNumero(cuenta);
    delay(10);
  }
