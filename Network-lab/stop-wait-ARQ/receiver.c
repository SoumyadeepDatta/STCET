#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, n, one = 0, a = 0;
    char output[20];
    FILE *out, *ack;
    out = fopen("data.txt", "r");
    fscanf(out, "%s", output);
    n = strlen(output);
    for (i = 0; i < n; i++)
    {
        if (output[i] == '1')
        {
            one++;
        }
    }
    if (one % 2 == 0)
    {
        printf("Received data has even parity \n");
        printf("Data accepted");
        a++;
        ack = fopen("ack.txt", "w");
        fprintf(ack, "%d", a);
    }
    else
    {
        printf("Received data has odd parity \n");
        printf("Data rejected");
        fprintf(ack, "%d", a);
    }
    printf("\nReceived data: ");
    for (i = 0; i < n - 1; i++)
    {
        printf("%c", output[i]);
    }

    fclose(out);
}