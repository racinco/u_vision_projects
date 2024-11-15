RS EQU P2.7                  
RW EQU P2.6                  
E  EQU P2.5                  
ORG 000H
MOV DPTR,#LUT
SETB P3.5
CLR P2.0
MOV TMOD,#00100001B
MOV TL1,#00D
ACALL DINT
ACALL TEXT1
MAIN: MOV R1,#8D
      SETB P3.5
      CLR P3.5
      ACALL DELAY1
      SETB P3.5
HERE:JB P3.5,HERE
HERE1:JNB P3.5,HERE1
HERE2:JB P3.5,HERE2
LOOP:JNB P3.5,LOOP
     RL A
     MOV R0,A
     SETB TR1
HERE4:JB P3.5,HERE4
      CLR TR1
      MOV A,TL1
      SUBB A,#50D
      MOV A,R0
      JB PSW.7, NEXT
      SETB ACC.0
      SJMP ESC
NEXT:CLR ACC.0
ESC: MOV TL1,#00D
     CLR PSW.7
     DJNZ R1,LOOP
     ACALL DINT
     ACALL TEXT1
     ACALL LINE2
     ACALL TEXT2
     ACALL HMDTY
     ACALL CHECK
     ACALL DELAY2
     LJMP MAIN

       
        
DELAY1: MOV TH0,#0B9H    
        MOV TL0,#0B0H    
        SETB TR0                  
HERE5: JNB TF0,HERE5             
       CLR TR0                      
       CLR TF0                    
       RET 

DELAY2:MOV R1,#112D
  BACK:ACALL DELAY1
       DJNZ R1,BACK
       RET
 
 CHECK:MOV A,R0
       MOV B,#65D
       SUBB A,B
       JB PSW.7,NEXT1
       ACALL TEXT3
       SETB P2.0
       SJMP ESC1
  NEXT1:ACALL TEXT4
        CLR P2.0
  ESC1:CLR PSW.7
       RET    
           
 CMD: MOV P0,A
    CLR RS
    CLR RW
    SETB E
    CLR E
    ACALL DELAY
    RET

DISPLAY:MOV P0,A
    SETB RS
    CLR RW
    SETB E
    CLR E
    ACALL DELAY
    RET
    
HMDTY:MOV A,R0
      MOV B,#10D
      DIV AB
      MOV R2,B
      MOV B,#10D
      DIV AB
      ACALL ASCII
      ACALL DISPLAY
      MOV A,B
      ACALL ASCII
      ACALL DISPLAY
      MOV A,R2
      ACALL ASCII
      ACALL DISPLAY
      MOV A,#"%"
      ACALL DISPLAY
      RET
      
      
TEXT1: MOV A,#"H"
       ACALL DISPLAY
       MOV A,#"y"
       ACALL DISPLAY
       MOV A,#"g"
       ACALL DISPLAY
       MOV A,#"r"
       ACALL DISPLAY
       MOV A,#"o"
       ACALL DISPLAY
       MOV A,#"m"
       ACALL DISPLAY
       MOV A,#"e"
       ACALL DISPLAY
       MOV A,#"t"
       ACALL DISPLAY
       MOV A,#"e"
       ACALL DISPLAY
       MOV A,#"r"
       ACALL DISPLAY
       RET      
       
TEXT2: MOV A,#"R"
       ACALL DISPLAY
       MOV A,#"H"
       ACALL DISPLAY
       MOV A,#" "
       ACALL DISPLAY
       MOV A,#"="
       ACALL DISPLAY
       MOV A,#" "
       ACALL DISPLAY
       RET 
 TEXT3: MOV A,#" "
       ACALL DISPLAY
       MOV A,#" "
       ACALL DISPLAY
       MOV A,#"O"
       ACALL DISPLAY
       MOV A,#"N"
       ACALL DISPLAY
       RET
 
 TEXT4:MOV A,#" "
       ACALL DISPLAY
       MOV A,#"O"
       ACALL DISPLAY
       MOV A,#"F"
       ACALL DISPLAY
       MOV A,#"F"
       ACALL DISPLAY
       RET
 
 DINT:MOV A,#0CH 
    ACALL CMD
    MOV A,#01H 
    ACALL CMD
    MOV A,#06H 
    ACALL CMD
    MOV A,#83H 
    ACALL CMD
    MOV A,#3CH 
    ACALL CMD
    RET
    
LINE2:MOV A,#0C0H 
      ACALL CMD
      RET
          
          
DELAY: CLR E
    CLR RS
    SETB RW
    MOV P0,#0FFH
    SETB E
    MOV A,P0
    JB ACC.7,DELAY
    CLR E
    CLR RW
    RET

ASCII: MOVC A,@A+DPTR
       RET
    
LUT: DB  48D
     DB  49D
     DB  50D
     DB  51D
     DB  52D
     DB  53D
     DB  54D
     DB  55D
     DB  56D
     DB  57D
    END
