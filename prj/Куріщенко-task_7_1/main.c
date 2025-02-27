#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

#ifdef _WIN32
    #include <io.h>
    #include <fcntl.h>
#endif

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

#ifdef _WIN32
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
#endif

    wprintf(L"Програма для аналізу речення: підрахунок символів 'Ц'/'ц' або цифр.\n");
    wprintf(L"Розробник: Куріщенко Павло\n");
    wprintf(L"Версія: 1.0\n");
    wprintf(L"Мова інтерфейсу: українська\n\n");

    wprintf(L"Введіть речення, що закінчується '!' або '?':\n");

    wchar_t sentence[256];
    fgetws(sentence, 256, stdin);

    int length = wcslen(sentence);

    if (length > 0 && sentence[length - 1] == L'\n') {
        sentence[length - 1] = L'\0';
        length--;
    }

    if (length == 0 || (sentence[length - 1] != L'!' && sentence[length - 1] != L'?')) {
        wprintf(L"Речення повинно закінчуватися '!' або '?'.\n");
        return 1;
    }

    int countTS = 0, countDigits = 0;

    for (int i = 0; i < length; i++) {
        if (sentence[i] == L'Ц' || sentence[i] == L'ц') {
            countTS++;
        } else if (iswdigit(sentence[i])) {
            countDigits++;
        }
    }

    if (countTS > 0) {
        wprintf(L"Кількість символів 'Ц' (враховуючи 'ц'): %d\n", countTS);
    } else {
        wprintf(L"Кількість цифр у реченні: %d\n", countDigits);
    }

    return 0;
}






