#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int source, destination;
    char buffer[100];
    int bytes;

    printf("====================================\n");
    printf("       WEEK 2 - SYSTEM CALLS\n");
    printf("====================================\n");

    printf("\nOpening source.txt...\n");

    source = open("source.txt", O_RDONLY);

    if (source < 0)
    {
        perror("Error opening source.txt");
        return 1;
    }

    printf("source.txt opened successfully.\n");

    printf("Opening destination.txt...\n");

    destination = open("destination.txt",
                       O_WRONLY | O_CREAT | O_TRUNC,
                       0644);

    if (destination < 0)
    {
        perror("Error opening destination.txt");
        close(source);
        return 1;
    }

    printf("destination.txt opened successfully.\n");

    printf("\nCopying file contents...\n");

    while ((bytes = read(source, buffer, sizeof(buffer))) > 0)
    {
        write(destination, buffer, bytes);
    }

    printf("File contents copied successfully.\n");

    close(source);
    close(destination);

    printf("Source file closed.\n");
    printf("Destination file closed.\n");

    printf("\n====================================\n");
    printf("       COPY COMPLETED SUCCESSFULLY\n");
    printf("====================================\n");

    return 0;
}
