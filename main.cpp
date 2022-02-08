///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           main.cpp                                  
//
//  Facility:                                                                
//                                                                           
//                                                                           
//  Abstract:                                                                
//                                                                           
//  Environment:    VC 6.0                                                   
//                                                                           
//  Author:         Зайцев С. А.                                                          
//                                                                           
//  Creation Date:  29/03/2003                                  
//                                                                           
///////////////////////////////////////////////////////////////////////////////


#include <fstream>
#include "StreamProcessor.h"
#include "PascalGramma.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       main                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

void main (int argc, char *argv [])
{
    if (argc < 2)
    {
        std::cout << "Программе нужно не менее 1 аргумента - имени обрабаываемого файла" << std::endl;
        return;
    }

    std::ifstream src (argv [1]);
    if ( ! src.is_open ())
    {
        std::cout << "Не могу открыть исходный файл " << argv [1] << std::endl;
        return;
    }

    std::ofstream dst;
    if (argc > 2)
    {
        dst.open (argv [2], std::ios::out);
        if ( ! dst.is_open ())
        {
            std::cout << "Не могу открыть целевой файл " << argv [2] << std::endl;
            std::cout << "Результат будет выведен на консоль." << std::endl;
        }

    }

    int bUseConsole = !dst.is_open ();
 
    CPascalGramma pascalGramma;
    CLineProcessor lineProcessor (&pascalGramma);
    if ( ! bUseConsole)
        CStreamProcessor::Process (src, dst, lineProcessor);
    else
        CStreamProcessor::Process (src, std::cout, lineProcessor);
}