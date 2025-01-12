#ifndef PLUGIN_H
#define PLUGIN_H

#include <meta_api.h>
#include <cstring> // Para usar strncpy

int plugin_init(void);
void plugin_exit(void);

void on_new_round(void);

// Declara una estructura de función para capturar eventos
extern META_FUNCTIONS gMetaFunctionTable;

#endif // PLUGIN_H
