#pragma once

#include "GestionArchivoPagos.h"

class ServicioPago
{
private:
    GestionArchivoPagos _archivoPago;

public:
    ServicioPago();

    bool verificarUltimoPago(int idSocio);
    bool registrarPago(int idSocio, int idMembresia, Fecha periodo);
    void verPago(int idSocio);
    void listarTotalPagos();
    void verPagosPorMes();
    void verPagosPorAnio();

    void verIngresosAnuales();
    void verIngresosMensuales();

    int cantidadDeDiasDelUltimoPago(int idSocio);
    void mostrarListaDePagosPorTipoDePase();
    void verIngresosAnualesPorSocios();


};
