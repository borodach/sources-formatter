///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           StreamProcessor.h                                  
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


#if !defined(AFX_STREAMPROCESSOR_H__277D7A4A_6DA2_4FDE_9B92_F0F1BBC2FD59__INCLUDED_)
#define AFX_STREAMPROCESSOR_H__277D7A4A_6DA2_4FDE_9B92_F0F1BBC2FD59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <iostream>
#include "LineProcessor.h"

class CStreamProcessor  
{
public:
    static int Process (std::istream &src, 
        std::ostream &dst,
        CLineProcessor &lineProcessor);
};

#endif // !defined(AFX_STREAMPROCESSOR_H__277D7A4A_6DA2_4FDE_9B92_F0F1BBC2FD59__INCLUDED_)
