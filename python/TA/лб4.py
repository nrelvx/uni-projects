print("\nЗавдання 1")
a = 38
b = 29
summ = a + b
multiply = a * b
mid = multiply / 2
print("Сума:", summ, "Множення:", multiply, "Середнє:", mid)

print("\nЗавдання 2")
text = input("Введіть рядок:")
upper_txt = text.upper()
print(upper_txt)
lower_txt = text.lower()
print(lower_txt)
reverse_txt = "".join(reversed(text))
print(reverse_txt)

print("\nЗавдання 3")
num = int(input("Введіть число: "))
if num >= 10 and num <= 100 and num % 5 == 0:
    print("Так")
else:
    print("Ні")

print("\nЗавдання 4")
N = int(input("Введіть число: "))
for i in range(0, N + 1):
    if i % 6 == 0:
        print(i)
    else:
        None

print("\nЗавдання 5")
n = int(input("Введіть число: "))
count = 0
for i in range(n - 1, -1, -1):
    print(i)
    square = i * i
    count += square
print("Сума квадратів:", count)
