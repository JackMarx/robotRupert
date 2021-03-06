// int pwmb = A5;
// int dirb = A3;
// int brakeb = D5;
// int senb = A1;

//                     chn a       chn b
// Direction          D12/A4      D13/A3
// PWM                  D3/D0     D11/A5
// Brake              D9/D6     D8/D5
// Current Sensing      A0/A0     A1/A1

// pinMode(pwmb, OUTPUT);
// pinMode(dirb, OUTPUT);
// pinMode(brakeb, OUTPUT);
// pinMode(senb, INPUT);



/* A Spark function to parse the commands */
void robotControl(String command);
int robotAction(String command);

/* Globals -------------------------------------------------------------------*/
int leftMotorEnable   = A5;
int rightMotorEnable  = D0;
int leftMotorDir    = A3;
int rightMotorDir   = A4;


/* This function is called once at start up ----------------------------------*/
void setup()
{
  //Register Spark function
  Spark.function("rccar", robotControl);

  pinMode(leftMotorDir, OUTPUT);
  pinMode(leftMotorEnable, OUTPUT);
  pinMode(rightMotorDir, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT);

  pinMode(D7,OUTPUT);
}

/* This function loops forever --------------------------------------------*/
void loop()
{
  // Nothing to do here
}

/*******************************************************************************
 * Function Name  : robotControl
 * Description    : Parses the incoming API commands and sets the motor control
                    pins accordingly
 * Input          : RC Car commands
                    e.g.: rc,FORWARD
                          rc,BACK
 * Output         : Motor signals
 * Return         : 1 on success and -1 on fail
 *******************************************************************************/
void robotControl(String command)
{
  for(char& c : command) {
    robotAction(c);
  }
  
}


int robotAction(char command)
{
  if(command == 'S')
  {
    digitalWrite(leftMotorEnable,LOW);
    digitalWrite(rightMotorEnable,LOW);

    digitalWrite(leftMotorDir,LOW);
    digitalWrite(rightMotorDir,LOW);

    return 1;
  }

  if(command == 'B')
  {
    digitalWrite(leftMotorDir,LOW);
    digitalWrite(rightMotorDir,LOW);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    delay(1000);
  }

  if(command == 'F')
  {
    digitalWrite(leftMotorDir,HIGH);
    digitalWrite(rightMotorDir,HIGH);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    delay(1000);
  }

  if(command == 'R')
  {
    digitalWrite(leftMotorDir,HIGH);
    digitalWrite(rightMotorDir,LOW);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    delay(1000);
  }

  if(command == 'L')
  {
    digitalWrite(leftMotorDir,LOW);
    digitalWrite(rightMotorDir,HIGH);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    delay(1000);
  }

  // If none of the commands were executed, return false
  return -1;
}

