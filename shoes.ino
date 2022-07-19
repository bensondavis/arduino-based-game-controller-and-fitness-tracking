int S1 = 0,S2 = 0,S3 = 0,S4 = 0,leg=0,sum1,sum2,gar=1;
int state1=0,state2=0;

unsigned long t,x=0,j;
 
uint8_t buf[8]={0};

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);

}

void loop() {

  t=millis();
  S1 = analogRead(A0);
  S2 = analogRead(A1);
  S3 = analogRead(A2);
  S4 = analogRead(A3);

  sum1=S1+S2;
  sum2=S3+S4;

  if(sum1<10 and sum2>40 and (t-x)>1500 and abs(sum1-sum2)>50 and leg!=1)
  {
    leg=1;
    x=t;
    
  }
  if(sum1>40 and sum2<10 and (t-x)>1500 and abs(sum1-sum2)>50 and leg!=2)
  {
    leg=2;
    x=t;
    
  }

  if(sum1<10 and sum2>40 and (t-x)<1500 and leg==2 and abs(sum1-sum2)>40)
  {
    leg=1;
    gar=1;
    state1=1;
    //x=t; 
    if((t-x)<300)
    {
      //Serial.println("running");
      buf[2] = 26;   // W keycode
      Serial.write(buf, 8);
      buf[3] =225 ;
      Serial.write(buf, 8);
    }
    else
    {
      
      //Serial.println("walking");
      buf[2] = 26;   // W keycode
      buf[3] = 0 ;
      Serial.write(buf, 8);
    }
    x=t;
  }

  if(sum1>40 and sum2<10 and (t-x)<1500 and leg==1 and abs(sum1-sum2)>40)
  {
    leg=2;
    gar=1; 
    state1=1;
    if((t-x)<300)
    {
      //Serial.println("running");
      buf[2] = 26;   // W keycode
      Serial.write(buf, 8);
      buf[3] =225 ;
      Serial.write(buf, 8);
    }
    else
    {
      //Serial.println("walking");
      buf[2] = 26;   // W keycode
      buf[3] = 0 ;
      Serial.write(buf, 8);
    }
    x=t;
  }

  if(t-x>600 and state1==1)
  {
    state1=0;
    releaseKey();
  }
 

  if(sum1+sum2<10 and gar==1)
  {
    gar=0;
    j=t;
  }
  if(t-j>250 and gar==0 and (sum1+sum2)<10)
  {
    gar=2;
    buf[2] = 44; 
    buf[3] =0;
    Serial.write(buf, 8);
    delay(600);
    releaseKey();
  }

  if(sum1+sum2>100)
  {
    gar=1; 
  }


delay(10);

}

void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Send Release key  
}
