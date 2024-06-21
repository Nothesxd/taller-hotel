#include <stdio.h>
#include "funciones.h"
#include <string.h>

void buscarPorTamano(int *numHabitacion, char habitaciones[9][3][40], double precios[9]) {
    int tamano;
    printf("Escoja un tamaño de habitación:\n1.Simple\n2.Doble\n3.Triple\n>>");
    scanf("%d", &tamano);
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][1], tamano == 1? "simple" : tamano == 2? "doble" : "triple") == 0) {
            printf("Habitación %s en el hotel %s, precio: %.2f\n", habitaciones[i][0], habitaciones[i][2], precios[i]);
        }
    }
    printf("Escoja un número de habitación:\n>>");
    scanf("%d", numHabitacion);
}

void buscarHotel(int *numHabitacion, char habitaciones[9][3][40], double precios[9]) {
    char hotel[40];
    printf("Escoja un hotel:\n1.Dan Carlton\n2.Swissotel\n3.Sheraton\n>>");
    scanf("%39s", hotel);
    for (int i = 0; i < 9; i++) {
        if (strcmp(habitaciones[i][2], hotel) == 0) {
            printf("Habitación %s, tipo: %s, precio: %.2f\n", habitaciones[i][0], habitaciones[i][1], precios[i]);
        }
    }
    printf("Escoja un número de habitación:\n>>");
    scanf("%d", numHabitacion);
}

void realizarReserva(int numHabitacion, char habitaciones[9][3][40], char clientes[5][2][40], int reservas[10][4]) {
    char cedula[40];
    printf("Ingrese su cédula:\n>>");
    scanf("%39s", cedula);
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][1], "") == 0) {
            strcpy(clientes[i][0], cedula);
            strcpy(clientes[i][1], habitaciones[numHabitacion - 1][0]);
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (reservas[i][0] == -1) {
            reservas[i][0] = numHabitacion;
            reservas[i][1] = i;
            reservas[i][2] = 0;
            reservas[i][3] = 0;
            break;
        }
    }
    printf("Reserva realizada con éxito\n");
}

void buscarReservaPorCedula(int *numReserva, char clientes[5][2][40], int reservas[10][4]) {
    char cedula[40];
    printf("Ingrese su cédula:\n>>");
    scanf("%39s", cedula);
    for (int i = 0; i < 5; i++) {
        if (strcmp(clientes[i][0], cedula) == 0) {
            for (int j = 0; j < 10; j++) {
                if (reservas[j][1] == i) {
                    *numReserva = j;
                    break;
                }
            }
            break;
        }
    }
}

void imprimirReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9]) {
    printf("Reserva número %d, habitación %s, precio: %.2f\n", numReserva, habitaciones[reservas[numReserva][0] - 1][0], precios[reservas[numReserva][0] - 1]);
}

void pagarReserva(int numReserva, int reservas[10][4], char habitaciones[9][3][40], double precios[9]) {
    printf("Paga la reserva número %d, habitación %s, precio: %.2f\n", numReserva, habitaciones[reservas[numReserva][0] - 1][0], precios[reservas[numReserva][0] - 1]);
    reservas[numReserva][2] = 1;
    printf("Reserva pagada con éxito\n");
}