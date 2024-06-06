#include <iostream>
#include <vector>

const int BASE = 13; 
const int NUMS = 6; 
const int MAX_SUM_OF_NUMS = NUMS * (BASE - 1); 

int main() {
    std::vector<long long> sumCounter(MAX_SUM_OF_NUMS + 1, 0);
    sumCounter[0] = 1;

    // Обновление массива sumCounter для каждой цифры в шестизначном числе
    for (int i = 0; i < NUMS; ++i) {
        std::vector<long long> tempSumCounter(MAX_SUM_OF_NUMS + 1, 0); // Создае вектор для временного хранения количества вариантов получения суммы
        for (int s = 0; s <= MAX_SUM_OF_NUMS; ++s) {
            if (sumCounter[s] > 0) { // Если есть способы достичь сумму s
                for (int digit = 0; digit < BASE; ++digit) {
                    if (s + digit <= MAX_SUM_OF_NUMS) {
                        tempSumCounter[s + digit] += sumCounter[s];
                    }
                }
            }
        }
        sumCounter.swap(tempSumCounter); // Сохраняем значения в sumCounter
    }

    // Количество красивых чисел равно сумме квадратов всех значений в массиве sumCounter
    long long beautifulNums = 0;
    for (auto count : sumCounter) {
        beautifulNums += count * count;
    }

    // Учитываем все возможные значения для 7-й цифры
    beautifulNums *= BASE;

    std::cout << "Number of beautiful numbers: " << beautifulNums << std::endl;

    return 0;
}