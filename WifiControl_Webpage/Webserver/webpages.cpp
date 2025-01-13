#include "webpages.h"


String SendHTML(uint8_t led0stat,uint8_t led1stat,uint8_t led2stat,uint8_t led3stat,uint8_t led4stat,uint8_t opt1stat,uint8_t opt2stat,uint8_t opt3stat,uint8_t opt4stat){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<meta http-equiv=\"refresh\" content=\"2\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 50px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 15px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-info {background-color: #87e3f1;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +=".rectangle { width: 100px;height:50px;background-color: #00FF00;color: #FFFFFF ;display: flex; justify-content: center; align-items: center; font-size: 15px; border: 2px solid #040404;}\n";
  ptr +=".rectangle-on { background-color: #00FF00;}\n";
  ptr +=".rectangle-off {  background-color: #adb0a6; }\n";
  ptr +=".placeside {display:flex;}\n";
  ptr +="p {font-size: 15px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>LED CONTROL</h1>\n";
  ptr +="<h3>Designed by Subhanjit</h3>\n";

  //Inputs
  ptr +="<h4> Optocoupler Inputs </h4>\n";
  ptr +="<div class = \"placeside\">\n";
  if(opt1stat)
  {ptr +="<div class=\"rectangle rectangle-on\">OPT1 ON</div>\n";}
  else
  {ptr +="<div class=\"rectangle rectangle-off\">OPT1 OFF</div>\n";}

  if(opt2stat)
    {ptr +="<div class=\"rectangle rectangle-on\">OPT2 ON</div>\n";}
  else
  {ptr +="<div class=\"rectangle rectangle-off\">OPT2 OFF</div>\n";}

  if(opt3stat)
  {ptr +="<div class=\"rectangle rectangle-on\">OPT3 ON</div>\n";}
  else
  {ptr +="<div class=\"rectangle rectangle-off\">OPT3 OFF</div>\n";}

  if(opt4stat)
  {ptr +="<div class=\"rectangle rectangle-on\">OPT4 ON</div>\n";}
  else
  {ptr +="<div class=\"rectangle rectangle-off\">OPT4 OFF</div>\n";}

  ptr +="</div>\n";

  //Buttons
  ptr +="<h4> Buttons Controls </h4>\n";
  ptr +="<div class = \"placeside\">\n";
  if(led0stat)
  {ptr +="<p>LED0:</p><a class=\"button button-on\" href=\"/led0off\">ON</a>\n";}
  else
  {ptr +="<p>LED0:</p><a class=\"button button-off\" href=\"/led0on\">OFF</a>\n";}

  if(led1stat)
  {ptr +="<p>LED1:</p><a class=\"button button-on\" href=\"/led1off\">ON</a>\n";}
  else
  {ptr +="<p>LED1:</p><a class=\"button button-off\" href=\"/led1on\">OFF</a>\n";}
  ptr +="</div>\n";
  ptr +="<div class = \"placeside\">\n";
  if(led2stat)
  {ptr +="<p>LED2:</p><a class=\"button button-on\" href=\"/led2off\">ON</a>\n";}
  else
  {ptr +="<p>LED2:</p><a class=\"button button-off\" href=\"/led2on\">OFF</a>\n";}

   if(led3stat)
  {ptr +="<p>LED3:</p><a class=\"button button-on\" href=\"/led3off\">ON</a>\n";}
  else
  {ptr +="<p>LED3:</p><a class=\"button button-off\" href=\"/led3on\">OFF</a>\n";}
  ptr +="</div>\n";
 
  if(led4stat)
  {ptr +="<p>LED4:<a class=\"button button-off\" href=\"/led4off\">OFF</a></p>\n";}
  else
  {ptr +="<p>LED4:</p><a class=\"button button-on\" href=\"/led4on\">ON</a>\n";}

  ptr +="<a class=\"button button-info\" href=\"/help\">Help</a>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}

String SendHTML2(){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<meta http-equiv=\"refresh\" content=\"2\">\n";
  ptr +="<title>Operation Details</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 50px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 15px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #1abc9c;}\n";
  ptr +=".button-on:active {background-color: #16a085;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +=".rectangle { width: 100px;height:50px;background-color: #00FF00;color: #FFFFFF ;display: flex; justify-content: center; align-items: center; font-size: 15px; border: 2px solid #040404;}\n";
  ptr +=".rectangle-on { background-color: #00FF00;}\n";
  ptr +=".rectangle-off {  background-color: #adb0a6; }\n";
  ptr +=".placeside {display:flex;}\n";
  ptr +="p {font-size: 15px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>Control Details</h1>\n";
  ptr +="<h3>Buttons</h3>\n";
  
  ptr +="<p>If Button Shows OFF : It means that LED is Off</p>\n";
  ptr +="<p>If Button Shows ON : It means that LED is ON</p>\n";

  ptr +="<h3>Connections</h3>\n";
  ptr +="<p>Check the Board . D0 to D4 are Outputs. Means controlled by Buttons. Connect LED to those pins.</p>\n";
  ptr +="<p>Check the Board . D5 to D8 are Inputs.Connect Optocoupler inputs.</p>\n";
  ptr +="<a class=\"button button-on\" href=\"/\">Back</a>\n";
  
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
