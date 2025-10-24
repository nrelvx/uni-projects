import string

print("Завдання 1")
text = "Linked lists vs arrays vs lists."
text = text.lower()
for p in string.punctuation:
    text = text.replace(p, "")

txt = text.split()
print("Список слів із рядка\n", txt)

s = set(txt)
print("Множина унікальних слів\n", s)

sorted_words = tuple(sorted(txt, key=len))
print("Кортеж слів, відсортованих за довжиною\n", sorted_words)

freq_dict = {}
for word in txt:
    freq_dict[word] = freq_dict.get(word, 0) + 1

print("Словник частот появи слів\n", freq_dict)

total_words = len(txt)
unique_words = len(s)
top5 = sorted(freq_dict.items(), key=lambda x: x[1], reverse=True)[:5]

print("\nСтатистика:")
print("Загальна кількість слів:", total_words)
print("Кількість унікальних слів:", unique_words)
print("Топ-5 найчастіших слів:", top5)

print("Завдання 2")
numbers = [1000, 500, 1000, 250, 125]

# 1. Видалити дублікати зі збереженням порядку
unique_numbers = []
for n in numbers:
    if n not in unique_numbers:
        unique_numbers.append(n)

# 2. Побудувати множину парних чисел
even_numbers = {n for n in unique_numbers if n % 2 == 0}

# 3. Побудувати кортеж перших п’яти мінімальних чисел
min_tuple = tuple(sorted(unique_numbers)[:5])

# 4. Створити словник позиція → значення
position_dict = {i: val for i, val in enumerate(numbers)}

# 5. Вивести статистику
count = len(numbers)
duplicates = [n for n in numbers if numbers.count(n) > 1]
duplicates = set(duplicates)
min_value = min(numbers)
max_value = max(numbers)

# Виведення результатів
print("Без дублікатів:", unique_numbers)
print("Множина парних:", even_numbers)
print("Кортеж мінімальних:", min_tuple)
print("Словник позиція → значення:", position_dict)
print("Статистика:")
print("Кількість елементів:", count)
print("Дублікати:", duplicates)
print("Мінімум:", min_value)
print("Максимум:", max_value)

print("Завдання 3")

# Початкові дані — список покупок
purchases = ["хліб", "молоко", "яблуко", "молоко", "сир", "хліб", "молоко"]

# Створюємо словник для підрахунку кількості кожного товару
purchase_count = {}

for item in purchases:
    purchase_count[item] = purchase_count.get(item, 0) + 1

# Виведення результату
print("Список покупок:", purchases)
print("Підрахунок кількості кожного товару:", purchase_count)
