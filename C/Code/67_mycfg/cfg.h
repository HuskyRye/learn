#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

    int trimSpace(char *inbuf, char *outbuf);
    int ReadCfgFile(char *file, char *key, char *value, int *len);
    int WriteCfgFile(char *file, char *key, char *value, int len);

#ifdef __cplusplus
}
#endif