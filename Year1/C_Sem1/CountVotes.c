#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNTRIES 2000

struct CountryCount {
    char country[75];
    int count;
};

int main() {
    int n, countryCount = 0;
    char line[75], countries[MAX_COUNTRIES][75];
    int counts[MAX_COUNTRIES] = {0};

    // Read the number of lines
    scanf("%d", &n);
    getchar(); // Consume the newline character

    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), stdin);

        // Extract the country
        char *country = strtok(line, " ");

        // Check if the country already exists in the list
        int found = 0;
        for (int j = 0; j < countryCount; j++) {
            if (strcmp(countries[j], country) == 0) {
                counts[j]++;
                found = 1;
                break;
            }
        }

        // If not found, add the country to the list
        if (!found) {
            strcpy(countries[countryCount], country);
            counts[countryCount] = 1;
            countryCount++;
        }
    }

    // Sort countries and their counts alphabetically
    for (int i = 0; i < countryCount - 1; i++) {
        for (int j = i + 1; j < countryCount; j++) {
            if (strcmp(countries[i], countries[j]) > 0) {
                char tempCountry[75];
                int tempCount;

                // Swap countries
                strcpy(tempCountry, countries[i]);
                strcpy(countries[i], countries[j]);
                strcpy(countries[j], tempCountry);

                // Swap counts
                tempCount = counts[i];
                counts[i] = counts[j];
                counts[j] = tempCount;
            }
        }
    }

    // Print the results
    for (int i = 0; i < countryCount; i++) {
        printf("%s %d\n", countries[i], counts[i]);
    }

    return 0;
}
