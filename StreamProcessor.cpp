///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           StreamProcessor.cpp                                  
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


#include "StreamProcessor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CStreamProcessor::Process                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

int CStreamProcessor::Process (std::istream &src, 
            std::ostream &dst,
            CLineProcessor &lineProcessor)
{
    char buffer [4096];
    std::string strBuffer;

    while( src.eof () == 0)
    {
        src.getline (buffer, sizeof (buffer));
        lineProcessor.Process (buffer, strBuffer);
        dst << strBuffer.c_str () << std::endl;
    }
    return 1;   
}