///////////////////////////////////////////////////////////////////////////////
//                                                                            
//  File:           CStringExtractor.cpp                                  
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


#include "CStringExtractor.h"


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCStringExtractor::CCStringExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CCStringExtractor::CCStringExtractor ()
{

}
 
///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCStringExtractor::~CCStringExtractor                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

CCStringExtractor::~CCStringExtractor ()
{

}


///////////////////////////////////////////////////////////////////////////////
//                                                                           
//  Function:       CCStringExtractor::ExtractToken                                                        
//                                                                           
//  Description:                                                             
//                                                                           
//                                                                           
///////////////////////////////////////////////////////////////////////////////

const char* CCStringExtractor::ExtractToken (const char* szData, 
                                            std::string &strToken, 
                                            eCommentState &eState)
{
    strToken.resize (0);
    if (*szData != '\"')
        return szData;

    const char *szCurrPos = szData + 1;
    for (; (*szCurrPos != '\"') && (*szCurrPos != 0); ++szCurrPos)
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