/****begin of scheduler ********************************************/
#define MAXTASKS 2
volatile unsigned short timers[MAXTASKS];
#define _SS static unsigned char _lc=0; switch(_lc){default: 
#define _EE ;}; _lc=0; return 65535;
#define WaitX(tickets)  do {_lc=(__LINE__%255)+1; return tickets ; case (__LINE__%255)+1: ;} while(0)
#define InitTasks() {unsigned char i; for(i=MAXTASKS;i>0 ;i--) timers[i-1]=0; }
#define RunTask(TaskName,TaskID) do { if (timers[TaskID]==0) timers[TaskID]=TaskName(); }  while(0)
#define CallSub(SubTaskName) do {unsigned short currdt; _lc=(__LINE__%255)+1; return 0; case (__LINE__%255)+1:  currdt=SubTaskName(); if(currdt!=65535) return currdt;} while(0) 
#define UpdateTimers() {unsigned char i; for(i=MAXTASKS;i>0 ;i--){if((timers[i-1]!=0)&&(timers[i-1]!=65535)) timers[i-1]--;}}
/*--end of scheduler-------------------------------------------------*/

unsigned short task1(){
_SS
  pinMode(BUILTIN_LED, OUTPUT);
  while(1){
      digitalWrite(BUILTIN_LED,HIGH);
      WaitX(50);   
      digitalWrite(BUILTIN_LED,LOW);
      WaitX(50);
  }
_EE
}

unsigned short  task2(){
_SS
  pinMode(14, OUTPUT);
  while(1){
      digitalWrite(13,HIGH);
      WaitX(100);   
      digitalWrite(13,LOW);
      WaitX(100);
  }
_EE
}


void setup() {
  // put your setup code here, to run once:
   InitTasks();
}

void loop() {
  // put your main code here, to run repeatedly:
    delay(10);
    UpdateTimers();
    RunTask(task1,0);                   
    RunTask(task2,1);                   
}