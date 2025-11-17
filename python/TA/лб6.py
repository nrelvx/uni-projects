#Завдання 1
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
