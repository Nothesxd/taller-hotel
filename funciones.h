

void buscarPorTamano(int *numHabitacion, char habitaciones[][3][40], double precios[]);
void buscarHotel(int *numHabitacion, char habitaciones[][3][40], double precios[]);
void realizarReserva(int numHabitacion, char habitaciones[10][3][40], char clientes[10][2][40], int reservas[10][4]);
void buscarReservaPorCedula(int *numReserva, char clientes[10][2][40], int reservas[10][4]);
void imprimirReserva(int numReserva, int reservas[10][4], char habitaciones[10][3][40], double precios[10]);
void pagarReserva(int numReserva, int reservas[10][4], char habitaciones[10][3][40], double precios[10]);

