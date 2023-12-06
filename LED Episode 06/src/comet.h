//+--------------------------------------------------------------------------
//
// NightDriver - (c) 2020 Dave Plummer.  All Rights Reserved.
//
// File:                  
//
// Description:
//
//   
//
// History:     Sep-28-2020     davepl      Created
//
//---------------------------------------------------------------------------

#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

extern CRGB g_LEDs[];

void DrawComet(byte color)
{
    const byte fadeAmt = 64; //Smaller number = longer tail fade, 32 looks to be the golden number for the KITT Scanner
    const int cometSize = 10;
    const int deltaHue  = 4;

    static byte hue = color;
    static int iDirection = 1;
    static int iPos = 0;

    //hue += deltaHue; //We want the color to stay red and Knight Rider-y

    iPos += iDirection;
    if (iPos == (NUM_LEDS - cometSize) || iPos == 0)
        iDirection *= -1;
    
    for (int i = 0; i < cometSize; i++)
        g_LEDs[iPos + i].setHue(hue);
    
    // (Don't) Randomly fade the LEDs
    for (int j = 0; j < NUM_LEDS; j++)
         if (random(10) > 5)
            g_LEDs[j] = g_LEDs[j].fadeToBlackBy(fadeAmt);  

    delay(10); //Larger number = more pixelated effect, slower number = faster smoother effect
}