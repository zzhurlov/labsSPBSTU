#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

// Функция для проверки, является ли символ разделителем
int is_separator(char c) {
    return isspace(c) || ispunct(c);
}


int main() {
    FILE *file;
    char buff[512];
    char filename[100];
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int count = 0;
    int max_length;
    char alph[] = "QqWwEeRrTtYyUuIiOoPpLlKkJjHhGgFfDdSsAaZzXxCcVvBbNnMm";
    
    // Запрос имени файла
    printf("Введите имя файла: ");
    scanf("%s", filename);


    // Открытие файла
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");    
        return EXIT_FAILURE;
    }

    // Запрос максимальной длины слова
    printf("Введите максимальную длину слова: ");
    scanf("%d", &max_length);

    // Чтение слов из файла
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s,", word) != EOF) {
        int length = strlen(word);
        int flag = 1;
        int flag2 = 1;
        int flag3 = 1;

        for (int k = 0; k < strlen(word); k++)
        {
            if (is_separator(word[k]))
                word[k] = ' ';
        }

        for (int i = 0; i <= strlen(word); i++){
            if (isdigit(word[i]) != 0){
                flag2 = 0;
                break;
            }
        }

        for (int i = 0; i <= strlen(word); i++){
            if (isspace(word[i]) != 0){
                flag3 = 0;
                break;
            }
        }


        for (int i = 0; i < strlen(word); i++)
        {
            if (word[i] == ' ')
                length--;
        }

        for (int j = 0; j < strlen(alph); j++)
        {
            if (alph[j] == word[0])
            {
              flag = 0;
              break;
            }
        }
        if (flag == 1)
          length = length / 2;

        // Проверка длины слова
        if (length < max_length) {
            // Сохранение слова в массив
            if ((flag2 != 0) & (flag3 != 0)){
                strcpy(words[count], word);
                count++;
            }
            if (count >= MAX_WORDS) {
                break; // Ограничение на количество слов
            }
        }
    }

    // Закрытие файла
    fclose(file);

    // Вывод слов в столбик
    printf("Слова длиной меньше %d:\n", max_length);
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return EXIT_SUCCESS;
}