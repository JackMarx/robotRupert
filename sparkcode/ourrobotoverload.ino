
// shield/spark         chn a       chn b
// Direction            D12/A4      D13/A3
// PWM                  D3/D0       D11/A5
// Brake                D9/D6       D8/D5
// Current Sensing      A0/A0       A1/A1



int robotControl(String command);
int robotAction(String command);


int leftMotorEnable   = A5;
int rightMotorEnable  = D0;
int leftMotorDir    = A3;
int rightMotorDir   = A4;



void setup()
{
  //Register Spark function
  Spark.function("robot", robotControl);

  pinMode(leftMotorDir, OUTPUT);
  pinMode(leftMotorEnable, OUTPUT);
  pinMode(rightMotorDir, OUTPUT);
  pinMode(rightMotorEnable, OUTPUT);

  pinMode(D7,OUTPUT);
}


void loop()
{

}


int robotControl(String command)
{
  for(int i = 0; i < command.length(); ++i)
  {
    int result = robotAction(command[i]);
    if(result == -1)
    {
        return -1;
    }
  }
  return 1;
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

    delay(2400); //1 foot
    return 1;
  }

  if(command == 'F')
  {
    digitalWrite(leftMotorDir,HIGH);
    digitalWrite(rightMotorDir,HIGH);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    delay(2400); // 1 foot
    return 1;
  }

  if(command == 'R')
  {
    digitalWrite(leftMotorDir,HIGH);
    digitalWrite(rightMotorDir,LOW);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    delay(833.33); // 90 Degrees, or angle times 13.8889
    return 1;
  }

  if(command == 'L')
  {
    digitalWrite(leftMotorDir,LOW);
    digitalWrite(rightMotorDir,HIGH);

    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    delay(833.33); // 90 Degrees
    return 1;
  }
  
    if(command == 'C') //CELEBRATE
  {
    digitalWrite(leftMotorEnable,HIGH);
    digitalWrite(rightMotorEnable,HIGH);

    digitalWrite(leftMotorDir,LOW);
    digitalWrite(rightMotorDir,HIGH);
    
    delay(833.33);

    digitalWrite(leftMotorDir,HIGH);
    digitalWrite(rightMotorDir,LOW);

    delay(833.33);
    
    digitalWrite(leftMotorDir,LOW);
    digitalWrite(rightMotorDir,HIGH);
    
    delay(833.33);

    digitalWrite(leftMotorDir,HIGH);
    digitalWrite(rightMotorDir,LOW);

    delay(4166.65);
    
    
    return 1;
  }

  // If none of the commands were executed, return false
  return -1;
}
