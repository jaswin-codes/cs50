// Program that recovers photos that were "deleted"(forgotten)

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Opens file to read mode
    FILE *card = fopen(argv[1], "r");
    // Check if file can be opened
    if (card == NULL)
    {
        return 1;
    }
    // Buffer for data, unsigned/positive/non-negative integer that requires 1 byte
    uint8_t buffer[512];
    int jpeg_count = 0;
    // Storage of name of each recovered JPEG
    char filename[8];
    // Pointer file image and set to NULL
    FILE *image = NULL;

    // Read data till EOF
    while (fread(buffer, 1, 512, card) != 0)
    {
        // JPEG Header first 4 bytes
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            if (image != NULL)
            {
                // File is currently open
                fclose(image);
            }
            // Create new file name (000.jpg)
            sprintf(filename, "%03d.jpg", jpeg_count);
            // Open image file in write mode for JPEGs
            image = fopen(filename, "w");
            // Found jpeg so increment amount
            jpeg_count++;
            fwrite(buffer, 1, 512, image);
        }
        else if (image != NULL)
        {
            fwrite(buffer, 1, 512, image);
        }
    }
    // If file open, close file
    if (image != NULL)
    {
        fclose(image);
    }
    fclose(card);
    return 0;
}
