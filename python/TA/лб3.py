# Список вступників
entrants = ["Іванов", "Бойко", "Шевченко", "Бондаренко"]

# Пуста таблиця
table_size = 7
table = [[] for _ in range(7)]

# Хеш функція
print("\t1. Перегляд")
index1 = hash("Іванов") % 7
index2 = hash("Бойко") % 7
index3 = hash("Шевченко") % 7
index4 = hash("Бондаренко") % 7

print("Іванов: ", index1)
print("Бойко: ", index2)
print("Шевченко:", index3)
print("Бондаренко: ", index4)


print("\t2. Додавання в таблицю")
table[index1].append("Іванов")
table[index2].append("Бойко")
table[index3].append("Шевченко")
table[index4].append("Бондаренко")

# Вивід поточного стану таблиці
for i, bucket in enumerate(table):
    print(f"{i}: {bucket}")

print("\t3. Додавання елементів")
new_index = hash("Ковальчук") % 7
new_index2 = hash("Ткаченко") % 7
table[new_index].append("Ковальчук")
table[new_index2].append("Ткаченко")

for i, bucket in enumerate(table):
    print(f"{i}: {bucket}")

print("\t4. Видалення елементу")
if "Ткаченко" in table[new_index2]:
    table[new_index2].remove("Ткаченко")

for i, bucket in enumerate(table):
    print(f"{i}: {bucket}")
