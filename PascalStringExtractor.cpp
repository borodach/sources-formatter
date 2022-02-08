///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           PascalStringExtractor.cpp                                  
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


#include "PascalStringExtractor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalStringExtractor::CPascalStringExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CPascalStringExtractor::CPascalStringExtractor ()
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalStringExtractor::~CPascalStringExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CPascalStringExtractor::~CPascalStringExtractor ()
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CPascalStringExtractor::ExtractToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CPascalStringExtractor::ExtractToken (const char* szData, 
                                                  std::string &strToken, 
                                                  eCommentState &eState)
{                                        
    strToken.resize (0);
    if (*szData != '\'')
        return szData;

    const char *szCurrPos = szData + 1;

    while (*szCurrPos != 0)
    {
        if (*szCurrPos == '\'')
        {
            if (*(szCurrPos + 1) == '\'') ++szCurrPos;
            else  break;
        }

        ++szCurrPos;
    }

    if (*szCurrPos == 0)
    {
        strToken = szData;
        return szCurrPos;
    }
    
    strToken.assign (szData, szCurrPos - szData + 1);
    return szCurrPos + 1;
}