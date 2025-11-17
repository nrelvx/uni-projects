# Завдання 1
def matrix_rows_difference(matrix):
    """
    Функція знаходить різницю між сумами елементів парних і непарних рядків матриці.

    Парними вважаються рядки з індексами 1, 3, 5... (для користувача)
    Непарними - рядки з індексами 0, 2, 4... (для користувача)
    """
    try:
        # Перевірка на порожню матрицю
        if not matrix:
            raise ValueError("Матриця порожня")

        # COMPREHENSION: перевірка однаковості довжин рядків
        if len(set(len(row) for row in matrix)) != 1:
            raise ValueError("Рядки матриці мають різну довжину")

        # Обчислення різниці сум за допомогою list comprehension
        even_sum = sum(sum(row) for i, row in enumerate(matrix) if i % 2 == 1)
        odd_sum = sum(sum(row) for i, row in enumerate(matrix) if i % 2 == 0)

        return even_sum - odd_sum

    except Exception as exc:
        print(f"Помилка: {exc}")
        return None


# Тестові приклади
test_matrices = [
    # Нормальна матриця
    [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]],
    # Матриця з дійсними числами
    [[1.5, 2.5], [3.5, 4.5], [5.5, 6.5]],
    # Порожня матриця
    [],
    # Матриця з різними довжинами
    [[1, 2, 3], [4, 5], [6, 7, 8]],
]

for i, matrix in enumerate(test_matrices, 1):
    print(f"\nТест {i}:")
    print("Матриця:", matrix)
    result = matrix_rows_difference(matrix)
    print(f"Результат: {result}")


# Завдання 2
def recursive_sum(lst):
    """
    Обчислює суму елементів списку рекурсивно.

    Параметри:
    lst (list): Вхідний список чисел (int, float)

    Повертає:
    int/float: Сума елементів списку
    None: У разі помилки

    Обмеження:
    - Працює тільки з числами (int, float)
    - Максимальна довжина списку: 1000 елементів
    - Не підходить для дуже великих списків через обмеження рекурсії
    """
    # Базовий випадок: порожній список
    if not lst:
        return 0

    # Рекурсивний випадок: перший елемент + сума решти
    return lst[0] + recursive_sum(lst[1:])


# Демонстрація роботи функції

print("Рекурсивне обчислення суми елементів списку")

# Тестові приклади
test_cases = [
    [1, 2, 3, 4, 5],
    [10, 20, 30],
    [2.5, 3.5, 1.5],
    [],
    [7],
    [-1, 2, -3, 4],
]

for i, test_list in enumerate(test_cases, 1):
    result = recursive_sum(test_list)
    print(f"Тест {i}: {test_list} = {result}")
