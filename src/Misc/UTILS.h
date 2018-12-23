#ifndef UTILS_H
#define UTILS_H

float heatIndexCels(float, float);
char *heatIndexCelsAsString(float);

float celsTOfar(float);
float farTOcels(float);

int Base64encode_len(int);
int Base64_encode(char *, const char *, int);

#endif