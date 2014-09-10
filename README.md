#2014 TeleOp & Autonomous code for FTC Cascade Effect Challenge
##### [View repository on github](https://github.com/3983NHRobotics/2014-FTC)
<!--- make this h1 thing a link to the github repo - it will serve as the link to here from the highlandsrobo site --->

<hr id="teleop">
<!--- I needed the id --->

##Tele0p

###Test:
```
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

<hr id="autonomous">

##Autonomous

> Autonomous wheeeeee
