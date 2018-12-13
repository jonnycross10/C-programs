#include <stdio.h>
#include <string.h>
#include <libsocket/libinetsocket.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd = create_inet_stream_socket("api.wunderground.com", "80", LIBSOCKET_IPv4, 0);
    if (fd == -1)
    {
        printf("Can't connect\n");
        exit(1);
    }
    FILE *f = fdopen(fd, "rb+");
    if (!f)
    {
        printf("Can't convert fd to FILE\n");
    }
    fprintf(f, "GET /api/1655f919bbcd29ed/conditions/q/%s.json HTTP/1.0\n", argv[1]);
    fprintf(f, "Host: api.wunderground.com\n");
    fprintf(f, "\n");
    char observationtime[500];
    char locationline[500];
    char temp[500];
    char hum[500];
    char wind[500];
    char line[500];
    while (fgets(line, 500, f) != NULL)
    {
        if(strstr(line, "observation_time") != NULL)
        {
            strcpy(observationtime, line);
        }
        
        if(strstr(line, "full") != NULL)
        {
            strcpy(locationline, line);
        }
        
        if(strstr(line, "temp_f") != NULL)
        {
            strcpy(temp, line);
        }
        
        if(strstr(line, "relative_humidity") != NULL)
        {
            strcpy(hum, line);
        }
        
        if(strstr(line, "wind_string") != NULL)
        {
            strcpy(wind, line);
        }
    }
    
    //observation time
    int observationindex = strchr(observationtime, ':')- observationtime + 1;
    printf("Observation time: ");
    while (observationtime[observationindex] != '\n')
    {
        if (observationtime[observationindex] != '"' && observationtime[observationindex] != ',')
        {
            printf("%c",observationtime[observationindex]);
        }
        observationindex++;
    } printf("\n");
    
    //location
    int locationindex = strchr(locationline, ':') - locationline +2;
    printf("Location: ");
    while (locationline[locationindex] != '\n')
    {
        if (locationline[locationindex] != '"' && locationline[locationindex] != ',')
        {
            printf("%c", locationline[locationindex]);
        }
        locationindex++;
    } printf("\n");
    
    //temp_f
    int tempindex = strchr(temp, ':') - temp +1;
    printf("Temperature: ");
    while (temp[tempindex] != '\n')
    {
        printf("%c", temp[tempindex]);
        tempindex++;
    } printf(" F\n");
    
    //humidity
    int humindex = strchr(hum, ':') - hum + 2;
    printf("Humidity: ");
    while (hum[humindex] != '\n')
    {
        if (hum[humindex] != '"' && hum[humindex] != ',')
        {
            printf("%c", hum[humindex]);
        }
        humindex++;
    } printf("\n");
    
    //wind
    int windindex = strchr(wind, ':') - wind + 2;
    printf("Wind: ");
    while (wind[windindex] != '\n')
    {
        if (wind[windindex] != '"' && wind[windindex] != ',')
        {
            printf("%c", wind[windindex]);
        }
        windindex++;
    } printf("\n");
    
    fclose(f);
    destroy_inet_socket(fd);
}