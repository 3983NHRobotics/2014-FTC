2014 TeleOp & Autonomous code for FTC Cascade Effect Challenge
======

I moved the autonomous into the same repo as the teleop for simplicity

###Test:
```c

task main() {
  int inputdata;
  HTPBsetupIO(HTPB, 0x3F);//setup IO connection to "HTPB" at 0x3F bin

  while(true) {
    inputdata = HTPBreadADC(HTPB, 0, 10);
    eraseDisplay();
    nxtDisplayTextLine(1, "%d", inputdata);

    if(inputdata < 512)
      HTPBwriteIO(HTPB, 0x00); //write value of 0 (off) to protoboard
    else
      HTPBwriteIO(HTPB, 0x01); //write value of 1 (on) to protoboard

    wait1Msec(50);
  }
}
```
