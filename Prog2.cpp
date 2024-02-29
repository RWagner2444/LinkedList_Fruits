//---------------------------------------------------------------------
// File: Prog2.cpp
// Project: Maintain and Manipulate a Catalog of Fruit Products.
// Purpose: Run Catalog (with or without Memory Leak detection).
//---------------------------------------------------------------------
#include <iostream>
#include "Catalog.h"
#include "global_config.h"

// Include memory leak detection - configured in global_config.h
#ifdef MEMORY_LEAK_ON
#include "LeakWatcher.h"
#endif

int main()
{
    // ****************************************************************
#ifdef MEMORY_LEAK_ON
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

    try
    {
#endif
        Catalog().Run();
#ifdef MEMORY_LEAK_ON
    }
    catch (...)
    {
        std::cout << "Uncaught Exception" << std::endl;
    }

    _CrtDumpMemoryLeaks();
#endif

    return 0;
}