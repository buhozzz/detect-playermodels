#include "plugin.h"

// Tabla de funciones Metamod
META_FUNCTIONS gMetaFunctionTable = {
    NULL,           // pfnGetEntityAPI
    NULL,           // pfnGetEntityAPI_Post
    NULL,           // pfnGetEntityAPI2
    NULL,           // pfnGetEntityAPI2_Post
    NULL,           // pfnGetNewDLLFunctions
    NULL,           // pfnGetNewDLLFunctions_Post
    NULL,           // pfnGetEngineFunctions
    NULL,           // pfnGetEngineFunctions_Post
    NULL,           // pfnGameInit
    NULL,           // pfnPlayerPreThink
    NULL,           // pfnPlayerPostThink
    NULL,           // pfnStartFrame
    on_new_round    // pfnNewRound
};

// Función para inicializar el plugin
int plugin_init(void) {
    // Código de inicialización
    return 0; // Indica éxito
}

// Función para limpiar recursos al salir
void plugin_exit(void) {
    // Código de limpieza
}

// Función que se llama al comenzar una nueva ronda
void on_new_round(void) {
    // Imprimir mensaje al inicio de una nueva ronda
    ALERT(at_logged, "¡Una nueva ronda ha comenzado!\n");
}

// Punto de entrada para el plugin
int Meta_Query(const char *ifvers, plugin_info_t **ppluginfo, mutil_funcs_t *pMetaUtilFuncs) {
    // Verificar compatibilidad de versiones y proporcionar información del plugin
    static plugin_info_t Plugin_info = {
        META_INTERFACE_VERSION, // Versión de la interfaz
        "Round Start Message",  // Nombre del plugin
        "1.0",                  // Versión del plugin
        "Estudiante",           // Autor
        "12-01-2025",           // Fecha
        "Imprime un mensaje al comenzar la ronda.", // Descripción
        "http://example.com"    // URL
    };

    // Configurar la información del plugin
    *ppluginfo = &Plugin_info;
    return TRUE; // Indica éxito
}

// Función de inicialización llamada por Metamod
int Meta_Attach(PLUG_LOADTIME now, META_FUNCTIONS *pFunctionTable, meta_globals_t *pMetaGlobals, gamedll_funcs_t *pGamedllFuncs) {
    // Establecer punteros a funciones y estructuras globales
    memcpy(pFunctionTable, &gMetaFunctionTable, sizeof(META_FUNCTIONS));
    return plugin_init();
}

// Función de limpieza llamada por Metamod
int Meta_Detach(PLUG_LOADTIME now, PL_UNLOAD_REASON reason) {
    plugin_exit();
    return TRUE;
}

