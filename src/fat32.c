#include <stdint.h>

typedef struct {
    uint16_t BytesPerSec;
    uint8_t SecPerClus;
    uint16_t RsvdSecCnt;
    uint8_t NumFATs;
    uint16_t RootEntCnt;
    uint16_t TotSec16;
    uint8_t Media;
    uint16_t FATSz16;
    uint16_t SecPerTrk;
} OEMStack;