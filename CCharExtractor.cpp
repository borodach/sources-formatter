///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           CCharExtractor.cpp                                  
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


#include "CCharExtractor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCCharExtractor::CCCharExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CCCharExtractor::CCCharExtractor ()
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCCharExtractor::~CCCharExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CCCharExtractor::~CCCharExtractor ()
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCCharExtractor::ExtractToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CCCharExtractor::ExtractToken (const char* szData, 
                                           std::string &strToken, 
                                           eCommentState &eState)
{
    strToken.resize (0);
    if (*szData != '\'')
        return szData;

    const char *szCurrPos = szData + 1;
    for (; (*szCurrPos != '\'') && (*szCurrPos != 0); ++szCurrPos)
    {
        if (*szCurrPos == '\\' )
        {
            ++szCurrPos;
            if (*szCurrPos == 0)
                break;
        }
    }

    if (*szCurrPos == 0)
    {
        strToken = szData;
        return szCurrPos;
    }
    
    strToken.assign (szData, szCurrPos - szData + 1);
    return szCurrPos + 1;
}