#include <string.h>
#include <stdio.h>
#include "Parser.h"
#include "Setings.h"
#include "Header.h"
#include "Frame.h"

int OutPut(char *name, char*data, int n)
{
    printf("%c%c%c%c\t", name[0], name[1], name[2], name[3]);
    printf("%d\t", n);
    if (name[0] == 'A' && name[1] == 'P' &&
            name[2] == 'I' && name[3] == 'C') {
        printf("Photo_)\n");
        return n + 10;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            printf("%c", data[i] > 127 ? 0 : data[i]);
        }
        printf("\n");
        return n + 10;
    }
}

void Parse(struct Setings *s, int argc, char * argv[])
{
    char * filepath;
    FILE* file;
    struct Header hdr;
    for (int i = 1; i < argc; i++)
    {
        if (strstr(argv[i], "--set=") == argv[i])
        {
            FILE * file1 = fopen("mp1.mp3", "wb");
            uint8_t t;
            fwrite(&hdr, sizeof(hdr), 1, file1);
            while(fread(&t, sizeof(t), 1, file) == 1)
            {
                fwrite(&t, sizeof(t), 1, file1);
            }
            char* tagName = argv[i] + 6;
            int bytesRead = 10;
            while (bytesRead < hdr._size - 10)
            {
                struct frame frm = readFrame(file);
                if (frm.tagId[0] + frm.tagId[1] + frm.tagId[2] + frm.tagId[3] == 0) {
                    return;
                }
                if (frm.tagId[0] != tagName[0] || frm.tagId[1] != tagName[1] || frm.tagId[2] != tagName[2] || frm.tagId[3] != tagName[3])
                {
                    fwrite(&frm, sizeof(frm), 1, file1);
                    bytesRead += frm.tagSize + 10;
                }
                else
                {
                    char* value = argv[i + 1] + 8;
                    printf("%s", value);
                    frm.tagSize = sizeof(value);

                    for (int j = 0; j < frm.tagSize; j++)
                    {
                        if(strlen(value) < j)
                            break;
                        frm.data[j] = value[j];
                    }

                    fwrite(&frm, sizeof(frm), 1, file1);


                    return;
                }
            }
        }
        else if (strstr(argv[i], "--show") == argv[i])
        {
            printf("ID\tVERSION\tflags\tsize\n");
            printf("%s\t", hdr._fileId);
            printf("%d.%d\t", hdr._majorVersion, hdr._minorVersion);
            printf("%d\t", hdr._flags);
            printf("%d\n", hdr._size);
            int bytesRead = 10;
            printf("Tag\tSize\tinformation\n");
            while (bytesRead < hdr._size - 10)
            {
                struct frame frm = readFrame(file);
                if (frm.tagId[0] + frm.tagId[1] + frm.tagId[2] + frm.tagId[3] == 0) {
                    return;
                }

                bytesRead += OutPut(frm.tagId, frm.data, frm.tagSize);

            }
        }
        else if (strstr(argv[i], "--get=") == argv[i])
        {
            char* tagName = argv[i] + 6;
            int bytesRead = 10;
            printf("Tag\tSize\tinformation\n");
            while (bytesRead < hdr._size - 10)
            {
                struct frame frm = readFrame(file);
                if (frm.tagId[0] + frm.tagId[1] + frm.tagId[2] + frm.tagId[3] == 0) {
                    return;
                }
                if (frm.tagId[0] != tagName[0] || frm.tagId[1] != tagName[1] || frm.tagId[2] != tagName[2] || frm.tagId[3] != tagName[3])
                {
                    bytesRead += frm.tagSize + 10;
                }
                else
                {
                    OutPut(frm.tagId, frm.data, frm.tagSize);
                    break;
                }
            }
        }
        else if (strstr(argv[i], "--filepath=") == argv[i])
        {
            filepath = argv[i] + 11;
            SetFilepath(s, filepath);
            file = fopen(filepath, "r+b");
            if (file == NULL) {
                printf("ERROR");
                return;
            }
            ReadHead(&hdr, file);
        }
    }

}