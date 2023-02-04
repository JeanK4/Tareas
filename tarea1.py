"""
Jean Karlo Buitrago Orozco
Codigo: 8972318
03 de Febrero de 2023
tarea1
"""

# Punto 1
# Verificar Diagonal

def verificarDiagonales(matriz):
    ans, i, j = True, 0, -1
    while i < len(matriz) and ans:
        if matriz[i][i] == matriz[i][j]:
            i += 1
            j -= 1
        else:
            ans = False
    return ans

# Punto 2
# Es Capicua

def esCapicua(lista):
    posicion1, posicion2, ans = 0, -1, True
    while posicion1 < int(len(lista)//2) and ans:
            if lista[posicion1] == lista[posicion2]:
                posicion1 += 1
                posicion2 -= 1
            else:
                ans = False
    return ans

# Punto 3 a
# Diferencia Listas

def diferenciaListas(lista1,lista2):
    ans = []
    for i in range(len(lista1)):
        if lista1[i] not in lista2:
           ans.append(lista1[i])
        else:
            lista2.remove(lista1[i])
    return ans

# Punto 3 b
# Leer imprimir

def leerImprimirPunto3():
    casos = int(input())
    for i in range(casos):
        lista1 = list(map(int,input().split()))
        lista2 = list(map(int,input().split()))
        lista3 = lista1[1:]
        lista4 = lista2[1:]
        resultado = diferenciaListas(lista3,lista4)
        for j in range(len(resultado)):
            resultado[j] = str(resultado[j])
        ans = ", ".join(resultado)
        print(ans)

# Punto 4
# Mostrar primos

# Función auxiliar que calcula la suma de los digitos de un número
def sumaDigitos(numero):
    ans = 0
    numero1 = str(numero)
    for i in range(len(numero1)):
        ans += int(numero1[i])
    return ans

#Función auxiliar que determina si un número es primo o no (Retornando 0 en caso de no serlo y el número en el caso contrario)
def numeroPrimo(numero):
    ans = 0
    if (numero%2!=0 or numero==2) and (numero%3!=0 or numero==3) and (numero%5!=0 or numero==5) and (numero%7!=0 or numero==7):
        ans = numero
    return ans

#Función auxiliar que organiza los números que la suma de sus digitos es un número primo
def sumaDigitosPrimos(lista):
    ans = []
    for i in range(len(lista)):
        suma = sumaDigitos(lista[i])
        prime = numeroPrimo(suma)
        if prime != 0:
            ans.append(lista[i])
    return ans

##Operación que recibe como parámetro un valor N y muestre los números primos desde 1 hasta N y
#aquellos números que la suma de sus digitos es un número primo y los imprime
def mostrarPrimos(numero):
    ans = []
    for i in range(2,numero+1):
        prime = numeroPrimo(i)
        if prime != 0:
            ans.append(i)
    print("Números primos entre 1 y %d:" % (numero))
    for x in range(len(ans)):
        if x < len(ans)-1:
            print("--> %d," % (ans[x]))
        else:
            print("--> %d" % (ans[x]))
    print()
    print("Números entre 1 y %d con suma de dígitos con valor primo:" % (numero))
    sumadigitos = sumaDigitosPrimos(ans)
    for j in range(len(sumadigitos)):
        sumadigitos[j] = str(sumadigitos[j])
    resultado = ", ".join(sumadigitos)
    print(resultado)

# Punto 5
# Sumar Valores Matriz Dispersa

def sumarValoresMatriz(disp,lista):
    ans = 0
    for i in range(len(lista)):
        if lista[i][0] in disp:
            lista1 = disp[lista[i][0]]
            flag, j = False, 0
            while j < len(lista1) and flag == False:
                if lista[i][1] in lista1[j]:
                    ans += lista1[j][1]
                    flag = True
                j += 1
    return ans