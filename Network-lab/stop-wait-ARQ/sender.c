#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, n, ch;
    char input[20], ackString[20];

    FILE *in, *ack;
    int a = 0;
    int one = 0;

    while (1)
    {
        printf("\n\t\t Stop and wait Protocol\n");
        printf("\n1. Send\n2. Check ACK\n3. EOT\n");
        printf("> ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            in = fopen("data.txt", "w");
            printf("Enter data (using even parity) > ");
            scanf("%s", input);
            n = strlen(input);
            one = 0;
            for (i = 0; i < n; i++)
            {
                fprintf(in, "%c", input[i]);
                if (input[i] == '1')
                {
                    one++;
                }
            }
            if (one % 2 == 1)
            {
                fprintf(in, "%d", 1);
            }
            else
            {
                fprintf(in, "%d", 0);
            }
            a++;
            fclose(in);
            printf("Data sent\n");
            break;
        case 2:
            ack = fopen("ack.txt", "r");
            fscanf(ack, "%s", ackString);
            fclose(ack);
            if (atoi(ackString) == a)
            {
                printf("acknowledged");
            }
            else
            {
                printf("not acknowledged");
                a--;
            }
            break;
        case 3:
            break;
        default:
            printf("Invalid input");
        }
    }
}