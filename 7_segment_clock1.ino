// C++ code
//
int h=1, m=0, s=0, f12=0, f13=0, d=0;
void setup()
{
  for(int i=0;i<=11;i++) {
    pinMode(i, OUTPUT); }
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  for(int i=8;i<=11;i++) {
    digitalWrite(i,1);}
}

void loop()
{
  if(h>12) { 
    h=1;
    m=0;
    s=0;
  }
  if(m>59) {
    m=0;
    h++;
    s=0;
  }
  if(s>59) {
    s=0;
    m++;
  }
  
  if(digitalRead(12)==HIGH){
    f12=1;}
  if(digitalRead(12)==LOW && f12==1) {
    h++;
    f12=0;}
  if(digitalRead(13)==HIGH){
    f13=1;}
  if(digitalRead(13)==LOW && f13==1) {
    m++;
    f13=0;}
  
  num(h/10);
  digitalWrite(8,0);
  wait();
  digitalWrite(8,1);
  
  num(h%10);
  digitalWrite(9,0);
  wait();
  digitalWrite(9,1);
  
  num(m/10);
  digitalWrite(10,0);
  wait();
  digitalWrite(10,1);
  
  num(m%10);
  digitalWrite(11,0);
  wait();
  digitalWrite(11,1);
  
  if(s%2==1){digitalWrite(7,1);}
  else {digitalWrite(7,0);}
}

void wait() {
  int x=4;
  delay(x);
  d+=x;
  if(d==1000){ s++; d=0;}
}

void num(int x) {
  int A[10][7] ={
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}};
  for(int i=0;i<=6;i++) {
    digitalWrite(i,A[x][i]);
  }
}
