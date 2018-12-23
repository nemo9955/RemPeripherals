#include "UTILS.h"

// dewPoint function NOAA
// reference (1) : http://wahiduddin.net/calc/density_algorithms.htm
// reference (2) :
// http://www.colorado.edu/geography/weather_station/Geog_site/about.htm
//
// float dewPoint(float celsius, float humidity)
// {
//     // (1) Saturation Vapor Pressure = ESGG(T)
//     float RATIO = 373.15 / (273.15 + celsius);
//     float RHS = -7.90298 * (RATIO - 1);
//     RHS += 5.02808 * log10(RATIO);
//     RHS += -1.3816e-7 * (pow(10, (11.344 * (1 - 1 / RATIO))) - 1);
//     RHS += 8.1328e-3 * (pow(10, (-3.49149 * (RATIO - 1))) - 1);
//     RHS += log10(1013.246);

//     // factor -3 is to adjust units - Vapor Pressure SVP * humidity
//     float VP = pow(10, RHS - 3) * humidity;

//     // (2) DEWPOINT = F(Vapor Pressure)
//     float T = log(VP / 0.61078); // temper var
//     return (241.88 * T) / (17.558 - T);
// }

float heatIndexCels(float tempCels, float humidity) {
    float temper = celsTOfar(tempCels);

    const float c1 = -42.379;
    const float c2 = 2.04901523;
    const float c3 = 10.14333127;
    const float c4 = -.22475541;
    const float c5 = -0.00683783;
    const float c6 = -0.05481717;
    const float c7 = 0.00122874;
    const float c8 = 0.00085282;
    const float c9 = -0.00000199;

    float heatIndex = c1 + (c2 * temper) + (c3 * humidity) +
                      (c4 * temper * humidity) + (c5 * (temper * temper)) +
                      (c6 * (humidity * humidity)) +
                      (c7 * (temper * temper) * humidity) +
                      (c8 * temper * (humidity * humidity)) +
                      (c9 * (temper * temper) * (humidity * humidity));

    return farTOcels(heatIndex);
}

char *heatIndexCelsAsString(float hiCels) {
    if (hiCels <= 27) return "PLEASANT";
    if (hiCels > 27 && hiCels <= 32) return "CAUTION";
    if (hiCels > 32 && hiCels < 41) return "WARNING";
    return "DANGER";
}

float celsTOfar(float c) { return c * 1.8 + 32; }

float farTOcels(float f) { return (f - 32) * 0.55555; }

// char *getMAC()
// {
//     sprintf(macAddr, "%08X", ESP.getChipId());
//     return macAddr;
// };

int Base64encode_len(int len) { return ((len + 2) / 3 * 4) + 1; }

// https://opensource.apple.com/source/QuickTimeStreamingServer/QuickTimeStreamingServer-452/CommonUtilitiesLib/base64.c
static const char basis_64[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int Base64_encode(char *encoded, const char *string, int len) {
    int i;
    char *p;

    p = encoded;
    for (i = 0; i < len - 2; i += 3) {
        *p++ = basis_64[(string[i] >> 2) & 0x3F];
        *p++ = basis_64[((string[i] & 0x3) << 4) |
                        ((int)(string[i + 1] & 0xF0) >> 4)];
        *p++ = basis_64[((string[i + 1] & 0xF) << 2) |
                        ((int)(string[i + 2] & 0xC0) >> 6)];
        *p++ = basis_64[string[i + 2] & 0x3F];
    }
    if (i < len) {
        *p++ = basis_64[(string[i] >> 2) & 0x3F];
        if (i == (len - 1)) {
            *p++ = basis_64[((string[i] & 0x3) << 4)];
            *p++ = '%';
            *p++ = '3';
            *p++ = 'D';
            // *p++ = '=';
        } else {
            *p++ = basis_64[((string[i] & 0x3) << 4) |
                            ((int)(string[i + 1] & 0xF0) >> 4)];
            *p++ = basis_64[((string[i + 1] & 0xF) << 2)];
        }
        // *p++ = '=';
        *p++ = '%';
        *p++ = '3';
        *p++ = 'D';
    }

    *p++ = '\0';
    return p - encoded;
}
