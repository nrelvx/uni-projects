# Відлік з нуля
# Лінійний пошук
a = [3, 7, 1, 9, 5]
x = 1
print("\n1.Лінійний пошук")
print("Масив:", a, "Шукане:", x)


def linear_search(a, x):
    for i in range(5):
        if a[i] == x:
            return i
    return None


result = linear_search(a, x)
print("idx=", result)
if result is None:
    print("Елементу немає в списку")

# Двійковий пошук
a = [1, 3, 5, 8, 9]  # для двійкового пошуку потрібен відсортований масив
x = 9
print("\n2.Двійковий пошук")
print("Масив:", a, "Шукане:", x)


def binary_search(a, x):
    left = 0
    right = len(a) - 1
    # Поки ліва межа не перевищила праву
    while left <= right:
        mid = (left + right) // 2  # середина

        if a[mid] == x:
            return mid
        # Якщо середній елемент менший - шукаємо праворуч
        elif a[mid] < x:
            left = mid + 1
        # Якщо середній елемент більший - шукаємо ліворуч
        else:
            right = mid - 1

    return None


result = binary_search(a, x)

if result is None:
    print("Елементу немає в списку")
else:
    print("idx=", result)

# Сортування вставками
a = [2, 4, 10, 9, 12, 5]
print("\n3.Сортування вставками")
print("Масив:", a)


def insertion_sort(a):
    # Проходимо по масиву починаючи з другого елемента
    for i in range(1, len(a)):
        key = a[i]  # Зберігаємо поточний елемент
        j = i - 1

        # Зсуваємо елементи, які більші за key, вправо
        while j >= 0 and a[j] > key:
            a[j + 1] = a[j]
            j = j - 1

        # Вставляємо key на правильну позицію
        a[j + 1] = key

    return a


result = insertion_sort(a)
print("Відсортований масив:", result)

# Швидке сортування
a = [3, 6, 9, 1, 5]
print("\n4.Швидке сортування")
print("Масив:", a)


def quick_sort(a):
    if (
        len(a) <= 1
    ):  # Якщо масив містить 0 або 1 елемент, він вважається вже відсортованим і повертається
        return a
    else:
        pivot = a[len(a) // 2]  # Вибираємо середній елемент як опорний
        left = [
            x for x in a if x < pivot
        ]  # Елементи, які знаходяться зліва від опорного
        middle = [
            x for x in a if x == pivot
        ]  # Порівняння середнього елементу з опорним
        right = [
            x for x in a if x > pivot
        ]  # Елементи, які знаходяться правіше від опорного
        return quick_sort(left) + middle + quick_sort(right)


result = quick_sort(a)
print("Відсортований масив:", result)
