#include <iostream>
#include <string>
#include <fstream>
#include <limits>

// Структура для представления трубы
struct Tub {

    std::string name;
    double lenght;
    double diametr;
    bool repair;

    // Ввод данных о трубе с проверками
    void vvod() {
        setlocale(LC_ALL, "Russian");
        std::cout << "Введите название трубы: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Введите длину трубы: ";
        while (!(std::cin >> lenght) || lenght < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Десятичные дроби вводятся через точку, например: 0.1" << std::endl;
            }
            else {
                std::cout << "Перепроверьте значения. Длина не может быть отрицательной." << std::endl;
            }
            std::cout << "Введите длину трубы: ";
        }

        std::cout << "Введите диаметр трубы: ";
        while (!(std::cin >> diametr) || diametr < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Десятичные дроби вводятся через точку, например: 0.1" << std::endl;
            }
            else {
                std::cout << "Перепроверьте значения. Диаметр не может быть отрицательным." << std::endl;
            }
            std::cout << "Введите диаметр трубы: ";
        }

        std::cout << "Находится ли труба в ремонте? (1 - да, 0 - нет): ";
        std::cin >> repair;
    }

    // Вывод данных о трубе
    void vivod() const {
        setlocale(LC_ALL, "Russian");
        std::cout << "Название трубы: " << name << std::endl;
        std::cout << "Длина: " << lenght << " км" << std::endl;
        std::cout << "Диаметр: " << diametr << " м" << std::endl;
        std::cout << "В ремонте: " << (repair ? "Да" : "Нет") << std::endl;
    }

    // Редактирование признака "в ремонте"
    void change_status() {
        setlocale(LC_ALL, "Russian");
        std::cout << "Введите новый статус ремонта (1 - да, 0 - нет): ";
        std::cin >> repair;
    }
};

// Структура для представления компрессорной станции (КС)
struct Station {
    std::string name;
    int kolCeh;
    int actCeh;
    double effectivity;

    // Ввод данных о КС с проверками
    void vvod() {
        setlocale(LC_ALL, "Russian");
        std::cout << "Введите название станции: ";
        std::cin.ignore();
        std::getline(std::cin, name);

        std::cout << "Введите общее количество цехов: ";
        while (!(std::cin >> kolCeh) || kolCeh < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Целые значения вводятся без запятой." << std::endl;
            }
            else {
                std::cout << "Перепроверьте значения. Количество не может быть отрицательным." << std::endl;
            }
            std::cout << "Введите общее количество цехов: ";
        }

        std::cout << "Введите количество активных цехов: ";
        while (!(std::cin >> actCeh) || actCeh > kolCeh || actCeh < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Целые значения вводятся без запятой." << std::endl;
            }
            else {
                std::cout << "Активные цеха не могут превышать общее количество или быть меньше 0." << std::endl;
            }
            std::cout << "Введите количество активных цехов: ";
        }

        std::cout << "Введите эффективность станции: ";
        while (!(std::cin >> effectivity) || effectivity < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Десятичные дроби вводятся через точку, например: 0.1" << std::endl;
            }
            else {
                std::cout << "Перепроверьте значения. Эффективность не может быть отрицательной." << std::endl;
            }
            std::cout << "Введите эффективность станции: ";
        }
    }

    // Вывод данных о КС
    void vivod() const {
        setlocale(LC_ALL, "Russian");
        std::cout << "Название станции: " << name << std::endl;
        std::cout << "Общее количество цехов: " << kolCeh << std::endl;
        std::cout << "Активные цеха: " << actCeh << std::endl;
        std::cout << "Эффективность: " << effectivity << std::endl;
    }

    // Запуск цеха
    void puskCeh() {
        setlocale(LC_ALL, "Russian");
        if (actCeh < kolCeh) {
            actCeh++;
            std::cout << "Цех запущен. Активные цеха: " << actCeh << std::endl;
        }
        else {
            std::cout << "Все цеха уже активны." << std::endl;
        }
    }

    // Остановка цеха
    void stopCeh() {
        setlocale(LC_ALL, "Russian");
        if (actCeh > 0) {
            actCeh--;
            std::cout << "Цех остановлен. Активные цеха: " << actCeh << std::endl;
        }
        else {
            std::cout << "Нет активных цехов для остановки." << std::endl;
        }
    }
};

// Функции для сохранения и загрузки данных в файл
void savef(Tub tubs[], int count_tubs, Station station[], int count_stations) {
    setlocale(LC_ALL, "Russian");
    std::ofstream file("данные.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для сохранения!" << std::endl;
        return;
    }

    file << count_tubs << std::endl;
    for (int i = 0; i < count_tubs; i++) {
        file << tubs[i].name
            << std::endl << tubs[i].lenght
            << std::endl << tubs[i].diametr
            << std::endl << tubs[i].repair << std::endl;
    }

    file << count_stations << std::endl;
    for (int i = 0; i < count_stations; i++) {
        file << station[i].name
            << std::endl << station[i].kolCeh
            << std::endl << station[i].actCeh
            << std::endl << station[i].effectivity << std::endl;
    }

    file.close();
    std::cout << "Данные успешно сохранены." << std::endl;
}

void loadf(Tub tubs[], int& count_tubs, Station stations[], int& count_stations) {
    setlocale(LC_ALL, "Russian");
    std::ifstream file("данные.txt");
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для загрузки!" << std::endl;
        return;
    }

    file >> count_tubs;
    file.ignore();
    for (int i = 0; i < count_tubs; i++) {
        std::getline(file, tubs[i].name);
        file >> tubs[i].lenght >> tubs[i].diametr >> tubs[i].repair;
        file.ignore();
    }

    file >> count_stations;
    file.ignore();
    for (int i = 0; i < count_stations; i++) {
        std::getline(file, stations[i].name);
        file >> stations[i].kolCeh >> stations[i].actCeh >> stations[i].effectivity;
        file.ignore();
    }

    file.close();
    std::cout << "Данные успешно загружены." << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Tub tubs[100];
    Station station[100];
    int count_tubs = 0, count_stations = 0;
    int выбор;

    while (true) {
        std::cout << "1. Добавить трубу" << std::endl;
        std::cout << "2. Добавить КС" << std::endl;
        std::cout << "3. Просмотреть все объекты" << std::endl;
        std::cout << "4. Изменить трубу" << std::endl;
        std::cout << "5. Релактировать КС" << std::endl;
        std::cout << "6. Сохранить" << std::endl;
        std::cout << "7. Загрузить" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> выбор;

        if (выбор == 0) {
            break;
        }

        switch (выбор) {
        case 1: {
            tubs[count_tubs].vvod();
            count_tubs++;
            break;
        }
        case 2: {
            station[count_stations].vvod();
            count_stations++;
            break;
        }
        case 3: {
            if (count_tubs == 0) {
                std::cout << "Нет труб." << std::endl;
            }
            else {
                for (int i = 0; i < count_tubs; i++) {
                    tubs[i].vivod();
                    std::cout << "----------------------" << std::endl;
                }
            }
            if (count_stations == 0) {
                std::cout << "Нет компрессорных станций." << std::endl;
            }
            else {
                for (int i = 0; i < count_stations; i++) {
                    station[i].vivod();
                    std::cout << "----------------------" << std::endl;
                }
            }
            break;
        }
        case 4: {
            std::cout << "Введите индекс трубы для редактирования: ";
            int i;
            std::cin >> i;
            if (i < count_tubs && i >= 0) {
                tubs[i].change_status();
            }
            else {
                std::cerr << "Неверный индекс." << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Введите индекс КС для редактирования: ";
            int i;
            std::cin >> i;
            if (i < count_stations && i >= 0) {
                std::cout << "1. Запустить КС" << std::endl;
                std::cout << "2. Остановить КС" << std::endl;
                std::cout << "Выберите действие: ";
                int doit;
                std::cin >> doit;
                if (doit == 1) {
                    station[i].puskCeh();
                }
                else if (doit == 2) {
                    station[i].stopCeh();
                }
                else {
                    std::cerr << "Неверное действие." << std::endl;
                }
            }
            else {
                std::cerr << "Неверный индекс." << std::endl;
            }
            break;
        }
        case 6: {
            savef(tubs, count_tubs, station, count_stations);
            break;
        }
        case 7: {
            loadf(tubs, count_tubs, station, count_stations);
            break;
        }
        default:
            std::cerr << "Неверная опция. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}
