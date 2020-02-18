#pragma config(Sensor, port5,  colorDetector,  sensorVexIQ_ColorHue)
#pragma config(Motor,  motor7,          leftFrontWheel, tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor8,          rightFrontWheel, tmotorVexIQ, openLoop, reversed, encoder)
#pragma config(Motor,  motor9,          leftRearWheel, tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor10,         rightRearWheel, tmotorVexIQ, openLoop, reversed, encoder)
#pragma config(Sensor, port11,  touchLED,      sensorVexIQ_LED)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(true) //Do this forever
	{
		/*------------------------------------------------------------------------------------------------
		A basic loop to detect a range of hue values. The color sensor returns hue as a 0-255 value.
		This program forces all colors to fit within the following ranges and prints hue value on LCD screen:

		Red:   0 to 50 OR 220 to 255
		Green: 51 to 130
		Blue   131 to 219
		------------------------------------------------------------------------------------------------*/

		int currentHueValue = getColorValue(colorDetector);

		if( (currentHueValue >=0 && currentHueValue < 50) || (currentHueValue > 219 && currentHueValue <= 255))//RED
		{
			//If this detects Red Color, make a power sound
			displayTextLine(1, "The hue value now is %d",currentHueValue);  displayTextLine(2, "I see RED!"); playSound(soundPowerOff2);

			//Set the LED color red and keep it blinking for 2 seconds ON, half-sec OFF
			setTouchLEDHue(touchLED, currentHueValue);	setTouchLEDBlinkTime(touchLED, 40, 10);

			//Bring all motors speed to 0
			setMotorSpeed(leftFrontWheel,0); setMotorSpeed(rightFrontWheel, 0); setMotorSpeed(leftRearWheel, 0);	setMotorSpeed(rightRearWheel,0);

		}
		else if((currentHueValue > 50) && (currentHueValue <= 130))//GREEN
		{
			displayTextLine(1, "The hue value now is %d",currentHueValue); displayTextLine(2, "I see GREEN!"); playSound(soundCarAlarm2);

			setTouchLEDHue(touchLED, currentHueValue); setTouchLEDBlinkTime(touchLED, 40, 10);

			//First bring the motor speed to 0 then go foward at 40% power
			setMotorSpeed(leftFrontWheel,40); setMotorSpeed(rightFrontWheel, 40); setMotorSpeed(leftRearWheel, 40);	setMotorSpeed(rightRearWheel,40);

		}
		else if((currentHueValue > 131) && (currentHueValue <= 219))//BLUE
		{
			displayTextLine(1, "The hue value now is %d",currentHueValue); displayTextLine(2, "I see BLUE!"); playSound(soundCarAlarm4);

			setTouchLEDHue(touchLED, currentHueValue);	setTouchLEDBlinkTime(touchLED, 40, 10);

			//First bring the motor speed to 0 then go reverse at 40% power
			setMotorSpeed(leftFrontWheel,-40); setMotorSpeed(rightFrontWheel, -40); setMotorSpeed(leftRearWheel, -40);	setMotorSpeed(rightRearWheel, -40);

		}

		sleep(25); //Small delay to allow color sensor to detect any changes in color
	}
}
