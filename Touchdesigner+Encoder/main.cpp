#include <Arduino.h>
#include <Encoder.h>

Encoder encoder(2, 3);
char serialBuffer[1024];

void setup()
{
    Serial.begin(115200);
    Serial.flush();

    encoder.write(2048);
}

void loop()
{
    if (unsigned numBytes = Serial.available())
    {
        Serial.readBytes(serialBuffer, numBytes);
        for (unsigned i = 0; i < numBytes; ++i)
        {
            if (serialBuffer[i] == 'i')
            {
                Serial.write('p');
                break;
            }
            else if (serialBuffer[i] == 'r')
            {
                uint16_t reading = encoder.read();
                Serial.write(reading >> 8);
                Serial.write(reading & 0xFF);
                break;
            }
        }
    }
}
