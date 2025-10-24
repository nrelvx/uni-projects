import math

R1 = float(input("Введіть внутрішній радіус: "))
R2 = float(input("Введіть зовнішній радіус: "))


def ring(R1, R2):
    if R1 < 0 or R2 <= R1:
        print("Задача не має розв'язку при R1<0, R2<=R1")
        return None
    # Обчислення площі кільця
    S = math.pi * (R2**2 - R1**2)
    return S


# Вивід результату
result = ring(R1, R2)
if result is not None:
    print(f"Площа кільця S = {result}")
