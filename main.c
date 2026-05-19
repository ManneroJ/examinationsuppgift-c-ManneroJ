#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char namn[5][20];
    int betyg[5][13];
    int average[5];
    int totalAverage = 0;
    int topScore = 0;
    char topStudent[20];

    //Tar input av användaren. För varje namn tas 13 heltal

    for (int i = 0; i < 5; i++) {

        scanf("%19s", namn[i]);

        namn[i][0] = toupper(namn[i][0]);

        for (int j = 1; namn[i][j] != '\0'; j++) {

            namn[i][j] = tolower(namn[i][j]);

        }
        
        int sum = 0;

        for (int k = 0; k < 13; k++) {

            scanf("%d", &betyg[i][k]);
            sum += betyg[i][k];

        }
        
        average[i] = sum / 13;
    }

    //Börja med att sätta första elementet som störst.

    topScore = average[0];
    strcpy(topStudent, namn[0]);

    //Hittar personen med högst medelpoäng genom att jämföra alla värden

    for (int i = 1; i < 5; i++) {
        
        if (topScore < average[i]) {
            topScore = average[i];
            strcpy(topStudent, namn[i]);
        }
        
    }

    //Skriver ut topStudent

    printf("%s\n", topStudent);

    //Summerar alla poäng och räknar sedan ut det totala medelvärdet

    for (int i = 0; i < 5; i++) {

        totalAverage += average[i];

    }

    totalAverage = totalAverage / 5;

    //Hittar studenter som ligger under medelvärdet och skriver ut
    
    for (int i = 0; i < 5; i++) {

        if (average[i] < totalAverage) {

            printf("%s\n", namn[i]);
            
        }

    }


}