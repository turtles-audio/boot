typedef struct {
    short BytesPerSec;
    char SecPerClus;
    short RsvdSecCnt;
    char NumFATs;
    short RootEntCnt;
    short TotSec16;
    char Media;
    short FATSz16;
    short SecPerTrk;
} OEMStack;